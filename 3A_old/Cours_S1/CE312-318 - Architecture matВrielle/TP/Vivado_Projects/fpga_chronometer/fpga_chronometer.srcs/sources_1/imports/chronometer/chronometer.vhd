library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity chronometer is
port (
    clk : in STD_LOGIC; -- clock signal
    rst : in STD_LOGIC; -- reset signal
    enable : in STD_LOGIC; -- enable signal
    out_secondes  : out STD_LOGIC_VECTOR (5 downto 0); -- counter signal
    out_minutes : out STD_LOGIC_VECTOR (5 downto 0) -- counter signal
);
end entity;

architecture archchronometer of chronometer is
    signal max_clock_counter_tmp, max_secondes_counter_tmp, enable_minute_counter_tmp  : STD_LOGIC := '0';
    signal out_secondestmp, out_minutestmp : STD_LOGIC_VECTOR (5 downto 0) := (others=>'0');
    component compteur_N
        generic (
            C_NB_BIT_COUNTER : integer;
            C_MODULO : integer
        );
        port (
            clk : in STD_LOGIC;
            rst : in STD_LOGIC;
            enable : in STD_LOGIC;
            max  : out STD_LOGIC; -- bit overflow
            out_count : out STD_LOGIC_VECTOR (C_NB_BIT_COUNTER-1 downto 0) -- le compteur temporaire
        );
    end component;
    -- two signal for made operations on it - because we cant on out an in signal
    begin
        compteur_clock: compteur_N generic map (C_NB_BIT_COUNTER=>26, C_MODULO=>50000000) port map (clk=>clk, rst=>rst, enable=>enable, max=>max_clock_counter_tmp);
        compteur_secondes: compteur_N generic map (C_NB_BIT_COUNTER=>6, C_MODULO=>60) port map (clk=>clk, rst=>rst, enable=>max_clock_counter_tmp, max=>max_secondes_counter_tmp, out_count=>out_secondestmp);
        compteur_minutes: compteur_N generic map (C_NB_BIT_COUNTER=>6, C_MODULO=>60) port map (clk=>clk, rst=>rst, enable=>enable_minute_counter_tmp, out_count=>out_minutestmp);
        process(clk) -- active when event happen on signal clk
        begin
            if (clk'event and clk='1') then
                if rst='1' then
                    max_clock_counter_tmp <= '0';
                    max_secondes_counter_tmp <= '0';
                    out_secondestmp <= (others=>'0');
                    out_minutestmp <= (others=>'0');
                elsif(max_clock_counter_tmp = '1' and max_secondes_counter_tmp = '1') then
                    enable_minute_counter_tmp <= '1';
                else
                    enable_minute_counter_tmp <= '0';
                end if;
            end if;
        end process;
        out_secondes <= out_secondestmp;
        out_minutes <= out_minutestmp;
end architecture;