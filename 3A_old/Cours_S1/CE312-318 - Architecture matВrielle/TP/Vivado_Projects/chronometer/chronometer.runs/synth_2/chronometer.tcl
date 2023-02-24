# 
# Synthesis run script generated by Vivado
# 

set_param gui.test TreeTableDev
debug::add_scope template.lib 1
set_msg_config -id {HDL 9-1061} -limit 100000
set_msg_config -id {HDL 9-1654} -limit 100000

create_project -in_memory -part xc7a35tcpg236-1
set_param project.compositeFile.enableAutoGeneration 0
set_param synth.vivado.isSynthRun true
set_property webtalk.parent_dir C:/Users/remi_cellard/Vivado_Projects/chronometer/chronometer.cache/wt [current_project]
set_property parent.project_path C:/Users/remi_cellard/Vivado_Projects/chronometer/chronometer.xpr [current_project]
set_property default_lib xil_defaultlib [current_project]
set_property target_language VHDL [current_project]
read_vhdl -library xil_defaultlib {
  C:/Users/remi_cellard/Vivado_Projects/chronometer/compteur_n.vhd
  C:/Users/remi_cellard/Vivado_Projects/chronometer/chronometer.vhd
}
catch { write_hwdef -file chronometer.hwdef }
synth_design -top chronometer -part xc7a35tcpg236-1
write_checkpoint chronometer.dcp
catch { report_utilization -file chronometer_utilization_synth.rpt -pb chronometer_utilization_synth.pb }
