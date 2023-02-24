@echo off
set xv_path=D:\\Logiciel\\Xilinx\\Vivado\\2014.3.1\\bin
call %xv_path%/xelab  -wto 7523f1e05a2840af9c00dc4819cea201 -m64 --debug typical --relax -L xil_defaultlib -L secureip --snapshot tb_chronometer_behav xil_defaultlib.tb_chronometer -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
