library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity tb_chronometer is
end tb_chronometer;

architecture tb of tb_chronometer is
  component chronometer
      port (
        clk : in STD_LOGIC; -- clock signal
        rst : in STD_LOGIC; -- reset signal
        start : in STD_LOGIC; -- enable signal
        out_secondes  : out STD_LOGIC_VECTOR (7 downto 0); -- counter signal
        out_minutes : out STD_LOGIC_VECTOR (7 downto 0) -- counter signal
      );
  end component;
  
  signal clk_tb, rst_tb, start_tb : STD_LOGIC := '0';
  signal out_secondes_tb, out_minutes_tb : STD_LOGIC_VECTOR (7 downto 0);
  
  begin
    chronometer_tb : chronometer port map (clk=>clk_tb, rst=>rst_tb, start=>start_tb, out_secondes=>out_secondes_tb, out_minutes=>out_minutes_tb);
    clock_50mhz_generation : process -- simulation of the clock signal
    begin
        clk_tb <= '0';
        wait for 10 ns;
        clk_tb <= '1';
        wait for 10 ns;
    end process;
    
    procreset: process -- simulation of the reset signal
    begin
      rst_tb <= '1';
      wait for 1s; -- we maintain the rst_tb signal on 100 ns
      rst_tb <= '0';
      wait for 8s;
      rst_tb <= '1';
      wait for 1s; -- we maintain the rst_tb signal on 100 ns
      rst_tb <= '0';
      wait for 3s;
      rst_tb <= '1';
      wait for 2s;
      rst_tb <= '0';
      wait; -- puis on l'enl?ve d?finitivement
    end process;
    
    procenable: process -- simulation of the enable signal
    begin
      start_tb <= '1';
      wait for 3250 ms;
      start_tb <= '0';
      wait for 7500 ms;
      start_tb <= '1';
      wait for 8000 ms;
      start_tb <= '0';  
      wait for 2000 ms;
      start_tb <= '1';      
      wait;
    end process;
    
end architecture;