#include <pratica35.h>
#include <lcd.c>
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7, bits=8, stop=1, parity=n)
char valor;


void main()
{
   lcd_init();
   
   setup_adc_ports(AN0);
   setup_adc(ADC_CLOCK_INTERNAL);
   set_adc_channel(0);
   
   int16 valor_ADC;
   float temperatura;
   
   while(TRUE)
   {
      valor = getc();
      delay_ms(20);
      printf("%C",valor);
      
      
      valor_ADC=read_adc();
      temperatura=valor_ADC/2;
      lcd_gotoxy(1,1);
      printf(lcd_putc,"Valor ADC %4ld",valor_ADC);
      lcd_gotoxy(1,2);
      printf(lcd_putc,"Temperatura %01.2f",temperatura);
      
      printf("%01.2f\n\r",temperatura);
   }
}
