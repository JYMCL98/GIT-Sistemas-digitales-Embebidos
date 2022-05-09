#include <practica30.h>
#use standard_io(b)

void main()
{
   set_tris_b(0b00000000);
   output_b(0b00000000);
   while(TRUE)
   {
   
      
      output_high(PIN_B0);
      delay_ms(2000);
      output_low(PIN_B0);
      
      output_high(PIN_B1);
      delay_ms(1000);
      output_low(PIN_B1);
      delay_ms(300);
      output_high(PIN_B1);
      delay_ms(300);
      output_low(PIN_B1);
      
      output_high(PIN_B2);
      delay_ms(2000);
      output_low(PIN_B2);
   }

}
