#include <Practica16.h>
#use standard_io(a)
#use standard_io(b)
#use standard_io(c)

void main()
{
   set_tris_a(0b11111);
   set_tris_b(0b00000000);
   set_tris_c(0b00000000);
   
   int numero[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67};
   output_b(numero[0]);
   output_c(numero[0]);
   while(TRUE)
   {
      if(input_state(PIN_A0)==1){
         for (int decenas=0;decenas<=9;decenas++){
            output_b(numero[decenas]);
            for(int unidades=0;unidades<=9;unidades++){
               output_c(numero[unidades]);
               delay_ms(300);
            }
         }
      }
      
      else{
         output_b(numero[0]);
         output_c(numero[0]);
      }
   }

}
