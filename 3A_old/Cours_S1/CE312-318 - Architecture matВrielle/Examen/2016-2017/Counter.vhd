library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.numeric_std.all;

entity Counter is
port(	clk		: 	in		std_logic;
		en		:	in		std_logic;
		rst		:	in		std_logic;
		count	:	out		std_logic_vector(3 downto 0);
		tresh	:	out		std_logic);
end Counter_modN;

architecture Behavioral of Counter is

signal count_temp : unsigned(3 downto 0);

begin

process(clk)
begin
if clk'event and clk='1' then
	if rst = '1' then
		count_temp <= (others=>'0');
	elsif en='1' then
		if count_temp = 4 then
			count_temp <= (others=>'0');
		else
			count_temp <= unsigned(count_temp) + 1;
		end if;
	end if;
end if;
end process;

count <= std_logic_vector(count_temp);

tresh <= '1' when count_temp = 4 else '0';

end Behavioral;

