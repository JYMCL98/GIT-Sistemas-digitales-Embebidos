#include <Practica14.h>
#use standard_io(b)

void main()
{
   set_tris_b(0x00);
   int numeros[10] = {0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x18};
   
   while(TRUE)
   {
      for(int i=0; i<10; i++)
      {
         output_b(numeros[i]);
         delay_ms(200);
      }
   }

}
