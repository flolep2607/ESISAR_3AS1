library ieee;
    use ieee.std_logic_1164.all;
    use ieee.numeric_std.all;

entity and_gate_registered_tb is
end entity;

architecture behavorial of and_gate_registered_tb is
    signal  reset_n_tb : std_logic;
    signal  clock_tb : std_logic;
    signal  e1_tb : std_logic;
    signal  e2_tb : std_logic;
    signal  result_tb : std_logic;

begin
    i_uut : entity work.and_gate_registered
        port map
        (
            reset_n => reset_n_tb,
            clock => clock_tb,
            e1 => e1_tb,
            e2 => e2_tb,
            result => result_tb
        );
    
    clock_100mhz_generation : process
        begin
            clock_tb <= '0';
            wait for 5 ns;
            clock_tb <= '1';
            wait for 5 ns;        
    end process ; -- clock_100mhz_generation

    simulation : process
        begin
            reset_n_tb <= '0';
            e1_tb <= '0';
            e2_tb <= '0';
            wait for 31 ns;
            e1_tb <= '1';
            e2_tb <= '0';
            wait for 31 ns;
            e1_tb <= '0';
            e2_tb <= '1';
            wait for 31 ns;
            e1_tb <= '1';
            e2_tb <= '1';
            wait for 31 ns;
            reset_n_tb <= '1';
            e1_tb <= '0';
            e2_tb <= '0';
            wait for 31 ns;
            e1_tb <= '1';
            e2_tb <= '0';
            wait for 31 ns;
            e1_tb <= '0';
            e2_tb <= '1';
            wait for 31 ns;
            e1_tb <= '1';
            e2_tb <= '1';
            wait for 31 ns;
    end process; -- simulation
end architecture; -- behavorial 