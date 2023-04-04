library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.numeric_std.all;

entity compteur_N is
     Generic(
         C_NB_BIT_COUNTER :integer;
         C_MODULO         :integer
     );
     Port(
         clk:       in STD_LOGIC;
         rst:       in STD_LOGIC;
         enable:    in STD_LOGIC;
         max:       out STD_LOGIC:='0';
         overflow:   out STD_LOGIC:='0';
         out_count: out STD_LOGIC_VECTOR(C_NB_BIT_COUNTER -1 downto 0)  
     );
end compteur_N;

architecture compteur of compteur_N is
	signal compteur_interne : STD_LOGIC_VECTOR(C_NB_BIT_COUNTER -1 downto 0) := (others => '0');
begin
	compteur : process (clk)
	begin
		if rising_edge(clk) then
			if rst = '1' then
				compteur_interne <= (compteur_interne'range =>'0');
			elsif enable = '1' then
				if compteur_interne=(compteur_interne'range =>'1') then
					 compteur_interne <=(compteur_interne'range =>'0');
					 overflow <= '1';
			    elsif unsigned(compteur_interne) >= C_MODULO then
			         compteur_interne <=(compteur_interne'range =>'0');
			         overflow <= '1';
				else
				     overflow <= '0';
					 compteur_interne <= STD_LOGIC_VECTOR(unsigned(compteur_interne) + 1);
				end if ;
			end if ;
		end if ;
	end process;
	max <= '1' when unsigned(compteur_interne) = C_MODULO else '0';
	out_count <= std_logic_vector(compteur_interne);
end compteur;
