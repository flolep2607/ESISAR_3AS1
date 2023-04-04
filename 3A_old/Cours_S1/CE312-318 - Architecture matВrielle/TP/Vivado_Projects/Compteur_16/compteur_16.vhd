library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity compteur_16 is
port (
    clk : in STD_LOGIC; -- clock signal
    rst : in STD_LOGIC; -- reset signal
    enable : in STD_LOGIC; -- enable signal
    deb  : out STD_LOGIC; -- bit overflow
    out_count : out STD_LOGIC_VECTOR (3 downto 0) -- counter signal
);
end entity;

architecture archcompteur of compteur_16 is
  signal debtmp : STD_LOGIC := '0';
  signal outtmp : STD_LOGIC_VECTOR (3 downto 0) := (others=>'0');
  signal full_signal : STD_LOGIC_VECTOR (3 downto 0) := (others=>'1');
  -- two signal for made operations on it - because we cant on out an in signal
  begin
  
    process(clk) -- active when event happen on signal clk
    begin
      if (clk'event and clk='1') then
        if rst='1' then
          debtmp <= '0';
          outtmp <= (others=>'0');
        elsif (enable='1') then -- no reset, counter enable
          if (unsigned(outtmp) = unsigned(full_signal)) then  -- add bit overflow + reset out_count
            outtmp <= (others=>'0');
            debtmp <= not debtmp;
          else
            outtmp <= std_logic_vector(unsigned(outtmp)+ 1); -- add 1 to unsigned
          end if;
        end if;
      end if;
    end process;
    
    -- output assignment
    deb <= debtmp;
    out_count <= outtmp;
end architecture;