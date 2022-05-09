#include <Practica3.h>
#use rs232(baud=9600,xmit=PIN_C6, rcv=PIN_C7)
#include <lcd.c>
int contador;

void main()
{
   lcd_init();
   while(TRUE)
   {
      for (contador=0;contador<10;contador++)
      {
         putc(contador);
         printf(lcd_putc,"\f Transmitiendo=%1D", contador);
         delay_ms(300);
      }
   }

}
