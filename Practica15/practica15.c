#include <practica15.h>
#use standard_io(a)
#use standard_io(b)

void main()
{
   set_tris_a(0b11111);
   set_tris_b(0x00);
   int numeros[10] = {0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x18};
   int conteo=0;
   output_b(numeros[0]);
   
   while(TRUE)
   {
      if (input_state(PIN_A0)==1)
      {
         while(input_state(PIN_A0)){}
         conteo=conteo+1;
         if (conteo>=10)
         {
            conteo=0;
         }
         output_b(numeros[conteo]);
      }
   }

}
