PROCESSOR 16F84A
#include <xc.inc>

    CONFIG FOSC = XT	;   Seleccionamos el tipo de crystal
    CONFIG WDTE = OFF	;   Deshabilitamos Watchdog
    CONFIG PWRTE = OFF	;   Deshabilitamos la propiedad Power-up
    CONFIG CP = OFF	;   Deshabilitamos la protección de código
    
    PSECT myCodigo, class=code, delta=2
    
    
myCodigo:
    bsf STATUS,5    ;Accedemos al banco 1
    movlw 0x1F	    ;0001 1111	asigno como ENTRADAS al puerto a
    movwf TRISA	    ;    
    movlw 0x00	    ;0000 0000	asigno como SALIDAS al puerto b    
    movwf TRISB	    ;
    bcf STATUS,5    ;Accedemos al banco 0
    
principal:
    movf PORTA,0
    movwf PORTB
    goto principal
    end myCodigo

    