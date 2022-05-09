#include <xc.inc>
#include "pic16f84a.inc"
; Etiquetas;	;Codigo de operación	;Campo de operandos datos   ;Comentarios    
    config FOSC = XT	;Seleccion de oscilador
    config WDTE = OFF	;Deshabilitamos el WatchDog
    config PWRTE = OFF;	Deshabilitamos la propiedad Power-up Timer
    config CP = OFF;	Deshabilitamos el codigo de proteccion
    
    estado EQU 0x03	;Definimos la variable estado (ver datasheet)
    puertoB EQU 0x06	;Definimos la variable puertoB (ver datasheet)
 
    contadorA EQU 0x0C	;Definimos la variable contadorA para generar un retardo 1s(Proposito general)
    contadorB EQU 0x0D	;Definimos la variable contadorA para generar un retardo 1s(Proposito general)
    contadorC EQU 0x0E	;Definimos la variable contadorA para generar un retardo 1s(Proposito general)
 
    PSECT Code, class=CODE,delta=2;	Indicamos donde inicia la programacion
    PSECT Code
 
 inicio:
    BCF estado,6
    BSF estado,5
    MOVLW 0xFE	;11111110B (Designo entradas (1) y salidas (0))
    MOVWF TRISB		;Establezco quienes son entradas y salidas
    BCF estado,6
    BSF estado,5
    
    
principal:
    BSF PORTB,0		;Ponemos alto el pin RB0
    CALL Retardo_1s	;Llamamos la subrutina Retardo 1s
    BCF PORTB,0		;Ponemos en bajo el pin RB0
    CALL Retardo_1s	;Llamamos la subrutina Retardo 1s
    GOTO principal
    
Retardo_1s:
    MOVLW 6;	    6,24,168 valores decimales 4MHz = 1s
    MOVWF contadorC
    MOVLW 24
    MOVWF contadorB
    MOVLW 168
    MOVWF contadorA
loop:
    DECFSZ contadorA,1
    GOTO loop
    DECFSZ contadorB,1
    GOTO loop
    DECFSZ contadorC,1
    GOTO loop
    return 
END
