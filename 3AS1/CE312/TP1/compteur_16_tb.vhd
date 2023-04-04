-- Testbench automatically generated online
-- at https://vhdl.lapinoo.net
-- Generation date : 8.10.2022 11:23:53 UTC

library ieee;
use ieee.std_logic_1164.all;

entity compteur_16_tb is
end compteur_16_tb;

architecture tb of compteur_16_tb is

    component compteur_16
        port (clk       : in std_logic;
              rst       : in std_logic;
              enable    : in std_logic;
              deb       : out std_logic;
              out_count : out std_logic_vector (3 downto 0));
    end component;

    signal clk       : std_logic;
    signal rst       : std_logic;
    signal enable    : std_logic;
    signal deb       : std_logic;
    signal out_count : std_logic_vector (3 downto 0);

    constant TbPeriod : time := 10 ns; -- EDIT Put right period here
    signal TbClock : std_logic := '0';
    signal TbSimEnded : std_logic := '0';

begin

    dut : compteur_16
    port map (clk       => clk,
              rst       => rst,
              enable    => enable,
              deb       => deb,
              out_count => out_count);

    -- Clock generation
    TbClock <= not TbClock after TbPeriod/2 when TbSimEnded /= '1' else '0';

    -- EDIT: Check that clk is really your main clock signal
    clk <= TbClock;

    stimuli : process
    begin
        -- EDIT Adapt initialization as needed
        enable <= '0';

        -- Reset generation
        -- EDIT: Check that rst is really your reset signal
        rst <= '1';
        wait for 100 ns;
        rst <= '0';
        wait for 100 ns;
        enable <= '1';

        -- EDIT Add stimuli here
        wait for 100 * TbPeriod/2;
        rst <= '1';
        wait for 100 ns;
        rst <= '0';
        wait for 100 * TbPeriod/2;

        -- Stop the clock and hence terminate the simulation
        TbSimEnded <= '1';
        wait;
    end process;

end tb;

-- Configuration block below is required by some simulators. Usually no need to edit.

configuration cfg_compteur_16_tb of compteur_16_tb is
    for tb
    end for;
end cfg_compteur_16_tb;