#include <practica8.h>

void main()
{

   while(TRUE)
   {
      output_high(PIN_B0);
      output_high(PIN_B7);
      delay_ms(500);
      
      output_high(PIN_B1);
      output_high(PIN_B6);
      delay_ms(500);
      
      output_high(PIN_B2);
      output_high(PIN_B5);
      delay_ms(500);
      
      output_high(PIN_B3);
      output_high(PIN_B4);
      delay_ms(500);
      
      output_low(PIN_B0);
      output_low(PIN_B1);
      output_low(PIN_B2);
      output_low(PIN_B3);
      output_low(PIN_B4);
      output_low(PIN_B5);
      output_low(PIN_B6);
      output_low(PIN_B7);
      
      
      output_high(PIN_B3);
      output_high(PIN_B4);
      delay_ms(500);
      
      output_high(PIN_B2);
      output_high(PIN_B5);
      delay_ms(500);
      
      output_high(PIN_B1);
      output_high(PIN_B6);
      delay_ms(500);
      
      output_high(PIN_B0);
      output_high(PIN_B7);
      delay_ms(500);
      
      output_low(PIN_B0);
      output_low(PIN_B1);
      output_low(PIN_B2);
      output_low(PIN_B3);
      output_low(PIN_B4);
      output_low(PIN_B5);
      output_low(PIN_B6);
      output_low(PIN_B7);
      
      //TODO: User Code
   }

}
