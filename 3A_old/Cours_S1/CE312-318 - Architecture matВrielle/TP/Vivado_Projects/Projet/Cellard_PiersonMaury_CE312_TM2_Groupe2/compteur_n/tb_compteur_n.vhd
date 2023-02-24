library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity tb_compteur_N is
end tb_compteur_N;

architecture tb of tb_compteur_N is

  constant C_MODULO : integer := 10;
  constant C_NB_BIT_COUNTER : integer := 4;
  
  component compteur_N
      generic (
        C_NB_BIT_COUNTER : integer;
        C_MODULO : integer
      );
      port (
        clk : in STD_LOGIC;
        rst : in STD_LOGIC;
        enable : in STD_LOGIC;
        max  : out STD_LOGIC; -- bit overflow
        out_count : out STD_LOGIC_VECTOR (C_NB_BIT_COUNTER-1 downto 0) -- le compteur temporaire
      );
  end component;
  
  signal clk_tb, rst_tb, enable_tb, max_tb : STD_LOGIC;
  signal out_count_tb : STD_LOGIC_VECTOR (C_NB_BIT_COUNTER-1 downto 0);
  
  begin
    compteur: compteur_N generic map (C_NB_BIT_COUNTER=>C_NB_BIT_COUNTER, C_MODULO=>C_MODULO) port map (clk=>clk_tb, rst=>rst_tb, enable=>enable_tb, max=>max_tb, out_count=>out_count_tb);
    
    clock_10mhz_generation : process -- simulation of the clock signal
    begin
        clk_tb <= '0';
        wait for 50 ns;
        clk_tb <= '1';
        wait for 50 ns;
    end process;
    
    procreset: process -- simulation of the reset signal
    begin
      rst_tb <= '1';
      wait for 100 ns; -- we maintain the rst_tb signal on 100 ns
      rst_tb <= '0';
      wait for 800 ns;
      rst_tb <= '1';
      wait for 100 ns; -- we maintain the rst_tb signal on 100 ns
      rst_tb <= '0';
      wait for 300 ns;
      rst_tb <= '1';
      wait for 200 ns;
      rst_tb <= '0';
      wait; -- puis on l'enl�ve d�finitivement
    end process;
    
    procenable: process -- simulation of the enable signal
    begin
      enable_tb <= '1';
      wait for 325 ns;
      enable_tb <= '0';
      wait for 75 ns;
      enable_tb <= '1';
      wait for 800 ns;
      enable_tb <= '0';  
      wait for 200 ns;
      enable_tb <= '1';      
      wait;
    end process;

end architecture;