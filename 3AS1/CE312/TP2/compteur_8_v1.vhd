library ieee;
	use ieee.std_logic_1164.all;
	use ieee.numeric_std.all;

entity compteur_8_v1 is
	port(
		clk 		: in	std_logic;
		rst 		: in	std_logic;
		enable 		: in	std_logic;
		out_count	: out	std_logic_vector (2 downto 0)
	);
end compteur_8_v1;

architecture behavioral of compteur_8_v1 is
	signal compteur_interne : unsigned(2 downto 0) := (others => '0');
begin
	compteur : process (clk)
	begin
		if rising_edge(clk) then
			if rst = '1' then
				compteur_interne <= "000";
			elsif enable = '1' then
				if compteur_interne = "111" then
					compteur_interne <= "000";
				else
					compteur_interne <= compteur_interne + 1;
				end if ;
			end if ;
		end if ;
	end process;

	out_count <= std_logic_vector(compteur_interne);

end behavioral;