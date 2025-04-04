library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use ieee.std_logic_signed.all;
entity lab_8 is
port (
    clk        : in  std_logic;
    reset_n       : in  std_logic;
    -- data input
    data_in       : in  signed( 15 downto 0);
    filter_en : in std_logic;
    -- filtered data 
    data_out       : out signed( 15 downto 0)
  );
end lab_8;

Architecture beh of lab_8 is

    component mult is
    PORT (
            dataa		: IN STD_LOGIC_VECTOR (15 DOWNTO 0);
            datab		: IN STD_LOGIC_VECTOR (15 DOWNTO 0);
            result		: OUT STD_LOGIC_VECTOR (31 DOWNTO 0)
            );
            
     end component;
     
     component registers is
     port (
    clk        : in  std_logic;
    reset_n       : in  std_logic;
    -- data input
    data_in       : in  signed( 15 downto 0);
    filter_en : in std_logic;
    -- filtered data 
    data_out       : out signed( 15 downto 0)
    );
    end component;
    component adder is
    port (
    -- data input
    data_inprev       : in  signed( 15 downto 0);
    data_inmult     : in  signed( 15 downto 0);
    data_out       : out signed( 15 downto 0)
  );
  end component;
        -- low pass
-- constant coef0 : signed(15 downto 0):= x"0052";
-- constant coef1 : signed(15 downto 0) := x"00BB";
-- constant coef2 : signed(15 downto 0):= x"01E2";
-- constant coef3 : signed(15 downto 0):= x"0408";
-- constant coef4 : signed(15 downto 0):= x"071B";
-- constant coef5 : signed(15 downto 0):= x"0AAD";
-- constant coef6 : signed(15 downto 0):= x"0E11";
-- constant coef7 : signed(15 downto 0):= x"1080";
-- constant coef8 : signed(15 downto 0):= x"1162";
-- constant coef9 : signed(15 downto 0):= x"1080";
-- constant coef10 : signed(15 downto 0):= x"0E11";
-- constant coef11 : signed(15 downto 0):= x"0AAD";
-- constant coef12 : signed(15 downto 0):= x"071B";
-- constant coef13 : signed(15 downto 0):= x"0408";
-- constant coef14 : signed(15 downto 0):= x"01E2";
-- constant coef15 : signed(15 downto 0):= x"00BB";
-- constant coef16 : signed(15 downto 0):= x"0052";
-- high pass 
constant coef0 : signed(15 downto 0):= x"003E";
constant coef1 : signed(15 downto 0):= x"FF9A";
constant coef2 : signed(15 downto 0):= x"FE9E";
constant coef3 : signed(15 downto 0):= x"0000";
constant coef4 : signed(15 downto 0):= x"0536";
constant coef5 : signed(15 downto 0):= x"05B2";
constant coef6 : signed(15 downto 0) := x"F5AC";
constant coef7 : signed(15 downto 0):= x"DAB7";
constant coef8 : signed(15 downto 0):= x"4C92";
constant coef9 : signed(15 downto 0):= x"DAB7";
constant coef10 : signed(15 downto 0):= x"F5AC";
constant coef11 : signed(15 downto 0):= x"05B2";
constant coef12 : signed(15 downto 0):= x"0536";
constant coef13 : signed(15 downto 0):= x"0000";
constant coef14 : signed(15 downto 0):= x"FE9E";
constant coef15 : signed(15 downto 0):= x"FF9A";
constant coef16 : signed(15 downto 0):= x"003E";
signal data_in1 : signed(15 downto 0);
signal data_in2 : signed(15 downto 0);
signal data_in3 : signed(15 downto 0);
signal data_in4 : signed(15 downto 0);
signal data_in5 : signed(15 downto 0);
signal data_in6 : signed(15 downto 0);
signal data_in7 : signed(15 downto 0);
signal data_in8 : signed(15 downto 0);
signal data_in9 : signed(15 downto 0);
signal data_in10 : signed(15 downto 0);
signal data_in11 : signed(15 downto 0);
signal data_in12 : signed(15 downto 0);
signal data_in13 : signed(15 downto 0);
signal data_in14 : signed(15 downto 0);
signal data_in15 : signed(15 downto 0);
signal data_in16 : signed(15 downto 0);

