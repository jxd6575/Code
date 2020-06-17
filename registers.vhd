library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use ieee.std_logic_signed.all;

entity registers is
port (
    clk        : in  std_logic;
    reset_n       : in  std_logic;
    -- data input
    data_in       : in  signed( 15 downto 0);
    filter_en : in std_logic;
    -- filtered data 
    data_out       : out signed( 15 downto 0)
  );
end registers

architecture beh of registers is

begin

registrate : process (reset_n,clk)
begin

    if(reset_n = '0') then 
    data_in <= (others => 0);
    elsif(rising_edge(clk) and filter_en = '1') then 
    data_out <= data_in;
    end if;
end process registrate;

end beh;