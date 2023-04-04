library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity tb_compteur_16 is
end tb_compteur_16;

architecture tb of tb_compteur_16 is
  component compteur_16
      port (
        clk : in STD_LOGIC;
        rst : in STD_LOGIC;
        enable : in STD_LOGIC;
        deb  : out STD_LOGIC; -- compteur de débordement 
        out_count : out STD_LOGIC_VECTOR (3 downto 0) -- le compteur temporaire
      );
  end component;
  
  signal clk_tb, rst_tb, enable_tb, deb_tb : STD_LOGIC;
  signal out_count_tb : STD_LOGIC_VECTOR (3 downto 0);
  
  begin
    compteur: compteur_16 port map (clk=>clk_tb, rst=>rst_tb, enable=>enable_tb, deb=>deb_tb, out_count=>out_count_tb);
    
    clock_10mhz_generation : process -- simulation du signal d'horloge
    begin
        clk_tb <= '0';
        wait for 50 ns;
        clk_tb <= '1';
        wait for 50 ns;
    end process;
    
    procreset: process -- simulation du reset
    begin
      rst_tb <= '1';
      wait for 100 ns; -- on maintient le rst_tb pendant les 100 premières secondes
      rst_tb <= '0';
      wait for 1000ns;
      rst_tb <= '1';
      wait for 100 ns; -- on maintient le rst_tb pendant les 100 premières secondes
      rst_tb <= '0';
      wait; -- puis on l'enlève définitivement
    end process;
    
    procenable: process -- simulation de l'enable
    begin
      enable_tb <= '1';
      wait for 325 ns;
      enable_tb <= '0';
      wait for 75 ns;
      enable_tb <= '1';
      wait;
    end process;

end architecture;