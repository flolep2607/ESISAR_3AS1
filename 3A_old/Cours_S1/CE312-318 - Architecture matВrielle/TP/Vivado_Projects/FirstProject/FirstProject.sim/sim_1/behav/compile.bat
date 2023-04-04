@echo off
set xv_path=D:\\Logiciel\\Xilinx\\Vivado\\2014.3.1\\bin
echo "xvhdl -m64 -prj and_gate_registered_tb_vhdl.prj"
call %xv_path%/xvhdl  -m64 -prj and_gate_registered_tb_vhdl.prj -log compile.log
if "%errorlevel%"=="1" goto END
if "%errorlevel%"=="0" goto SUCCESS
:END
exit 1
:SUCCESS
exit 0
