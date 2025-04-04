library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use ieee.std_logic_signed.all;

entity adder is
port (
    -- data input
    data_inprev       : in  signed( 15 downto 0);
    data_inmult     : in  signed( 15 downto 0);
    data_out       : out signed( 15 downto 0)
  );
end adder;

architecture beh of adder is

begin

data_out <= data_inprev + data_inmult;
end beh;
