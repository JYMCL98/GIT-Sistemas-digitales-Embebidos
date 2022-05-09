// Universidad Autónoma Chapingo
//              DIMA
// Ingeniería Mecatrónica Agrícola
//            Equipo 1
//     Integrantes del equipo:
// Alfoso López Hernández
// Antonio Reyes Paredes
// Carlos Euardo Ruíz Diaz
// Jym Emmanuel Cocotle Lara

#include <Tarea3.h>
// Habilitamos el puerto b
#use standard_io(b)
// Habilitamos el puerto c
#use standard_io(c)

// Establecemos una variable de tipo entero y lo igualamos a 0
int contador = 0;
// Establecemos una variable de tipo entero de 16 bits
int16 lectura_ADC;
// Establecemos una variable de tipo entero de 16 bits
int16 millis;

// ClockWise 
// Establecemos el arreglo para el giro en sentido horario
byte const CW[8] = {0b1000, 0b1100, 0b0100, 0b0110,
                    0b0010, 0b0011, 0b0001, 0b1001};
// Counter ClockWise
// Establecemos el arreglo para el giro en sentido antihorario
byte const CCW[8] ={0b1001, 0b0001, 0b0011, 0b0010,
                    0b0110, 0b0100, 0b1100, 0b1000};

// Función que establece el sentido y velocidad del motor
void motor(int contador){
      // Si el botón esta presionado, el motor gira en sentido horario
      if(input_state(PIN_C0)){//CW
         // Paso a la derecha
         output_b(CW[contador]);
      }
      // De lo contrario gira en sentido antihorario
      else{//CCW
         // Paso a la izquierda
         output_b(CCW[contador]);
      }
      // Control de velocidad
      // Al valor del regulador se le resta 1 hasta llegar a 0
      // con un retardo de 1 milisegundo
      while(millis > 0){
         delay_ms(1);
         millis--;
      }
      // Varia dependiendo el equipo por la sobrecarga de la simulación
      delay_ms(400); 
}

void main(){
   // Establecemos la entrada 0 como analógica
   setup_adc_ports(AN0);
   // ADC trabaja con el reloj interno
   setup_adc(ADC_CLOCK_INTERNAL);
   // Establecemos el puerto b como salidas
   set_tris_b(0x00);
   // Establecemos el puerto c0 como entrada
   set_tris_c(0x01);
   while(TRUE)
   {
      // Control de posisión del motor
      // Declaramos  un bucle el cual sirve para leer los arreglos
      // que declaramos anteriormente
      for(contador = 0; contador <= 7; contador++){
         set_adc_channel(0);  // Declaración del pin A0 como ADC
         delay_us(20);        // Retardo de estabilización
         lectura_ADC = read_ADC();  // Lectura del ADC
         // Establecemos la velocidad
         millis = lectura_ADC;  // Relación del ADC con la velocidad
         motor(contador);       // Llamado de la función
      }
   }
}

