#!/bin/bash
riscv64-unknown-elf-gcc -march=rv64g libprint.s $1 -o prog
riscv64-unknown-elf-nm prog | grep loop
riscv64-unknown-elf-nm prog | grep continue
# spike -d pk prog
spike pk prog