signal multres0 : std_logic_vector(31 downto 0);
signal multres1 : std_logic_vector(31 downto 0);
signal multres2 : std_logic_vector(31 downto 0);
signal multres3 : std_logic_vector(31 downto 0);
signal multres4 : std_logic_vector(31 downto 0);
signal multres5 : std_logic_vector(31 downto 0);
signal multres6 : std_logic_vector(31 downto 0);
signal multres7 : std_logic_vector(31 downto 0);
signal multres8 : std_logic_vector(31 downto 0);
signal multres9 : std_logic_vector(31 downto 0);
signal multres10 : std_logic_vector(31 downto 0);
signal multres11 : std_logic_vector(31 downto 0);
signal multres12 : std_logic_vector(31 downto 0);
signal multres13 : std_logic_vector(31 downto 0);
signal multres14 : std_logic_vector(31 downto 0);
signal multres15 : std_logic_vector(31 downto 0);
signal multres16 : std_logic_vector(31 downto 0);

signal multfix0 : signed(15 downto 0);
signal multfix1 : signed(15 downto 0);
signal multfix2 : signed(15 downto 0);
signal multfix3 : signed(15 downto 0);
signal multfix4 : signed(15 downto 0);
signal multfix5 : signed(15 downto 0);
signal multfix6 : signed(15 downto 0);
signal multfix7 : signed(15 downto 0);
signal multfix8 : signed(15 downto 0);
signal multfix9 : signed(15 downto 0);
signal multfix10 : signed(15 downto 0);
signal multfix11 : signed(15 downto 0);
signal multfix12 : signed(15 downto 0);
signal multfix13 : signed(15 downto 0);
signal multfix14 : signed(15 downto 0);
signal multfix15 : signed(15 downto 0);
signal multfix16 : signed(15 downto 0);


signal sum0 : signed(15 downto 0);
signal sum1 : signed(15 downto 0);
signal sum2 : signed(15 downto 0);
signal sum3 : signed(15 downto 0);
signal sum4 : signed(15 downto 0);
signal sum5 : signed(15 downto 0);
signal sum6 : signed(15 downto 0);
signal sum7 : signed(15 downto 0);
signal sum8 : signed(15 downto 0);
signal sum9 : signed(15 downto 0);
signal sum10 : signed(15 downto 0);
signal sum11 : signed(15 downto 0);
signal sum12 : signed(15 downto 0);
signal sum13 : signed(15 downto 0);
signal sum14 : signed(15 downto 0);
--signal sum15 : signed(15 downto 0);


begin

multfix0 <= signed(multres0(30 downto 15));
multfix1 <= signed(multres1(30 downto 15));
multfix2 <= signed(multres2(30 downto 15));
multfix3 <= signed(multres3(30 downto 15));
multfix4 <= signed(multres4(30 downto 15));
multfix5 <= signed(multres5(30 downto 15));
multfix6 <= signed(multres6(30 downto 15));
multfix7 <= signed(multres7(30 downto 15));
multfix8 <= signed(multres8(30 downto 15));
multfix9 <= signed(multres9(30 downto 15));
multfix10 <= signed(multres10(30 downto 15));
multfix11 <= signed(multres11(30 downto 15));
multfix12 <= signed(multres12(30 downto 15));
multfix13 <= signed(multres13(30 downto 15));
multfix14 <= signed(multres14(30 downto 15));
multfix15  <= signed(multres15(30 downto 15));
multfix16 <= signed(multres16(30 downto 15));
mult_inst0 : mult PORT MAP (
		dataa	 => std_logic_vector(data_in),
		datab	 => std_logic_vector(coef0),
		result	 => multres0
	);
    
