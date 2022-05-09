#include <Practica32.h>
#use standard_io(b)

void main()
{
   set_tris_b(0b00000000);
   output_b(0b00000000);
   while(TRUE)
   {
      // Giro a la derecha
      output_high(PIN_B0);
      delay_ms(1000);
      output_low(PIN_B0);
      delay_ms(200);
      // Giro a la izquierda
      output_high(PIN_B1);
      delay_ms(1000);
      output_low(PIN_B1);
      delay_ms(200);
   }
}
