library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity compteur_16 is
port (
    clk : in STD_LOGIC;
    rst : in STD_LOGIC;
    enable : in STD_LOGIC;
    deb  : out STD_LOGIC; -- bit overflow
    out_count : out STD_LOGIC_VECTOR (3 downto 0) -- counter
);
end entity;

architecture archcompteur of compteur_16 is
  signal debtmp : STD_LOGIC := '0';
  signal outtmp : STD_LOGIC_VECTOR (3 downto 0) := (others=>'0');
  begin
  
    -- clock event
    process(clk)
    begin
      if (clk'event and clk='1') then
        if rst='1' then
          debtmp <= '0';
          outtmp <= (others=>'0');
        elsif (enable='1') then -- no reset, counter enable
          if (outtmp = "1111") then
            outtmp <= (others=>'0');
            debtmp <= not debtmp;
          else
            outtmp <= std_logic_vector(unsigned(outtmp)+ 1);
          end if;
        end if;
      end if;
    end process;
    
    -- output assignment
    deb <= debtmp;
    out_count <= outtmp;
end architecture;