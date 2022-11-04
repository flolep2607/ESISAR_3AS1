#! /usr/bin/env python3
import subprocess
import pytest
import glob
import sys
import os
import re

BASE_DIR = os.environ.get("BASE_DIR", ".")
EMUL_MIPS = os.path.join(BASE_DIR, "emul-mips")
TEST_DIR = os.environ.get("TEST_FILES", os.path.join(BASE_DIR, "tests/*.s"))

if "TEST_FILES" in os.environ:
    ALL_FILES = glob.glob(os.environ["TEST_FILES"], recursive=True)
else:
    ALL_FILES = glob.glob(os.path.join(BASE_DIR, "tests/*.s"))

# Split into non-empty lines, remove spaces, translate to upper case
def normalize_and_split_lines(s):
    s = [re.sub(r"[ \t\n]+", "", line.upper()) for line in s.split("\n")]
    return [line for line in s if line]

# Parse string into a final state dictionary
def parse_final_state(s):
    s = normalize_and_split_lines(s)
    state = dict()
    for line in s:
        reg, value = line.split(":", 1)
        assert re.fullmatch(r"HI|LO|\$(?:[0-2][0-9]|30|31)", reg) is not None
        state[reg] = int(value, 0)
    return state

def assert_equal_hex(ref, out):
    ref = normalize_and_split_lines(ref)
    out = normalize_and_split_lines(out)

    if len(out) != len(ref):
        pytest.fail("Output should contain {} instructions, but has {}".format(
            len(ref), len(out)))
    for i in range(len(ref)):
        if out[i] != ref[i]:
            pytest.fail("Instruction #{} should be {}, but is {}".format(
                i+1, ref[i], out[i]))

def assert_equal_regs(ref, out):
    ref = parse_final_state(ref)
    out = parse_final_state(out)

    for r in range(32):
        r = "$%02d" % r
        if ref.get(r, 0) != out.get(r, 0):
            pytest.fail("Register {} should be {}, but it is {}".format(
                r, ref.get(r, 0), out.get(r, 0)))
    for r in ["LO", "HI"]:
        if ref.get(r, 0) != out.get(r, 0):
            pytest.fail("Register {} should be {}, but it is {}".format(
                r, ref.get(r, 0), out.get(r, 0)))

class TestMIPS:
    def get_expect(self, file):
        exp_hex, exp_state = "", ""
        inside = None

        with open(file, encoding="utf-8") as fp:
            for line in fp.readlines():
                # Ignore non-comments
                if not re.match(r"\s*#", line):
                    continue
                # Cleanup comment start and whitespaces
                line = re.sub(r"\s*#\s*", "", line)
                line = re.sub(r"\s*$", "", line)

                if line == "END":
                    inside = None
                elif line == "EXPECTED_ASSEMBLY":
                    inside = "hex"
                elif line == "EXPECTED_FINAL_STATE":
                    inside = "state"
                elif inside == "hex":
                    exp_hex += "\n" + line
                elif inside == "state":
                    exp_state += "\n" + line

        # Make them None if they are empty strings
        return (exp_hex or None, exp_state or None)

    def do_test_expect(self, filename, kind):
        prog, _ = os.path.splitext(filename)
        prog_hex = prog + ".hex"
        prog_state = prog + ".state"

        exp_hex, exp_state = self.get_expect(filename)

        # Run the command, ignoring I/Os (wd only use output files)
        subprocess.run([EMUL_MIPS, prog + ".s", prog_hex, prog_state],
            timeout=10, stderr=subprocess.STDOUT, check=True)

        if kind == "EXPECTED_ASSEMBLY":
            if exp_hex is None:
                pytest.skip("no EXPECTED_ASSEMBLY")
            with open(prog_hex, "r") as fp:
                assert_equal_hex(exp_hex, fp.read())
        else:
            if exp_state is None:
                pytest.skip("no EXPECTED_FINAL_STATE")
            with open(prog_state, "r") as fp:
                state = fp.read()
                if state == "":
                    pytest.skip("emulation not implemented yet")
                assert_equal_regs(exp_state, state)

    @pytest.mark.parametrize("filename", ALL_FILES)
    def test_hex(self, filename):
        self.do_test_expect(filename, "EXPECTED_ASSEMBLY")

    @pytest.mark.parametrize("filename", ALL_FILES)
    def test_state(self, filename):
        self.do_test_expect(filename, "EXPECTED_FINAL_STATE")

pytest.main(sys.argv)
