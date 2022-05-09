#include <16f877a.h>
#device ADC = 10
#fuses HS,NOWDT,NOPROTECT,NOPUT,NOLVP,BROWNOUT
#use delay(clock=20M)
#use standard_io(D)

#define use_servo_1           // Utiliza el servo 1
#define servo_1 PIN_D0        // Pin del servo 1
#include <servo_st.c>         // Libreria para el manejo de servomotores
#include <map_function.c>     // Libreria para conversiones

void main()
{
   setup_adc_ports(AN0);
   setup_adc(adc_clock_internal);
   servo_init();              // Inicializa el servo
   
   while(true)
   {
      set_adc_channel(0);
      delay_us(2);
      long valor_adc = read_adc();
      int angulo = map(valor_adc, 0, 1023, 0, 180);
      servo_1_write(angulo);
   }
}
