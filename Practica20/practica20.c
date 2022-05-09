#include <practica20.h>
#include <lcd.c>

void main()
{
   lcd_init();
   while(TRUE)
   {
      lcd_gotoxy(5,1);
      printf(lcd_putc,"Hola UACh");
      lcd_gotoxy(7,2);
      printf(lcd_putc,"DIMA");
   }

}
