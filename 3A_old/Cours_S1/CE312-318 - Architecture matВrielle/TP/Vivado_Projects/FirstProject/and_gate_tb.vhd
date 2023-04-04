library ieee;
    use ieee.std_logic_1164.all;
    use ieee.numeric_std.all;

entity and_gate_tb is 
end entity;

architecture behavorial of and_gate_tb is
    signal e1_tb : std_logic;
    signal e2_tb : std_logic;
    signal result_tb : std_logic;
begin
    i_uut : entity work.and_gate
        port map (
            e1 => e1_tb,
            e2 => e2_tb,
            result => result_tb
        );
    simulation : process
    begin
        e1_tb <= '0';
        e2_tb <= '0';
        wait for 20 ns;
        e1_tb <= '1';
        e2_tb <= '0';
        wait for 20 ns;
        e1_tb <= '0';
        e2_tb <= '1';
        wait for 20 ns;
        e1_tb <= '1';
        e2_tb <= '1';
        wait for 20 ns;
    end process ; -- simulation
end behavorial ; -- behavorial