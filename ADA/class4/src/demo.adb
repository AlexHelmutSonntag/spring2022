with Setq, Ada.Integer_Text_IO, Ada.Text_IO;
use Setq, Ada.Integer_Text_IO, Ada.Text_IO;
with Bag; use Bag;
procedure demo is

   R: Rational := 4/8;
   B: Bag 
    -- X: Rational := 3/4/
begin

    R := R / (R/2);
    Put( Numerator(R) );
    Put( '/' );
    Put( Denominator(R) );
    R:= (2/4 + 5/2);
   Put( Numerator(R) );
    Put( Denominator(R) );
end demo;