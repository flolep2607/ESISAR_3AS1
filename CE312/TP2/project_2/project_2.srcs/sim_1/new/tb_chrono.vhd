library ieee;
	use ieee.std_logic_1164.all;
	use ieee.numeric_std.all;

entity tb_chrono is
end tb_chrono;

architecture Behavioral of tb_chrono is
	signal clk_tb		: std_logic	:='0';
	signal rst_tb		: std_logic	:='0';
	signal enable_tb	: std_logic	:='0';
	signal out_count1_tb	: std_logic_vector(5 downto 0)	:= (others => '0');
	signal out_count2_tb	: std_logic_vector(5 downto 0)	:= (others => '0');
begin
	inst : entity work.chrono
	   generic map(
            DIV=>1
        )
		port map(
			clk			=> clk_tb,
			rst			=> rst_tb,
			enable		=> enable_tb,
			out1_count	=> out_count1_tb,
			out2_count  => out_count2_tb
		);
	
	clk_tb <= not clk_tb after 5 ns;	-- Periode : 10ns --> Frequence : 100MHz

	stim_proc :	process
	begin
		rst_tb		<= '0';
		enable_tb	<= '0';
		wait for 50 ns;

		rst_tb		<= '1';
		enable_tb	<= '0';
		wait for 20 ns;

		rst_tb		<= '0';
		enable_tb	<= '1';
		wait for 100 ns;

		rst_tb		<= '0';
		enable_tb	<= '0';
		wait for 20 ns;

		rst_tb		<= '0';
		enable_tb	<= '1';
		wait for 200 ns;

		rst_tb		<= '1';
		enable_tb 	<= '1';
		wait for 50 ns;

		rst_tb		<= '0';
		enable_tb 	<= '1';
		wait for 100 ns;

		wait;
    end process;
end Behavioral;

