#include <16f877a.h>
#fuses HS,NOWDT,NOPROTECT,NOPUT,NOLVP,BROWNOUT
#use delay(clock=20M)
#use standard_io(D)

#define use_servo_1           // Utiliza el servo 1
#define servo_1 PIN_D0        // Pin del servo 1
#include <servo_st.c>         // Libreria para el manejo de servomotores

void main()
{
   servo_init();              // Inicializa el servo
   
   while(true)
   {
      servo_1_write(0);       // 0�
      delay_ms(1000);
      
      servo_1_write(90);      // 90�
      delay_ms(1000);
      
      servo_1_write(180);     // 180�
      delay_ms(1000);
   }
}
