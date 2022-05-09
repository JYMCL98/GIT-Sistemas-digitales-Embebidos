#include <Practica29.h>
// Habilitamos los pines para la LCD
#define LCD_ENABLE_PIN  PIN_B3
#define LCD_RS_PIN      PIN_B1
#define LCD_RW_PIN      PIN_B2
#define LCD_DATA4       PIN_B4
#define LCD_DATA5       PIN_B5
#define LCD_DATA6       PIN_B6
#define LCD_DATA7       PIN_B7
#include <lcd.c>

// Declaramos una variable de tipo entero de 16 bits
int16 valor_ADC;
// Declaramos una variable de tipo flotante para referenciar al angulo
float angulo=0;
// Declaramos una variable de tipo flotante 
// para referenciar al valor de entrada que se enviar� al servomotor
float entrada=0;
// Declaramos una variable de tipo flotante 
// como entrada m�xima para este caso 2^10 = 1024
float ent_max = 1023;
// Declaramos una variable de tipo flotante 
// como entrada m�nima con valor igual a 0
float ent_min = 0;
// Declaramos una variable de tipo flotante 
// para el ciclo de trabajo m�ximo
float duty_max = 500;
// Declaramos una variable de tipo flotante 
// para el ciclo de trabajo minimo
float duty_min = 250;
// Declaramos una variable de tipo flotante
// para establecer el valor m�ximo del servomotor
float angulo_max = 180;
// Declaramos una variable de tipo flotante
// para establecer el valor minimo del servomotor
float angulo_min = 0;


void main()
{
   // Inicializamos la LCD
   lcd_init();
   // Configuramos el ADC
   // Configuramos al canal A como salidas anal�gicas
   setup_adc_ports(AN0);
   // Habilitamos el reloj interno del micro
   setup_adc(ADC_CLOCK_INTERNAL);
   // Habilitamos el canal 0
   set_adc_channel(0);
   
   // Configuramos el Timer
   // prescalador, contador, postcalador
   setup_timer_2(T2_DIV_BY_16,255,1);
   // Configuramos al ccp1 como PWM
   setup_ccp1(ccp_pwm);
   
   while(TRUE)
   {
      // Leemos el valor del potenci�metro en A0
      valor_ADC = read_adc();
      
      // Realizamos una interpolaci�n para obtener el valor de la entrada
      // para enviar al servomotor
      entrada = (duty_min) + ((duty_max - duty_min)
               /(ent_max - ent_min))*(valor_ADC - ent_min);
      // Realizamos una interpolaci�n para obtener el valor del �ngulo
      // que se mostrar� en la LCD
      angulo = (angulo_min) + ((angulo_max - angulo_min)
               /(ent_max - ent_min))*(valor_ADC - ent_min);
      
      // Convertimos la variable de entrada a un entero de 16 bits
      // y mandamos el valor al servomotor para que gire
      set_pwm1_duty((int16)entrada);
      // Esperamos 20 milisegundos
      delay_ms(20);
      
      // Posici�n con respecto a columna y fila
      lcd_gotoxy(1,1);
      // Imprimimos un texto en la LCD
      printf(lcd_putc," Posicion");
      // Posici�n con respecto a columna y fila
      lcd_gotoxy(1,2);
      // Imprimimos los grados en los que se encuentra el servo
      printf(lcd_putc," %f Grados",angulo);
      
   }

}
