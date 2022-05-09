#include <Practica9.h>
#use standard_io(b)
#define DELAY 100

void main()
{
   set_tris_b(0b00000000);

   while(TRUE)
   {
      output_b(0b10000001);
      delay_ms(DELAY);
      output_b(0b11000011);
      delay_ms(DELAY);
      output_b(0b11100111);
      delay_ms(DELAY);
      output_b(0b11111111);
      delay_ms(DELAY);
      output_b(0b00011000);
      delay_ms(DELAY);
      output_b(0b00111100);
      delay_ms(DELAY);
      output_b(0b01111110);
      delay_ms(DELAY);
      output_b(0b11111111);
      delay_ms(DELAY);
      //TODO: User Code
   }

}
