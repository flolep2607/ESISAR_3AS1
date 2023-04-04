library ieee;
    use ieee.std_logic_1164.all;
    use ieee.numeric_std.all;

entity and_gate_registered is
  port (
    reset_n : in std_logic;
    clock : in std_logic;
    e1 : in std_logic;
    e2 : in std_logic;
    result : out std_logic
  ) ;
end entity;

architecture rtl of and_gate_registered is
    begin
        process(reset_n, clock)
        begin
            if(reset_n = '0') then 
                result <= '0';
            elsif(rising_edge(clock)) then
                result <= e1 and e2;
            end if;            
        end process;
end architecture; -- rtl