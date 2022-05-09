#include <xc.inc>
#include <pic16f84a.inc>
    
    CONFIG FOSC = XT	; Seleccionamos el tipo de crystal
    CONFIG WDTE = OFF	; Dehabilitamos el Watchdog
    CONFIG PWRTE = OFF	; Deshabilitamos la propiedad Power-up
    CONFIG CP = OFF	; Deshabilitamos la proteccion de código
    
    ESTATUS EQU 0x03	; Definimos la variable estatus basado en el Datasheet
    PUERTO_B EQU 0x06	; Definimos la variable puerto_b basado en el Datasheet
    
    ; Variables necesarias para formar el retardo de ls
    CONTADOR_A EQU 0x0C
    CONTADOR_B EQU 0x0D
    CONTADOR_C EQU 0x0E
    
    PSECT CODE, CLASS=CODE,DELTA=2 ; Indicamos donde inicia el código
    PSECT CODE
 
INICIO:
    BSF ESTATUS,5   ; Accedemos al Banco 1 (Ver Datasheet)
    MOVLW 0x00	    ; Asignamos entradas (1) y salidas (0)
    MOVWF TRISB	    ; Establecer entradas/salidas
    BCF ESTATUS,5   ; Accedemos al Banco 0 (Ver Datasheet)
    
PRINCIPAL:
    MOVLW 10000001B	
    MOVWF PORTB		; Movemos los 8 bits al puerto B
    CALL RETARDO_1S	; Esperamos menos de 1 segundo
    MOVLW 11000011B	
    MOVWF PORTB		; Movemos los 8 bits al puerto B
    CALL RETARDO_1S	; Esperamos menos de 1 segundo
    MOVLW 11100111B	
    MOVWF PORTB		; Movemos los 8 bits al puerto B
    CALL RETARDO_1S	; Esperamos menos de 1 segundo
    MOVLW 11111111B	
    MOVWF PORTB		; Movemos los 8 bits al puerto B
    CALL RETARDO_1S	; Esperamos menos de 1 segundo
    
    MOVLW 00011000B	
    MOVWF PORTB		; Movemos los 8 bits al puerto B
    CALL RETARDO_1S	; Esperamos menos de 1 segundo
    MOVLW 00111100B	
    MOVWF PORTB		; Movemos los 8 bits al puerto B
    CALL RETARDO_1S	; Esperamos menos de 1 segundo
    MOVLW 01111110B	
    MOVWF PORTB		; Movemos los 8 bits al puerto B
    CALL RETARDO_1S	; Esperamos menos de 1 segundo
    MOVLW 11111111B	
    MOVWF PORTB		; Movemos los 8 bits al puerto B
    CALL RETARDO_1S	; Esperamos menos de 1 segundo
    
    
    GOTO PRINCIPAL
    
RETARDO_1S:
    MOVLW 2
    MOVWF CONTADOR_C
    MOVLW 8
    MOVWF CONTADOR_B
    MOVLW 56
    MOVWF CONTADOR_A
LOOP:
    DECFSZ CONTADOR_A,1 ;Decremento de 1 en 1
    GOTO LOOP
    DECFSZ CONTADOR_B,1
    GOTO LOOP
    DECFSZ CONTADOR_C,1
    GOTO LOOP
    RETURN
END
    