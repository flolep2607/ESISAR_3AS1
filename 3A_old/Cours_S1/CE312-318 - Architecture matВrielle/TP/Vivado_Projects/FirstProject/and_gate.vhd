library ieee;
    use ieee.std_logic_1164.all;
    use ieee.numeric_std.all;

entity and_gate is 
    port (
        e1 : in std_logic;
        e2 : in std_logic;
        result : out std_logic
    );
end entity;

architecture rtl of and_gate is
    
begin
    
    process(e1, e2)
    begin
        result <= e1 and e2;
    end process;

end architecture;