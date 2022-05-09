// Universidad Aut�noma Chapingo
// Mecatr�nica Agr�cola
// 6� 7
// Realizado por:
// Jym Emmanuel Cocotle Lara

#include <Tarea2.h>
// Definimos los pines a usar del microcontrolador
#define LCD_RS_PIN      PIN_B1
#define LCD_RW_PIN      PIN_B2
#define LCD_ENABLE_PIN  PIN_B3
#define LCD_DATA4       PIN_B4
#define LCD_DATA5       PIN_B5
#define LCD_DATA6       PIN_B6
#define LCD_DATA7       PIN_B7
// Incluimos la librer�a LCD
#include <lcd.c>
// Habilitamos el puerto B
#use standard_io(b)

// Declaraci�n de variable
int contador = 217;  // Variable a decrementar
int s_1 = 5;  // segundo (decenas)
int s_2 = 5;  // segundo (unidades)
int m_1 = 5;  // minuto (decenas)
int m_2 = 9;  // minuto (unidades)
int h_1 = 1;  // hora (decenas)
int h_2 = 2;  // hora (unidades)


//Caracteres animados
int bomba1[8]={4,4,27,4,4,0,0,0};
int bomba2[8]={0,25,6,0,0,0,0,0};
int bomba3[8]={0,19,12,0,0,0,0,0};
int bomba4[8]={0,6,25,0,0,0,0,0};
int bomba5[8]={0,12,19,0,0,0,0,0};
int bomba6[8]={0,24,4,14,31,31,14,0};
int exp[8]={21,10,21,10,21,10,21,0};


void bomba(){
   // Posici�n con respecto a columna y fila
   lcd_gotoxy(1,1);
   // Mostramos la hora en el LCD
   printf(lcd_putc,"Hora: %d%d:%d%d:%d%d", h_1,h_2,m_1,m_2,s_1,s_2);
   // Posici�n con respecto a columna y fila
   lcd_gotoxy(1,2);
   // Mostramos el estado inicial de la animaci�n
   printf(lcd_putc,"%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0, 1, 2, 3, 4,  1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 5);
   // Creamos un bucle que hace posible la animaci�n
   for(int i=0; i<=16;i++){
      // Posici�n con respecto a columna y fila
      lcd_gotoxy(1,1);
      // Mostramos la hora
      printf(lcd_putc,"Hora: %d%d:%d%d:%d%d", h_1,h_2,m_1,m_2,s_1,s_2);
      // Posici�n con respecto a columna y fila la cual va a variar
      lcd_gotoxy(i,2);
      // animamos la mecha
      printf(lcd_putc," %c",0);
      // Retardo
      delay_ms(200);
      // Establecemos una condici�n en la cual al llegar la mecha a la 
      // posici�n 16 se muestra otra animaci�n
      if (i==16){
         // Posici�n con respecto a columna y fila
         lcd_gotoxy(0,2);
         // mostramos la animaci�n de la explosi�n
         printf(lcd_putc,"%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
         ,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6);
         // Retardo
         delay_ms(200);
      }
   }
}

// Llamado de la funcion de interrupci�n timer 0
#INT_TIMER0
// Interrupci�n interna
void reloj(){
   // Decremento del contador
   contador--;
   // Valor de seteo del timer
   set_timer0(238);
   
   // Si el contador llega a cero, paso un segundo
   if(contador==0){
      // Cuando el contador llega a 0 paso un segundo
      s_2++;
      // Se restablece el contador
      contador=217;
      // Si el segundo de las nidades llega a 10
      if(s_2 == 10) {
         // Se reinicia el valor del segundo de las unidades
         s_2 = 0;
         // Se aumenta el segundo de las decenas
         s_1++;
         // Si el segundo de las decenas es 6, paso un minuto
         if(s_1 == 6){
            // se reestablece el valor de los segundos de las decenas
            s_1 = 0;
            // Aumneta en 1 el valor de las unidades de minuto
            m_2++;
            // si las unidades del minuto llega a 10
            if(m_2 == 10)  {
               // Se reinicia el valor del minuto de unidades
               m_2 = 0;
               // El valor del minuto de las decenas aumenta
               m_1++;
               // si el valor del minuto de las decenas llega a 6,
               // paso una hora
               if(m_1 == 6) {
                  // El minuto de las decenas se reinicia
                  m_1 = 0;
                  // Aumenta una hora (unidades
                  h_2++;
                  // Si la hora de las unidades llega a 10
                  if(h_2 == 10) {
                     // Aumenta en 1 la hora de las decenas
                     h_1++;
                     // Se reinicia el valor de las horas (unidades) 
                     h_2 = 0;
                  }
               }
            }
         }
      }
      // Si estan por dar la 1
      if(h_1 == 1&&h_2==3){
      // Se reinicia a 0 (decenas)
      h_1 = 0;
      // Se pone en 1 (unidades)
      h_2 = 1;
      }
   }
}


void main()
{
   // Inicializamos la lcd en su modo de 8 bits
   lcd_init();
   // Declaramos los caracteres especiales en la memoria
   lcd_set_cgram_char(0,bomba1);
   lcd_set_cgram_char(1,bomba2);
   lcd_set_cgram_char(2,bomba3);
   lcd_set_cgram_char(3,bomba4);
   lcd_set_cgram_char(4,bomba5);
   lcd_set_cgram_char(5,bomba6);
   lcd_set_cgram_char(6,exp);
   
   // Establecemos al puerto B como salidas
   set_tris_b(0x00);
   // Reloj interno del microcontrolador y el preescalador
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_256);
   // Habilitamos las interrupciones de manera interna
   enable_interrupts(INT_TIMER0);
   // Habilitamos todas las interrupciones
   enable_interrupts(GLOBAL);

   while(TRUE)
   {  
      // Mandamos a llamar a la funci�n creada
      bomba();
   }
}
