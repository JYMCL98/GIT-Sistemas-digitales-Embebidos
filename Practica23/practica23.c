#include <practica23.h>
#include <lcd.c> // librería de la lcd


void main()
{
   lcd_init();
   setup_adc_ports(AN0);//puerto analógico A0
   setup_adc(ADC_CLOCK_INTERNAL);//reloj interno
   int16 lectura_ADC;
   float valor_voltaje;
   float valor_corriente;
   float sensibilidad=0.185;
   while(TRUE)
   {
      set_adc_channel(0);
      delay_us(20);//Ta
      lectura_ADC = read_adc();
      valor_voltaje = (5.0*lectura_ADC/65535);
      valor_corriente = (valor_voltaje - 2.5)/sensibilidad;
      
      lcd_gotoxy(1,1); //
      printf(lcd_putc,"ADC = %Lu",lectura_ADC);
      delay_ms(300);
      
      lcd_gotoxy(1,2); //
      printf(lcd_putc,"I = %01.2f A",valor_corriente);
      delay_ms(300);
      
   }

}
