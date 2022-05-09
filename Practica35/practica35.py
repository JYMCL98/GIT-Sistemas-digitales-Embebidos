import matplotlib.pyplot as plt
import numpy as np
import serial

data_size = 10
temp = np.zeros(data_size,dtype=np.float32)
muestras = range(0,data_size)
indice = 0

fig = plt.figure()
ax = fig.gca()
ax.set_ylim([0,40])
ax.set_title("Comunicación con la PC y el microcontrolador")
ax.set_xlabel("Tiempo (s)")
ax.set_ylabel("Temperatura (C)")

puerto_comunicacion = serial.Serial('COM2',baudrate=9600,timeout=10, 
					  parity=serial.PARITY_NONE,
					  stopbits=serial.STOPBITS_ONE,bytesize=serial.EIGHTBITS)

plt.ion()

print("La comunicacion inicia")
try:
	while True:
		datos=puerto_comunicacion.readline()
		if indice<data_size:
			temp[indice] = float(datos)
			ax.cla()
			ax.grid(True)
			ax.set_ylim([0,40])
			ax.set_title("Comunicación con la PC y el microcontrolador")
			ax.set_xlabel("Tiempo (s)")
			ax.set_ylabel("Temperatura (C)")
			ax.plot(muestras,temp,'b')
			plt.pause(1e-9)
			index +=1
		else:
			indice=0
except:
	print("La comunicacion finalizo")
finally:
	puerto_comunicacion.close()
	plt.ioff()
	plt.show()
	print("La comunicacion finalizo")
