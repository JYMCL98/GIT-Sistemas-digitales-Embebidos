#include <practica28.h>

void main()
{
   // Configuramos el ADC
   setup_adc_ports(sAN0);
   setup_adc(ADC_CLOCK_INTERNAL);
   set_adc_channel(0);
   
   // Configuramos el Timer
   setup_timer_2(T2_DIV_BY_16,255,1);
   setup_ccp1(ccp_pwm);
   
   while(TRUE)
   {
      set_pwm1_duty(read_adc());
      delay_ms(20);
   }

}
