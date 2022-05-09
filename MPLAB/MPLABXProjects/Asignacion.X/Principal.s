; Universidad Autónoma Chapingo
; Mecatrónica Agrícola
; Jym Emmanuel Cocotle Lara
; 6° 7
    
    
PROCESSOR 16F84A
#include <xc.inc>
    
    CONFIG FOSC = XT	; Seleccion de oscilador
    CONFIG WDTE = OFF	; Deshabilitamos el WatchDog
    CONFIG PWRTE = OFF	; Deshabilitamos la propiedad Power-up Timer
    CONFIG CP = OFF	; Deshabilitamos el codigo de proteccion
    
    ; Variables necesarias para formar el retardo de ls
    CONTADOR_A EQU 0x0C	; Definimos la variable contador_A para generar un retardo
    CONTADOR_B EQU 0x0D	; Definimos la variable contador_B para generar un retardo 
    CONTADOR_C EQU 0x0E ; Definimos la variable contador_C para generar un retardo

    
    PSECT my_codigo, class=code, delta=2    ; Indicamos donde inicia la programacion
    
my_codigo:
    bsf STATUS, 5   ; Accedemos al banco 1
    movlw 0x1F	    ; 0001 1111 asigno como entradas al puerto A
    movwf TRISA	    ; Mueve la instruccion anterior hacia el puerto A
    movlw 0x00	    ; 0000 0000 asigno las salidas al puerto B
    movwf TRISB	    ; Mueve la instruccion anterior hacia el puerto B
    bcf STATUS,5    ; Accedemos al banco 0

principal:
    movlw 00111111B ; nada,g,f,e,d,c,b,a
    movwf PORTB	    ; Movemos los 8 bits al puerto B
    btfsc PORTA,0   ; Si el botón del pin 0 del puerto A esta oprimido
    goto principal  ; Se ignora esta instrucción
    call retar	    ; Esperamos un retardo
    btfss PORTA,0   ; Si el botón del pin 0 del puerto A no esta oprimido
    goto principal  ; Se ignora esta instrucción
    goto num_1	    ; Nos dirigimos a la subrutina num_1
    
  
num_1:
    movlw 00000110B ; nada,g,f,e,d,c,b,a
    movwf PORTB	    ; Movemos los 8 bits al puerto B
    btfsc PORTA,0   ; Si el botón del pin 0 del puerto A esta oprimido
    goto num_1	    ; Se ignora esta instrucción
    call retar	    ; Esperamos un retardo
    btfss PORTA,0   ; Si el botón del pin A0 no está oprimido
    goto num_1	    ; Está ciclado en el ciclo del número 1
    goto num_2	    ; Nos dirigimos a la subrutina num_2


num_2:
    movlw 01011011B ; nada,g,f,e,d,c,b,a
    movwf PORTB	    ; Movemos los 8 bits al puerto B
    btfsc PORTA,0   ; Si el botón del pin 0 del puerto A esta oprimido
    goto num_2	    ; Se ignora esta instrucción
    call retar	    ; Esperamos un retardo
    btfss PORTA,0   ; Si el botón del pin A0 no está oprimido
    goto num_2	    ; Está ciclado en el ciclo del número 2
    goto num_3	    ; Nos dirigimos a la subrutina num_3
    
    
num_3:
    movlw 01001111B ; nada,g,f,e,d,c,b,a
    movwf PORTB	    ; Movemos los 8 bits al puerto B
    btfsc PORTA,0   ; Si el botón del pin 0 del puerto A esta oprimido
    goto num_3	    ; Se iognora esta instrucción
    call retar	    ; Esperamos un retardo
    btfss PORTA,0   ; Si el botón del pin A0 no está oprimido
    goto num_3	    ; Está ciclado en el ciclo del número 3
    goto num_4	    ; Nos dirigimos a la subrutina num_4
    
num_4:
    movlw 01100110B ; nada,g,f,e,d,c,b,a
    movwf PORTB	    ; Movemos los 8 bits al puerto B
    btfsc PORTA,0   ; Si el botón del pin 0 del puerto A esta oprimido
    goto num_4	    ; Se iognora esta instrucción
    call retar	    ; Esperamos un retardo
    btfss PORTA,0   ; Si el botón del pin A0 no está oprimido
    goto num_4	    ; Está ciclado en el ciclo del número 4
    goto num_5	    ; Nos dirigimos a la subrutina num_5

