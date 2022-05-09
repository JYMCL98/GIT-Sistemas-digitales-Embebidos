PROCESSOR 16F84A
#include <xc.inc>

    CONFIG FOSC = XT	;   Seleccionamos el tipo de crystal
    CONFIG WDTE = OFF	;   Deshabilitamos Watchdog
    CONFIG PWRTE = OFF	;   Deshabilitamos la propiedad Power-up
    CONFIG CP = OFF	;   Deshabilitamos la protección de código
    
    PSECT myCodigo, class=code, delta=2

myCodigo:
    BSF STATUS,5;   Accedemos al banco 1
    movlw 0X1F
    MOVWF TRISA
    MOVLW 0X00
    MOVWF TRISB
    BCF STATUS,5
    
principal:
    movlw 00000000B
    movwf PORTB
    btfss PORTA,0	;Si el botón del pin 0 del puerto A no está oprimido
    goto principal	; Está ciclado en el ciclo principal
    goto enciende_led
    
enciende_led:
    movlw 00000001B
    movwf PORTB
    end myCodigo
