PROCESSOR 16F84A
#include <xc.inc>
    
    CONFIG FOSC = XT
    CONFIG WDTE = OFF
    CONFIG PWRTE = OFF
    CONFIG CP = OFF
    
    CONTADOR EQU 0X0C
    
    PSECT my_codigo, class=code, delta=2
    
my_codigo:
    bsf STATUS, 5
    movlw 0x1F
    movwf TRISA
    movlw 0x00
    movwf TRISB
    bcf STATUS,5

principal:
    movlw 00111111B  ; nada,g,f,e,d,c,b,a
    movwf PORTB
    btfss PORTA,0   ; Si el botón del pin 0 del puerto A no esta oprimido
    goto num_1
    goto principal  ; Esta ciclado en el ciclo principal
    call ini_cont
    

ini_cont:
    INCFSZ CONTADOR,1
    goto ini_cont
    
  
num_1:
    movlw 00000110B  ; nada,g,f,e,d,c,b,a
    movwf PORTB
    btfss PORTA,0   ; Si el botón del pin 0 del puerto A no esta oprimido
    goto num_1
    goto num_2  ; Esta ciclado en el ciclo principal
    call ini_cont

num_2:
    movlw 01011011B  ; nada,g,f,e,d,c,b,a
    movwf PORTB
    btfss PORTA,0   ; Si el botón del pin 0 del puerto A no esta oprimido
    goto num_2
    goto num_3  ; Esta ciclado en el ciclo principal
    
num_3:
    movlw 01001111B  ; nada,g,f,e,d,c,b,a
    movwf PORTB
    goto num_3
    
num_4:
    movlw 01100110B  ; nada,g,f,e,d,c,b,a
    movwf PORTB
    goto num_4

num_5:
    movlw 01101101B  ; nada,g,f,e,d,c,b,a
    movwf PORTB
    goto num_5
    
num_6:
    movlw 01111101B  ; nada,g,f,e,d,c,b,a
    movwf PORTB
    
num_7:
    movlw 00000111B  ; nada,g,f,e,d,c,b,a
    movwf PORTB
    
num_8:
    movlw 01111111B  ; nada,g,f,e,d,c,b,a
    movwf PORTB

    
num_9:
    movlw 01101111B  ; nada,g,f,e,d,c,b,a
    movwf PORTB
    
    
    end my_codigo