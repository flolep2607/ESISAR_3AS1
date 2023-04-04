@echo off
set xv_path=D:\\Logiciel\\Xilinx\\Vivado\\2014.3.1\\bin
call %xv_path%/xsim tb_compteur_16_behav -key {Behavioral:sim_1:Functional:tb_compteur_16} -tclbatch tb_compteur_16.tcl -log simulate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
