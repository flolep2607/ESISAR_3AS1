library ieee;
	use ieee.std_logic_1164.all;
	use ieee.numeric_std.all;

entity compteur_8_v2 is
	port(
		clk 			: in std_logic;
		rst 			: in std_logic;
		enable 			: in std_logic;
		an				: out std_logic_vector(3 downto 0);
		seven_seg_out	: out std_logic_vector(6 downto 0)
	);
end entity;

architecture behavioral of compteur_8_v2 is
	signal clk_1hz		: std_logic	:= '0';
	signal out_count	: std_logic_vector(2 downto 0) := (others => '0');
	signal max			: integer range 0 to 100000000 := 0;
begin
	-- Création horloge 1Hz
	CLK_1HZ_PROC : process(clk)
		begin
		  if(rising_edge(clk)) then 
			  if (max < 100000000-1) then 
				  max <= max + 1 ;
				  clk_1hz <= '0';
			  else
				  max <= 0;
				  clk_1hz <= '1';
			  end if;
		  end if;
	end process;

	-- Instanciation compteur
	inst : entity work.compteur_8_v1
		port map(
			clk			=> clk_1hz,
			rst			=> rst,
			enable		=> enable,
			out_count	=> out_count
		);

	-- Gestion afficheur 7 segments
	seven_seg_out <=	"1000000" when out_count = "000" else
						"1111001" when out_count = "001" else
						"0100100" when out_count = "010" else
						"0110000" when out_count = "011" else
						"0011001" when out_count = "100" else
						"0010010" when out_count = "101" else
						"0000010" when out_count = "110" else
						"1111000";
	an <= "1110";
end behavioral;
