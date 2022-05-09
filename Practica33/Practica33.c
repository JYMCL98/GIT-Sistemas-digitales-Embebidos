#include <Practica33.h>
#define LCD_DATA_PORT getenv("SFR:PORTD")
#define use_portb_kbd TRUE
#include <lcd.c>
#include <kbd.c>
#include <stdlib.h>

#rom 0x2100 = {'1','2','3'}

void main()
{
   lcd_init();
   kbd_init();
   port_b_pullups(TRUE);
   
   char k;
   int i;
   char data[3], clave[3];
   
   while(TRUE)
   {
      i=0;
      printf(lcd_putc,"\fPulsa la tecla 1\n");
      while(i<=2)
      {
         k = kbd_getc();
         if(k!=0)
         {
            data[i]=k;
            i++;
            printf(lcd_putc,"\fPulsa la tecla %u\n",i+1);
         }
      }
      
      for(int j=0; j<=2;j++)
      {
         clave[j]=read_eeprom(j);
      }
      
      if((data[0]==clave[0])&&(data[1]==clave[1])&&(data[2]==clave[2]))
      {
         printf(lcd_putc,"\fCerradura abierta");
         output_high(PIN_A0);
         delay_ms(500);
         output_low(PIN_A0);
      }
      else
      {
         printf(lcd_putc,"\fCerradura cerrada");
         delay_ms(500);
      }
   }
}
