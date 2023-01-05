library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity chrono is
Generic(
         DIV : integer := 50000000
     );
    Port(
         clk:       in STD_LOGIC;
         rst:       in STD_LOGIC;
         enable:    in STD_LOGIC;
         out1_count: out STD_LOGIC_VECTOR(6 -1 downto 0);
         out2_count: out STD_LOGIC_VECTOR(6 -1 downto 0)  
     );
end chrono;

architecture chronometer of chrono is
    signal overflow1 : STD_LOGIC;
    signal overflow2 : STD_LOGIC;
begin
     compteur1 : entity work.compteur_N
	   generic map(
            C_NB_BIT_COUNTER=>27,
            C_MODULO=>DIV
        )
		port map(
			clk			=> clk,
			rst			=> rst,
			enable		=> enable,
			overflow    => overflow1
		);
	compteur2 : entity work.compteur_N
	   generic map(
            C_NB_BIT_COUNTER=>6,
            C_MODULO=>59
        )
		port map(
			clk			=> overflow1,
			rst			=> rst,
			enable		=> enable,
			overflow    => overflow2,
			out_count   => out1_count
		);
	compteur3 : entity work.compteur_N
	   generic map(
            C_NB_BIT_COUNTER=>6,
            C_MODULO=>59
        )
		port map(
			clk			=> overflow2,
			rst			=> rst,
			enable		=> enable,
			out_count   => out2_count
		);
end chronometer;
