#Config
set_property CONFIG_VOLTAGE 3.3 [current_design]
set_property CFGBVS VCCO [current_design]

# Clock signal
set_property PACKAGE_PIN W5 [get_ports clk]
set_property IOSTANDARD LVCMOS33 [get_ports clk]
create_clock -period 10.000 -name sys_clk_pin -waveform {0.000 5.000} -add [get_ports clk]

#7 segment display choice
set_property PACKAGE_PIN U2 [get_ports {an[0]}]					
	set_property IOSTANDARD LVCMOS33 [get_ports {an[0]}]
set_property PACKAGE_PIN U4 [get_ports {an[1]}]					
	set_property IOSTANDARD LVCMOS33 [get_ports {an[1]}]
set_property PACKAGE_PIN V4 [get_ports {an[2]}]					
	set_property IOSTANDARD LVCMOS33 [get_ports {an[2]}]
set_property PACKAGE_PIN W4 [get_ports {an[3]}]					
	set_property IOSTANDARD LVCMOS33 [get_ports {an[3]}]

#7 segment display
set_property PACKAGE_PIN W7 [get_ports {seven_seg_out[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports {seven_seg_out[0]}]
set_property PACKAGE_PIN W6 [get_ports {seven_seg_out[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {seven_seg_out[1]}]
set_property PACKAGE_PIN U8 [get_ports {seven_seg_out[2]}]
set_property IOSTANDARD LVCMOS33 [get_ports {seven_seg_out[2]}]
set_property PACKAGE_PIN V8 [get_ports {seven_seg_out[3]}]
set_property IOSTANDARD LVCMOS33 [get_ports {seven_seg_out[3]}]
set_property PACKAGE_PIN U5 [get_ports {seven_seg_out[4]}]
set_property IOSTANDARD LVCMOS33 [get_ports {seven_seg_out[4]}]
set_property PACKAGE_PIN V5 [get_ports {seven_seg_out[5]}]
set_property IOSTANDARD LVCMOS33 [get_ports {seven_seg_out[5]}]
set_property PACKAGE_PIN U7 [get_ports {seven_seg_out[6]}]
set_property IOSTANDARD LVCMOS33 [get_ports {seven_seg_out[6]}]

#Buttons
set_property PACKAGE_PIN T17 [get_ports rst]
set_property IOSTANDARD LVCMOS33 [get_ports rst]
set_property PACKAGE_PIN U17 [get_ports enable]
set_property IOSTANDARD LVCMOS33 [get_ports enable]