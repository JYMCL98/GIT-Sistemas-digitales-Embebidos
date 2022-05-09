import matplotlib.pyplot as plt
import numpy as np
import serial
 
# Variables para construir el array que se va a gráficar
data_size = 10
temperatura = np.zeros(data_size,dtype=np.float32)
muestras =  range(0,data_size)
indice = 0


 
# Configuración de la gráfica
figura = plt.figure()
ax = figura.gca()
ax.set_ylim([0,40])
ax.set_title('Comunicación con la PC y el microcontrolador')
ax.set_xlabel('Tiempo (s)')
ax.set_ylabel('Temperatura (C)')
 
# Habilitamos la comunicación 
puerto_comunicacion = serial.Serial('COM2',baudrate=9600,
                                    timeout=10,parity=serial.PARITY_NONE,
                                    stopbits=serial.STOPBITS_ONE, bytesize=serial.EIGHTBITS)

puerto_comunicacion.write(b"B\n")


plt.ion()
print("La comunicación inicia")
 
try:
    while True:
        datos= puerto_comunicacion.readline()
        if indice<data_size:
            temperatura[indice] = float(datos)
            ax.cla()
            ax.grid(True)
            ax.set_ylim([0,40])
            ax.set_title('Comunicación con la PC y el microcontrolador')
            ax.set_xlabel('Tiempo (s)')
            ax.set_ylabel('Temperatura (C)')
            ax.plot(muestras,temperatura,'b')
            plt.pause(1e-9)
            indice +=1
        else:
            indice=0
except KeyboardInterrupt:
    print("La comunicación finalizo")
finally:
    puerto_comunicacion.close()
    plt.ioff()
    plt.show()
    print("La comunicación finalizo")