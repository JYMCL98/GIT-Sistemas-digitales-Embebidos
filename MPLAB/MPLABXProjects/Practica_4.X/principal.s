    PROCESSOR 16F84A
    #include <xc.inc>
    
    CONFIG FOSC =XT
    CONFIG WDTE = OFF
    CONFIG PWRTE = OFF
    CONFIG CP = OFF
    
    PSECT my_codigo, class=code, delta=2
    
my_codigo:
    bsf STATUS,5    ; Accedemos al banco 1
    movlw 0x1F	    ; 0001 1111 asigno como entradas al puerto a
    movwf TRISA
    movlw 0x00	    ; 0000 0000 asigno las salidas al puerto b
    movwf TRISB
    bcf STATUS,5    ; Accedemos al banco 0
    
principal:
    movf PORTA,0
    movwf PORTB
    goto principal
    end my_codigo