mult_inst1 : mult PORT MAP (
		dataa	 => std_logic_vector(data_in1),
		datab	 => std_logic_vector(coef1),
		result	 => multres1
	);
    
mult_inst2 : mult PORT MAP (
		dataa	 => std_logic_vector(data_in2),
		datab	 => std_logic_vector(coef2),
		result	 => multres2
	);
    
mult_inst3 : mult PORT MAP (
		dataa	 => std_logic_vector(data_in3),
		datab	 => std_logic_vector(coef3),
		result	 => multres3
	);
    
mult_inst4 : mult PORT MAP (
		dataa	 => std_logic_vector(data_in4),
		datab	 => std_logic_vector(coef4),
		result	 => multres4
	);
    
mult_inst5 : mult PORT MAP (
		dataa	 => std_logic_vector(data_in5),
		datab	 => std_logic_vector(coef5),
		result	 => multres5
	);
    
mult_inst6 : mult PORT MAP (
		dataa	 => std_logic_vector(data_in6),
		datab	 => std_logic_vector(coef6),
		result	 => multres6
	);
    
mult_inst7 : mult PORT MAP (
		dataa	 => std_logic_vector(data_in7),
		datab	 => std_logic_vector(coef7),
		result	 => multres7
	);
    
mult_inst8 : mult PORT MAP (
		dataa	 => std_logic_vector(data_in8),
		datab	 => std_logic_vector(coef8),
		result	 => multres8
	);
    
mult_inst9 : mult PORT MAP (
		dataa	 => std_logic_vector(data_in9),
		datab	 => std_logic_vector(coef9),
		result	 => multres9
	);
    
mult_inst10 : mult PORT MAP (
		dataa	 => std_logic_vector(data_in10),
		datab	 => std_logic_vector(coef10),
		result	 => multres10
	);
    
mult_inst11 : mult PORT MAP (
		dataa	 => std_logic_vector(data_in11),
		datab	 => std_logic_vector(coef11),
		result	 => multres11
	);
    
mult_inst12 : mult PORT MAP (
		dataa	 => std_logic_vector(data_in12),
		datab	 => std_logic_vector(coef12),
		result	 => multres12
	);
    
mult_inst13 : mult PORT MAP (
		dataa	 => std_logic_vector(data_in13),
		datab	 => std_logic_vector(coef13),
		result	 => multres13
	);
    
mult_inst14 : mult PORT MAP (
		dataa	 => std_logic_vector(data_in14),
		datab	 => std_logic_vector(coef14),
		result	 => multres14
	);
    
mult_inst15 : mult PORT MAP (
		dataa	 => std_logic_vector(data_in15),
		datab	 => std_logic_vector(coef15),
		result	 => multres15
	);
    
mult_inst16 : mult PORT MAP (
		dataa	 => std_logic_vector(data_in16),
		datab	 => std_logic_vector(coef16),
		result	 => multres16
	);
    
register0 : registers PORT MAP(
        clk => clk,
        reset_n => reset_n,
        data_in => data_in,
        filter_en => filter_en,
        data_out => data_in1
        );
       
register1 : registers PORT MAP(
        clk => clk,
        reset_n => reset_n,
        data_in => data_in1,
        filter_en => filter_en,
        data_out => data_in2
        );
        
register2 : registers PORT MAP(
        clk => clk,
        reset_n => reset_n,
        data_in => data_in2,
        filter_en => filter_en,
        data_out => data_in3
        );
        
register3 : registers PORT MAP(
        clk => clk,
        reset_n => reset_n,
        data_in => data_in3,
        filter_en => filter_en,
        data_out => data_in4
        );
        
register4 : registers PORT MAP(
        clk => clk,
        reset_n => reset_n,
        data_in => data_in4,
        filter_en => filter_en,
        data_out => data_in5
        );
        
register5 : registers PORT MAP(
        clk => clk,
        reset_n => reset_n,
        data_in => data_in5,
        filter_en => filter_en,
        data_out => data_in6
        );
        
