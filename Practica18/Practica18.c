#include <Practica18.h>
#use standard_io(b)

#INT_EXT
ext_itr()
{
   output_toggle(PIN_B1);
}

void main()
{
   set_tris_b(0b00000001);
   enable_interrupts(int_ext);
   ext_int_edge(L_TO_H);
   enable_interrupts(GLOBAL);
   
   while(TRUE)
   {
      output_high(PIN_B2);
      delay_ms(250);
      output_low(PIN_B2);
      delay_ms(250);
   }
}
