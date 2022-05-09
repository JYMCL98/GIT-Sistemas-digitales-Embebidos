#include <practica24.h>
#include <lcd.c>
#use standard_io(a)
#use standard_io(c)


void main()
{
   lcd_init();
   set_tris_a(0b11111);
   set_tris_c(0b00000000);
   int steps[4] = {0b00001010,0b00001001,0b00000101,0b00000110};
   
   while(TRUE)
   {
      if(input(PIN_A0))
      {
         lcd_gotoxy(1,1);
         printf(lcd_putc," Motor funcionando");
         lcd_gotoxy(1,2);
         printf(lcd_putc,"Izquierda");
         for(int i=0; i<4; i++)
         {
            output_c(steps[i]);
            delay_ms(500);
         }
      }
      else if (input(PIN_A1))
      {
         lcd_gotoxy(1,1);
         printf(lcd_putc," Motor funcionando");
         lcd_gotoxy(1,2);
         printf(lcd_putc,"Derecha");
         for(int j=5; j>=1;j--)
         {
            output_c(steps[j-1]);
            delay_ms(500);
         }
      }
      else
      {
         lcd_gotoxy(1,1);
         printf(lcd_putc,"Motor fuera");
         lcd_gotoxy(1,2);
         printf(lcd_putc,"De servicio");
         delay_ms(500);
      }
   }

}
