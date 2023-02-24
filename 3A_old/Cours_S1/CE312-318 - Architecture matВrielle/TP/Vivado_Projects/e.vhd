library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity register is
	generic (
		fxmax : integer
	);
	port
	(
		data_in : in integer range 0 to fxmax;
		data_out : out integer range 0 to fxmax;
		twindow : in STD_LOGIC
	);
end entity;

architecture register_arch of register is
	signal outtmp : integer range 0 to fxmax;
	-- two signal for made operations on it - because we cant on out an in signal
	begin
		process(clk) -- active when event happen on signal clk
		begin
			if (clk'event and clk='1') then
				outtmp <= data_in;
			end if;
	  	end process;
		-- output assignment
	data_out <= outtmp;
end architecture;

entity counter2 is
	generic (
		fxmax : integer
	);
	port
	(
		in : in STD_LOGIC;
		count2 : out integer range 0 to fxmax;
		reset : in STD_LOGIC
	);
end entity;

architecture counter2_arch of counter2 is
	signal outtmp : integer range 0 to fxmax;
	-- two signal for made operations on it - because we cant on out an in signal
	begin
		process(clk) -- active when event happen on signal clk
		begin
			if (clk'event and clk='1') then
				if reset='1' then
					outtmp <= 0;
				else 
					outtmp <= outtmp+1;
				end if;
			end if;
	  	end process;
		-- output assignment
	count2 <= outtmp;
end architecture;


entity counter1 is
	generic (
		fclk : integer
	);
	port
	(
		in : in STD_LOGIC;
		twindow : out STD_LOGIC
	);
end entity;

architecture counter1_arch of counter1 is
	signal compteur : integer range 0 to fclk;
	-- two signal for made operations on it - because we cant on out an in signal
	begin
		process(clk) -- active when event happen on signal clk
		begin
			if (clk'event and clk='1') then
				if compteur = fclk then
					twindow <= 1;
					compteur := 0;
				else 
					twindow <= 0;
					compteur := compteur+1;
				end if;
			end if;
	  	end process;
		-- output assignment
end architecture;