#include <Practica19.h>
#use standard_io(b)

#INT_TIMER0
void timer0_isr()
{
   output_toggle(PIN_B0);
}

void main()
{
   set_tris_b(0x00);
   
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_2);
   set_timer0(0x18);  // 24 en decimal 
   enable_interrupts(INT_TIMER0);
   enable_interrupts(GLOBAL);
   
   while(TRUE)
   {
      
   }

}
