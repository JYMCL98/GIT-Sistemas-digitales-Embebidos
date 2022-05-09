#include <xc.inc>
#include "pic16f84a.inc"

    CONFIG FOSC = XT	;   Seleccionamos el tipo de crystal
    CONFIG WDTE = OFF	;   Deshabilitamos Watchdog
    CONFIG PWRTE = OFF	;   Deshabilitamos la propiedad Power-up
    CONFIG CP = OFF	;   Deshabilitamos la protección de código
    
    ESTATUS EQU 0x03	;   Definimos ESTATUS basado en el datasheet
    PUERTO_B EQU 0x06	;   Definimos la variable PUERTO_B basado en el datasheet
    
    ;Variables necesarias para formar el retardo de 1s
    CONTADOR_A EQU 0x0C	    ;Asignamos de propósito general (datasheet)
    CONTADOR_B EQU 0x0D
    CONTADOR_C EQU 0x0E
 
    PSECT CODE, CLASS=CODE,DELTA=2 ;Declaramos dónde inicia el código
    PSECT CODE 
    
INICIO:
    BSF ESTATUS,5   ;Accedemos al banco, ver datasheet. poner en el registro BSF = 5
    MOVLW 0x00	    ; = 00000000B  Asignamos entradas (1) y salidas (0)
    MOVWF TRISB	    ;Establecer entradas y salidas
    BCF ESTATUS,5   ;Accedemos al banco BCF = 5, ver datasheet
    
PRINCIPAL:
    MOVLW 0xFF	    ; 1111 1111B
    MOVWF PORTB	    ;Movemos los 8 bits al puerto B. Va a encender el puertoB
    CALL RETARDO_1S ;Esperamos 1s
    MOVLW 0x00	    ;0000 0000B ponemos en w 8 bits en 0
    MOVWF PORTB	    ;Movemos los 8 bits al puertoB
    CALL RETARDO_1S ;Esperamos 1s
    GOTO PRINCIPAL
	    ;Generamos el retardo de 1s
RETARDO_1S:
    MOVLW 6
    MOVWF CONTADOR_C
    MOVLW 24
    MOVWF CONTADOR_B
    MOVLW 168
    MOVWF CONTADOR_A
    
    
LOOP:
    DECFSZ CONTADOR_A,1	    ;Decrementar de 1 en 1
    GOTO LOOP
    DECFSZ CONTADOR_B,1
    GOTO LOOP
    DECFSZ CONTADOR_C,1
    GOTO LOOP
    RETURN
END
