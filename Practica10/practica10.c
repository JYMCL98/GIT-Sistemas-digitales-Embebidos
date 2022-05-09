#include <practica10.h>
#use standard_io(b)
#define DELAY 200

void main()
{
   set_tris_b(0b00000000);
   while(TRUE)
   {
      output_b(0x40);
      delay_ms(DELAY);
      output_b(0x79);
      delay_ms(DELAY);
      output_b(0x24);
      delay_ms(DELAY); 
      output_b(0x30);
      delay_ms(DELAY);
      output_b(0x19);
      delay_ms(DELAY);
      output_b(0x12);
      delay_ms(DELAY);
      output_b(0x02);
      delay_ms(DELAY);
      output_b(0x78);
      delay_ms(DELAY);
      output_b(0x00);
      delay_ms(DELAY);
      output_b(0x18);
      delay_ms(DELAY);
      
      //TODO: User Code
   }

}
