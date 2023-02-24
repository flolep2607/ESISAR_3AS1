library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity tb_display is
end tb_display;

architecture tb of tb_display is
    signal clk_tb, dp_tb : STD_LOGIC;
    signal seg_tb : std_logic_vector(6 downto 0);
    signal an_tb : std_logic_vector(3 downto 0);
    
    component display
    port ( clk      : in std_logic;
           seg      : out std_logic_vector(6 downto 0);
           dp       : out std_logic;
           an       : out std_logic_vector(3 downto 0)
    );
    end component;
begin
    ecran : display port map (clk=>clk_tb, seg=>seg_tb, dp=>dp_tb, an=>an_tb);
    clock_10mhz_generation : process -- simulation of the clock signal
    begin
        clk_tb <= '0';
        wait for 100 ns;
        clk_tb <= '1';
        wait for 100 ns;
    end process;

end architecture;
