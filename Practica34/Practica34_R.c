#include <Practica34_R.h>
#use rs232(baud=9600,xmit=PIN_C6,rcv=PIN_C7)
#include <lcd.c>

int conteo;

#int_RDA

RDA_isr()
{
   conteo=GETC();
}


void main()
{
   lcd_init();
   enable_interrupts(INT_RDA);
   enable_interrupts(GLOBAL);
   while(TRUE)
   {
      lcd_gotoxy(1,1);
      printf(lcd_putc,"recibiendo=%1D",conteo);
   }

}