num_5:
    movlw 01101101B ; nada,g,f,e,d,c,b,a
    movwf PORTB	    ; Movemos los 8 bits al puerto B
    btfsc PORTA,0   ; Si el botón del pin 0 del puerto A esta oprimido
    goto num_5	    ; Se iognora esta instrucción
    call retar	    ; Esperamos un retardo
    btfss PORTA,0   ; Si el botón del pin A0 no está oprimido
    goto num_5	    ; Está ciclado en el ciclo del número 5
    goto num_6	    ; Nos dirigimos a la subrutina num_6
    
num_6:
    movlw 01111101B ; nada,g,f,e,d,c,b,a
    movwf PORTB	    ; Movemos los 8 bits al puerto B
    btfsc PORTA,0   ; Si el botón del pin 0 del puerto A esta oprimido
    goto num_6	    ; Se iognora esta instrucción
    call retar	    ; Esperamos un retardo
    btfss PORTA,0   ; Si el botón del pin A0 no está oprimido
    goto num_6	    ; Está ciclado en el ciclo del número 6
    goto num_7	    ; Nos dirigimos a la subrutina num_7
    
num_7:
    movlw 00000111B ; nada,g,f,e,d,c,b,a
    movwf PORTB	    ; Movemos los 8 bits al puerto B
    btfsc PORTA,0   ; Si el botón del pin 0 del puerto A esta oprimido
    goto num_7	    ; Se iognora esta instrucción
    call retar	    ; Esperamos un retardo
    btfss PORTA,0   ; Si el botón del pin A0 no está oprimido
    goto num_7	    ; Está ciclado en el ciclo del número 7
    goto num_8	    ; Nos dirigimos a la subrutina num_8
    
num_8:
    movlw 01111111B ; nada,g,f,e,d,c,b,a
    movwf PORTB	    ; Movemos los 8 bits al puerto B
    btfsc PORTA,0   ; Si el botón del pin 0 del puerto A esta oprimido
    goto num_8	    ; Se iognora esta instrucción
    call retar	    ; Esperamos un retardo
    btfss PORTA,0   ; Si el botón del pin A0 no está oprimido
    goto num_8	    ; Está ciclado en el ciclo del número 8
    goto num_9	    ; Nos dirigimos a la subrutina num_9

    
num_9:
    movlw 01101111B ; nada,g,f,e,d,c,b,a
    movwf PORTB	    ; Movemos los 8 bits al puerto B
    btfsc PORTA,0   ; Si el botón del pin 0 del puerto A esta oprimido
    goto num_9	    ; Se iognora esta instrucción
    call retar	    ; Esperamos un retardo
    btfss PORTA,0   ; Si el botón del pin A0 no está oprimido
    goto num_9	    ; Está ciclado en el ciclo del número 9
    call principal  ; Nos dirigimos rutina principal

retar:
    MOVLW 2		; Se mueven 2 bits hacia el registro W
    MOVWF CONTADOR_C	; Se mueven los bits hacia la variable CONTADOR_C
    MOVLW 8		; Se mueven 8 bits hacia el registro W
    MOVWF CONTADOR_B	; Se mueven los bits hacia la variable CONTADOR_B
    MOVLW 28		; Se mueven 28 bits hacia el registro W
    MOVWF CONTADOR_A	; Se mueven los bits hacia la variable CONTADOR_A
    
Bucle:
    DECFSZ CONTADOR_A,1 ; Decremento de 1 en 1
    GOTO Bucle		; Creamos el bucle
    DECFSZ CONTADOR_B,1	; Decremento de 1 en 1
    GOTO Bucle		; Creamos el bucle
    DECFSZ CONTADOR_C,1	; Decremento de 1 en 1
    GOTO Bucle		; Creamos el bucle
    RETURN		; Se regresa a donde fue llamado
    
    end my_codigo	; Fin del código
     