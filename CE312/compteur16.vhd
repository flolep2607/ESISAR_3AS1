LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.NUMERIC_STD.ALL;

ENTITY compteur_16 IS
    PORT (
        clk : IN STD_LOGIC;
        rst : IN STD_LOGIC;
        enable : IN STD_LOGIC;
        deb : OUT STD_LOGIC;
        out_count : OUT STD_LOGIC_VECTOR (3 DOWNTO 0)
    );
END compteur_16;

ARCHITECTURE modulo_16 OF compteur_16 IS
    SIGNAL t_count : STD_LOGIC_VECTOR(3 DOWNTO 0);
BEGIN
    PROCESS (clk, rst)

    BEGIN
        IF (clk'event AND clk = '1') THEN
            IF rst = '1' THEN
                t_count <= "0000";
            ELSIF enable = '1' THEN
                IF t_count = "1111" THEN
                    t_count <= "0000";
                    deb <= '1';
                ELSE
                    t_count <= std_logic_vector(unsigned(t_count) + 1);
                    deb <= '0';
                END IF;
            END IF;
        END IF;
    END PROCESS;
    out_count <= t_count;
END modulo_16;