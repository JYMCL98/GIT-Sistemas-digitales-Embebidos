#include <Practica11.h>
#use standard_io(b)
#define DELAY 400

void main()
{
   set_tris_b(0b00000000);
   
   while(TRUE)
   {
      output_b(0x3F);  // Esta l�nea enciende el display en 0
      delay_ms(DELAY);  // Esperamos 400 ms
      output_b(0x06);  // Esta l�nea enciende el display en 1
      delay_ms(DELAY);  // Esperamos 400 ms
      output_b(0x5B);  // Esta l�nea enciende el display en 2
      delay_ms(DELAY);  // Esperamos 400 ms
      output_b(0x4F);  // Esta l�nea enciende el display en 3
      delay_ms(DELAY);  // Esperamos 400 ms
      output_b(0x66);  // Esta l�nea enciende el display en 4
      delay_ms(DELAY);  // Esperamos 400 ms
      output_b(0x6D);  // Esta l�nea enciende el display en 5
      delay_ms(DELAY);  // Esperamos 400 ms
      output_b(0x7D);  // Esta l�nea enciende el display en 6
      delay_ms(DELAY);  // Esperamos 400 ms
      output_b(0x07);  // Esta l�nea enciende el display en 7
      delay_ms(DELAY);  // Esperamos 400 ms
      output_b(0x7F);  // Esta l�nea enciende el display en 8
      delay_ms(DELAY);  // Esperamos 400 ms
      output_b(0x67);  // Esta l�nea enciende el display en 9
      delay_ms(DELAY);  // Esperamos 400 ms
      
   }

}
