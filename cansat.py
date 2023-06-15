import serial
import mysql.connector
import csv
import time


# Configurar la comunicación serie
ser = serial.Serial('COM6', 9600)  # Ajusta el puerto y la velocidad según corresponda

# Configuracion de la conexión a la base de datos MySQL
conexion = mysql.connector.connect(
    host = "localhost:3306",
    user = "root",
    password = "0602",
    database = "data_sensor"
)

# Abrir el archivo CSV
csv_file = open('datos_sensor.csv', 'w')
csv_writer = csv.writer(csv_file)


tiempo_inicio = time.time()
# Leer los datos serie y escribirlos en el archivo CSV
while True:
    # Leer una línea de datos del Arduino
    data = ser.readline().decode().strip()  # Decodificar los bytes recibidos a texto

    # Dividir los valores en función del separador utilizado (coma en este caso)
    valores = data.split(',')

    # Escribir los valores en el archivo CSV
    csv_writer.writerow(valores)

    # Mostrar los valores en la consola
    print(data)

    # Detener la captura después de un minuto
    tiempo_actual = time.time()
    tiempo_transcurrido = tiempo_actual - tiempo_inicio
    if tiempo_transcurrido >= 60:
        break

# Cerrar el archivo CSV y la comunicación serie
csv_file.close()
ser.close()