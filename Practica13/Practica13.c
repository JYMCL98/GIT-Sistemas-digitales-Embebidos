#include <practica13.h>
#use standard_io(b)
#define DELAY 200

void main()
{

   while(TRUE)
   {
      for(int i=48; i<56; i++)
      {
         output_high(i);
         delay_ms(DELAY);
         output_low(i);
         delay_ms(DELAY);
      }
      
      for(int j=55; j>=48; j--)
      {
         output_high(j);
         delay_ms(DELAY);
         output_low(j);
         delay_ms(DELAY);
      }
   }

}
