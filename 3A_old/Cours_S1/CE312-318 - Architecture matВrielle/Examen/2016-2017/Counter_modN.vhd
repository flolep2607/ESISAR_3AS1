library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.numeric_std.all;

entity Counter_modN is
generic(N, SIZE : integer);
port(	clk		: 	in		std_logic;
		en		:	in		std_logic;
		rst		:	in		std_logic;
		count	:	out		std_logic_vector(SIZE-1 downto 0);
		tresh	:	out		std_logic);
end Counter_modN;

architecture Behavioral of Counter_modN is

signal count_temp : unsigned(SIZE-1 downto 0);

begin

process(clk)
begin
if clk'event and clk='1' then
	if rst = '1' then
		count_temp <= (others=>'0');
	elsif en='1' then
		if count_temp = N-1 then
			count_temp <= (others=>'0');
		else
			count_temp <= unsigned(count_temp) + 1;
		end if;
	end if;
end if;
end process;

count <= std_logic_vector(count_temp);

tresh <= '1' when count_temp = N-1 else '0';

end Behavioral;

