#include <xc.inc>   ;Incluimos la librería de default del compilador
#include "pic16f84a.inc"    ;PROCESSOR 16F84A

    CONFIG FOSC = XT	;   Seleccionamos el tipo de crystal
    CONFIG WDTE = OFF	;   Deshabilitamos Watchdog
    CONFIG PWRTE = OFF	;   Deshabilitamos la propiedad Power-up
    CONFIG CP = OFF	;   Deshabilitamos la protección de código
    
    ESTATUS EQU 0x03	;   Definimos ESTATUS basado en el datasheet,registro STATUS
    PUERTO_B EQU 0x06	;   Definimos la variable PUERTO_B basado en el datasheet, registro
    
    ;Variables necesarias para formar el retardo de 1s
    CONTADOR_A EQU 0x0C	    ;Asignamos de propósito general (datasheet)
    CONTADOR_B EQU 0x0D
    CONTADOR_C EQU 0x0E
 
    PSECT CODE, CLASS=CODE,DELTA=2 ;Declaramos dónde inicia el código
    PSECT CODE 
		    ;PSECT myCodigo
INICIO:		    ;Etiqueta que indica donde inicia la programacion,registro STATUS
    BSF ESTATUS,5   ;BitsetFile, Accedemos al banco 1,bit5, ver datasheet. poner en el registroBSF = 5
    MOVLW 0x00	    ; = 00000000B  Asignamos entradas (1) y salidas (0),registro W,0x00 hexadecimal
    MOVWF TRISB	    ;Establecer entradas y salidas,registro F
    BCF ESTATUS,5   ;Accedemos al banco BCF = 5, ver datasheet,bitclearfile, regresamos al banco 5

PRINCIPAL:
    MOVLW 10000001B ;RB7=1 RB6=0 RB5=0 RB4=0 RB3=0 RB2=0 RB1=0 RB0=1
    MOVWF PORTB	    ;Mover registro W hacia el PORTB
    CALL RETARDO_1S ;Esperamos 1s
    MOVLW 11000011B;
    MOVWF PORTB;
    CALL RETARDO_1S ;Esperamos 1s, call para subrutinas y goto para saltos
    MOVLW 11100111B;
    MOVWF PORTB;
    CALL RETARDO_1S ;Esperamos 1s
    MOVLW 11111111B;
    MOVWF PORTB;
    CALL RETARDO_1S ;Esperamos 1s
    
    MOVLW 00011000B;
    MOVWF PORTB;
    CALL RETARDO_1S ;Esperamos 1s  
    MOVLW 00111100B;
    MOVWF PORTB;
    CALL RETARDO_1S ;Esperamos 1s
    MOVLW 01111110B;
    MOVWF PORTB;
    CALL RETARDO_1S ;Esperamos 1s
    MOVLW 11111111B;
    MOVWF PORTB;
    CALL RETARDO_1S ;Esperamos 1s
    GOTO PRINCIPAL  ;Aquí termina el principal (se repita infinitamente)
		    ;Generamos el retardo de 0.5s
RETARDO_1S:	    ;Iniciamos una subrutina
    MOVLW 3
    MOVWF CONTADOR_C
    MOVLW 12
    MOVWF CONTADOR_B
    MOVLW 84
    MOVWF CONTADOR_A
    	
    
LOOP:
    DECFSZ CONTADOR_A,1	    ;Decrementar de 1 en 1,Decrementar, cambia por el tipo de crystal
    GOTO LOOP	;
    DECFSZ CONTADOR_B,1
    GOTO LOOP
    DECFSZ CONTADOR_C,1
    GOTO LOOP
    RETURN  ; RETURN: Se sale de la subrutina
END
