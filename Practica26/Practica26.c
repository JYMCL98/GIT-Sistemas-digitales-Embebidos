#include <Practica26.h>
#use standard_io(b)
#use standard_io(c)
#use standard_io(a)
#include <lcd.c>


void main()
{
   set_tris_a(0b11111);
   set_tris_b(0x00);
   set_tris_c(0b00000000);
   lcd_init();
   
   
   while(TRUE)
   {
      //PIN_C0---Enable
      //PIN_C1---1A
      //PIN_C2---2A
      
      //PIN_A0---Control de giro a la derecha
      //PINA_1---Control de giro a la izquierda
      
      output_high(PIN_C2);       // Se factoriza para optimizar el codigo
      
      if(input_state(PIN_A0))
      {
         //output_high(PIN_C0);
         output_low(PIN_C0);
         output_high(PIN_C1);
         lcd_gotoxy(1,1);
         printf(lcd_putc," Motor funcionando");
         lcd_gotoxy(1,2);
         printf(lcd_putc,"Der");
      }
      else if (input_state(PIN_A1))
      {
         //output_high(PIN_C0);
         output_high(PIN_C0);
         output_low(PIN_C1);
         lcd_gotoxy(1,1);
         printf(lcd_putc," Motor funcionando");
         lcd_gotoxy(1,2);
         printf(lcd_putc,"Izq");
      }
      else
      {
         //output_high(PIN_C0);
         output_low(PIN_C0);
         output_low(PIN_C1);
         lcd_gotoxy(1,1);
         printf(lcd_putc," Motor detenido");
         lcd_gotoxy(1,2);
         printf(lcd_putc,":(");
      }
      
   }

}

