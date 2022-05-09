#include <practica22.h>
#include <lcd.c>


void main()
{
   lcd_init();
   setup_adc_ports(AN0);
   setup_adc(ADC_CLOCK_INTERNAL);
   int16 lectura_ADC;
   float volt;
   
   while(TRUE)
   {
      set_adc_channel(0);
      delay_us(20);
      lectura_ADC = read_adc();
      
      lcd_gotoxy(1,1);
      printf(lcd_putc,"ADC = %6lu", lectura_ADC);
      delay_ms(100);
      volt = (lectura_ADC*5.0)/65536;
      lcd_gotoxy(1,2);
      printf(lcd_putc,"Volts = %01.2f", volt);
      delay_ms(100);
   }

}
