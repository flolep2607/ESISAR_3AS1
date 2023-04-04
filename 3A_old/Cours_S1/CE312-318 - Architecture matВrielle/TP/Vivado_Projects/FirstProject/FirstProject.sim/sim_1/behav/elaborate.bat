@echo off
set xv_path=D:\\Logiciel\\Xilinx\\Vivado\\2014.3.1\\bin
call %xv_path%/xelab  -wto a44c805b7ab141ad8c51e80fe0b2220a -m64 --debug typical --relax -L xil_defaultlib -L secureip --snapshot and_gate_registered_tb_behav xil_defaultlib.and_gate_registered_tb -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