register6 : registers PORT MAP(
        clk => clk,
        reset_n => reset_n,
        data_in => data_in6,
        filter_en => filter_en,
        data_out => data_in7
        );
        
register7 : registers PORT MAP(
        clk => clk,
        reset_n => reset_n,
        data_in => data_in7,
        filter_en => filter_en,
        data_out => data_in8
        );
        
register8 : registers PORT MAP(
        clk => clk,
        reset_n => reset_n,
        data_in => data_in8,
        filter_en => filter_en,
        data_out => data_in9
        );
       
register9 : registers PORT MAP(
        clk => clk,
        reset_n => reset_n,
        data_in => data_in9,
        filter_en => filter_en,
        data_out => data_in10
        );
        
register10 : registers PORT MAP(
        clk => clk,
        reset_n => reset_n,
        data_in => data_in10,
        filter_en => filter_en,
        data_out => data_in11
        );
        
register11 : registers PORT MAP(
        clk => clk,
        reset_n => reset_n,
        data_in => data_in11,
        filter_en => filter_en,
        data_out => data_in12
        );
        
register12 : registers PORT MAP(
        clk => clk,
        reset_n => reset_n,
        data_in => data_in12,
        filter_en => filter_en,
        data_out => data_in13
        );
        
register13 : registers PORT MAP(
        clk => clk,
        reset_n => reset_n,
        data_in => data_in13,
        filter_en => filter_en,
        data_out => data_in14
        );
        
register14 : registers PORT MAP(
        clk => clk,
        reset_n => reset_n,
        data_in => data_in14,
        filter_en => filter_en,
        data_out => data_in15
        );
        
register15 : registers PORT MAP(
        clk => clk,
        reset_n => reset_n,
        data_in => data_in15,
        filter_en => filter_en,
        data_out => data_in16
        );
        
adder0 :  adder PORT MAP(
   data_inprev => multfix0,
    data_inmult => multfix1,
    data_out => sum0
    );

adder1 :  adder PORT MAP(
   data_inprev => sum0,
    data_inmult => multfix2,
    data_out => sum1
    );
    
adder2 :  adder PORT MAP(
   data_inprev => sum1,
    data_inmult => multfix3,
    data_out => sum2
    );
    
adder3 :  adder PORT MAP(
   data_inprev => sum2,
    data_inmult => multfix4,
    data_out => sum3
    );
    
adder4 :  adder PORT MAP(
   data_inprev => sum3,
    data_inmult => multfix5,
    data_out => sum4
    );
    
adder5 :  adder PORT MAP(
   data_inprev => sum4,
    data_inmult => multfix6,
    data_out => sum5
    );
    
adder6 :  adder PORT MAP(
   data_inprev => sum5,
    data_inmult => multfix7,
    data_out => sum6
    );
    
adder7 :  adder PORT MAP(
   data_inprev => sum6,
    data_inmult => multfix8,
    data_out => sum7
    );

adder8 :  adder PORT MAP(
   data_inprev => sum7,
    data_inmult => multfix9,
    data_out => sum8
    );
    
adder9 :  adder PORT MAP(
   data_inprev => sum8,
    data_inmult => multfix10,
    data_out => sum9
    );
    
adder10 :  adder PORT MAP(
   data_inprev => sum9,
    data_inmult => multfix11,
    data_out => sum10
    );
    
adder11 :  adder PORT MAP(
   data_inprev => sum10,
    data_inmult => multfix12,
    data_out => sum11
    );
    
adder12 :  adder PORT MAP(
   data_inprev => sum11,
    data_inmult => multfix13,
    data_out => sum12
    );
    
adder13 :  adder PORT MAP(
   data_inprev => sum12,
    data_inmult => multfix14,
    data_out => sum13
    );
    
adder14 :  adder PORT MAP(
   data_inprev => sum13,
    data_inmult => multfix15,
    data_out => sum14
    );

adder15 :  adder PORT MAP(
   data_inprev => sum14,
    data_inmult => multfix16,
    data_out => data_out
    );
    

end beh;
