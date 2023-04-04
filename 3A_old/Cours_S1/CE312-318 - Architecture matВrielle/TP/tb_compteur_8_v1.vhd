----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 25.05.2021 12:42:29
-- Design Name: 
-- Module Name: tb_compteur_8 - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.numeric_std.all;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity tb_compteur_8_v1 is
end tb_compteur_8_v1;

architecture Behavioral of tb_compteur_8_v1 is

signal rst_tb, enable_tb: std_logic;
signal clk_tb : std_logic:='0';
signal out_count_tb : std_logic_vector(2 downto 0);
signal an : std_logic_vector (3 downto 0);
signal seven_seg_out: out std_logic_vector (6 downto 0);

begin
	inst : entity work.compteur_8
		port map(
			clk => clk_tb,
			rst => rst_tb,
			enable => en_tb,
			out_count => out_count_tb
		);
	
clk_tb <= not clk_tb after 5 ns; -- 100MHz


	process
    begin
        rst_tb<='0';
        en_tb <='0';
        wait for 10ns;
        en_tb <='1';
        wait for 180ns;
        rst_tb<='1';
        wait for 10ns;
        rst_tb<='0';
        en_tb <='0';
    end process;

end Behavioral;
