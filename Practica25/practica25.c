#include <practica25.h>
#use standard_io(c)


void main()
{
   set_tris_a(0b11111);
   set_tris_c(0b00000000);
   output_high(PIN_C2);       // Se factoriza para optimizar el codigo
   
   while(TRUE)
   {
      //PIN_C0---Enable
      //PIN_C1---1A
      //PIN_C2---2A
      
      //PIN_A0---Control de giro a la derecha
      //PINA_1---Control de giro a la izquierda
      
      if(input_state(PIN_A0))
      {
         //output_high(PIN_C0);
         output_low(PIN_C0);
         output_high(PIN_C1);
      }
      else if (input_state(PIN_A1))
      {
         //output_high(PIN_C0);
         output_high(PIN_C0);
         output_low(PIN_C1);
      }
      else
      {
         //output_high(PIN_C0);
         output_low(PIN_C0);
         output_low(PIN_C1);
      }
      
   }

}
