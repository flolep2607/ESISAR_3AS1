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
           out_count : out STD_LOGIC_VECTOR (2 downto 0));
end compteur_8;

architecture Behavioral of compteur_8 is
signal en_1Hz : std_logic ;
signal max : integer range 0 to 100000000 ;  -- 100mhz 
signal compteur_interne : unsigned(2 downto 0);
begin

	compteur : process (clk)
	begin
		
		if rising_edge(clk) then
			if rst = '1' then
				compteur_interne <= "000";
			elsif en_1Hz = '1' then
				if compteur_interne = "111" then 
					compteur_interne <= "000";
				else
					compteur_interne <= compteur_interne + 1;
				end if ;
			end if ;
		end if ;
					
	end process; -- compteur

out_count <= std_logic_vector(compteur_interne);

end Behavioral;
