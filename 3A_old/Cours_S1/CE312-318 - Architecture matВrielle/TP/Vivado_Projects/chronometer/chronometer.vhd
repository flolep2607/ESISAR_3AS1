library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity chronometer is
port (
    clk : in STD_LOGIC; -- clock signal
    rst : in STD_LOGIC; -- reset signal
    start : in STD_LOGIC; -- enable signal
    out_secondes  : out STD_LOGIC_VECTOR (7 downto 0); -- counter signal
    out_minutes : out STD_LOGIC_VECTOR (7 downto 0) -- counter signal
);
end entity;

architecture archchronometer of chronometer is
    signal max_clock_counter_tmp, max_secondes_counter_tmp, enable_minute_counter_tmp  : STD_LOGIC := '0';
    signal out_secondestmp, out_minutestmp : STD_LOGIC_VECTOR (7 downto 0);
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
        compteur_clock: compteur_N generic map (C_NB_BIT_COUNTER=>26, C_MODULO=>50000000) port map (clk=>clk, rst=>rst, enable=>start, max=>max_clock_counter_tmp);
        compteur_secondes: compteur_N generic map (C_NB_BIT_COUNTER=>8, C_MODULO=>60) port map (clk=>clk, rst=>rst, enable=>max_clock_counter_tmp, max=>max_secondes_counter_tmp, out_count=>out_secondestmp);
        compteur_minutes: compteur_N generic map (C_NB_BIT_COUNTER=>8, C_MODULO=>60) port map (clk=>clk, rst=>rst, enable=>(max_clock_counter_tmp and max_secondes_counter_tmp), out_count=>out_minutestmp);

        out_secondes <= out_secondestmp;
        out_minutes <= out_minutestmp;
end architecture;