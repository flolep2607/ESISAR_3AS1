@echo off
set xv_path=D:\\Logiciel\\Xilinx\\Vivado\\2014.3.1\\bin
call %xv_path%/xelab  -wto d04b6fb335964a2e94487ce739812bda -m64 --debug typical --relax -L xil_defaultlib -L secureip --snapshot tb_compteur_N_behav xil_defaultlib.tb_compteur_N -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
