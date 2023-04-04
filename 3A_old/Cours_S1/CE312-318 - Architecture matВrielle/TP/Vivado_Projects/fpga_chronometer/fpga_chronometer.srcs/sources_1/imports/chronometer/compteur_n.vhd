library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity compteur_N is
generic (
    C_NB_BIT_COUNTER : integer;
    C_MODULO : integer
);
port (
    clk : in STD_LOGIC; -- clock signal
    rst : in STD_LOGIC; -- reset signal
    enable : in STD_LOGIC; -- enable signal
    max  : out STD_LOGIC; -- bit overflow
    out_count : out STD_LOGIC_VECTOR (C_NB_BIT_COUNTER-1 downto 0) -- counter signal
);
end entity;

architecture archcompteur of compteur_N is
  signal maxtmp : STD_LOGIC := '0';
  signal outtmp : STD_LOGIC_VECTOR (C_NB_BIT_COUNTER-1 downto 0) := (others=>'0');
  -- two signal for made operations on it - because we cant on out an in signal
  begin
    process(clk) -- active when event happen on signal clk
    begin
      if (clk'event and clk='1') then
        maxtmp <= '0';
        if rst='1' then
          outtmp <= (others=>'0');
        elsif (enable='1') then -- no reset, counter enable
          outtmp <= std_logic_vector(unsigned(outtmp)+ 1); -- add 1 to unsigned
          if (unsigned(outtmp) = (C_MODULO-2)) then  -- max is reach
            maxtmp <= '1';
          elsif(unsigned(outtmp) = (C_MODULO-1)) then -- restart the counter
            outtmp <= (others=>'0');
          end if;
        end if;
      end if;
   end process;
    
    -- output assignment
    max <= maxtmp;
    out_count <= outtmp;
end architecture;