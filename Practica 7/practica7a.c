#include <practica7a.h>

void main()
{

   while(TRUE)
   {

      //Example blinking LED program
      output_low(PIN_B0);
      delay_ms(DELAY);
      output_high(PIN_B0);
      delay_ms(DELAY);
      
      output_low(PIN_B1);
      delay_ms(DELAY);
      output_high(PIN_B1);
      delay_ms(DELAY);
      
      output_low(PIN_B2);
      delay_ms(DELAY);
      output_high(PIN_B2);
      delay_ms(DELAY);
      
      output_low(PIN_B3);
      delay_ms(DELAY);
      output_high(PIN_B3);
      delay_ms(DELAY);
      
      output_low(PIN_B4);
      delay_ms(DELAY);
      output_high(PIN_B4);
      delay_ms(DELAY);
      
      output_low(PIN_B5);
      delay_ms(DELAY);
      output_high(PIN_B5);
      delay_ms(DELAY);
      
      output_low(PIN_B6);
      delay_ms(DELAY);
      output_high(PIN_B6);
      delay_ms(DELAY);
      
      output_low(PIN_B7);
      delay_ms(DELAY);
      output_high(PIN_B7);
      delay_ms(DELAY);

      //TODO: User Code
   }

}
