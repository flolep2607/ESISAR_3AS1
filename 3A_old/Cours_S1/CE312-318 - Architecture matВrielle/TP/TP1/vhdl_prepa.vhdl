librairy IEEE;
use IEEE.numeric_std.all;
use IEEE.std_logic_1164.all;

entity compteur_16 is
	Port ( clk : in STD_LOGIC;
	rst : in STD_LOGIC;
	enable : in STD_LOGIC;
	deb : out STD_LOGIC;
	out_count : out STD_LOGIC_VECTOR (3 downto 0)
 );
end compteur_16;

architecture struct of compteur_16 is
	signal q_count : STD_LOGIC_VECTOR(3 downto 0);
	signal qdeb : STD_LOGIC;
begin
	
	on_clock : process(clk)
	begin
		if clk'event and clk = '1' then
			if 'enable' = 1 then
				q_count = std_logic_vector( unsigned(q_count) + 1 );
			end if;
			if 'rst' = 1 or 'qdeb' = 1 then
				q_count = "0000"
			end if;
		end if;
	end process on_clock;

	qdeb <= ( q_count(0) and q_count(1) and q_count(2) and q_count(3) ) ;
	deb <= qdeb ;
	out_count <= q_count ;

end struct;