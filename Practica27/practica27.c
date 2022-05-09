#include <practica27.h>
#define LCD_RS_PIN      PIN_B1
#define LCD_RW_PIN      PIN_B2
#define LCD_ENABLE_PIN  PIN_B3
#define LCD_DATA4       PIN_B4
#define LCD_DATA5       PIN_B5
#define LCD_DATA6       PIN_B6
#define LCD_DATA7       PIN_B7
#include <lcd.c>

long cont=0;//contar las interrupciones
int16 valor_ADC=0;
double rpm=0;//valor de rpm

#int_ext//interrupción externa
void ext_isr(){
   cont++; //cont=cont+1
}


void main()
{
   lcd_init();
   // configuramos el ADC
   setup_adc_ports(sAN0);//ALL_ANALOG
   setup_adc(adc_clock_internal);
   
   // configuramos las interrupciones: entra el valor del encoder
   enable_interrupts(int_ext);
   ext_int_edge(L_TO_H);
   enable_interrupts(GLOBAL);
   
   // habilitamos el pwm
   setup_timer_2(T2_DIV_BY_4,249,1);//modo, periodo, postescape
   setup_ccp1(ccp_pwm);
   
   while(TRUE)
   {
      set_adc_channel(0);//
      delay_us(100); //Ta
      valor_ADC = read_adc();
 
      set_pwm1_duty(valor_ADC); //0-1023
      delay_ms(999);
      
      rpm = cont*60/10; //10 ranuras
      cont = 0;
      
      lcd_gotoxy(1,1);
      printf(lcd_putc,"Velocidad");
      lcd_gotoxy(1,2);
      printf(lcd_putc,"RPM: %f",rpm);
      
   }
   

}
