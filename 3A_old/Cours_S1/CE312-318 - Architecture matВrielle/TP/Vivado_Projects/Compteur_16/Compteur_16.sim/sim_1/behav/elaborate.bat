@echo off
set xv_path=D:\\Logiciel\\Xilinx\\Vivado\\2014.3.1\\bin
call %xv_path%/xelab  -wto f8ef3b450c6145ad8c258a4b48f035ea -m64 --debug typical --relax -L xil_defaultlib -L secureip --snapshot tb_compteur_16_behav xil_defaultlib.tb_compteur_16 -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
