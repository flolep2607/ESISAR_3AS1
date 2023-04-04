----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 28.05.2021 14:24:37
-- Design Name: 
-- Module Name: compteur_8 - Behavioral
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

entity compteur_8 is
    Port ( clk : in STD_LOGIC;
           rst : in STD_LOGIC;
           enable : in STD_LOGIC;
           an:out std_logic_vector (3 downto 0);
           seven_seg_out: out std_logic_vector (6 downto 0);
           out_count : out STD_LOGIC_VECTOR (2 downto 0));
end compteur_8;

architecture Behavioral of compteur_8 is
signal clk_1hz : std_logic ;
signal max : integer range 0 to 100000000 ;  -- 100mhz 
signal compteur_interne : unsigned(2 downto 0);
begin



	inst : entity work.compteur_8
		port map(
			clk => clk_tb,
			rst => rst_tb,
			enable => en_tb,
			out_count => out_count_tb
		);
		
an<="0111"; 

----process clk
clk_1hz_process : process( clk,rst )
    begin                 
      if(rising_edge(clk)) then 
          if (max < 100000000) then 
              max <= max + 1 ;
              clk_1hz <= '0';
          else
              max <= 0;
              clk_1hz <= '1';
          end if;
      end if;
end process clk_1hz_process;  


process(compteur_interne)
begin
case compteur_interne is
when "000" => seven_seg_out <= "1000000";
when "001" => seven_seg_out <= "1111001";
when "010" => seven_seg_out <= "0100100";
when "011" => seven_seg_out <= "0110000";
when "100" => seven_seg_out <= "0011001";
when "101" => seven_seg_out <= "0010010";
when "110" => seven_seg_out <= "0000010";
when "111" => seven_seg_out <= "1111000";
end case;
end process;

out_count <= std_logic_vector(compteur_interne);




end Behavioral;
