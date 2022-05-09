#include <practica17.h>
#use standard_io(a)
#use standard_io(b)

#define RAND_MAX 6
#include <stdlib.h>

void main()
{
   set_tris_a(0b11111);
   set_tris_b(0x00);
   int numeros[6] = {0x79,0x24,0x30,0x19,0x12,0x02};
   int contar=0;
   srand(1);
   
   while(TRUE)
   {
      if (input_state(PIN_A0))
      {
         while (input(PIN_A0)){}
         contar =rand();
         output_b(numeros[contar]);
      }
   }
}
