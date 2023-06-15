import serial
import pyodbc
import csv
import time


# Configurar la comunicación serie
ser = serial.Serial('COM6', 9600)  # Ajusta el puerto y la velocidad según corresponda

# # Configuracion de la conexión a la base de datos
# server = 'tcp:data-sensor.database.windows.net'
# database = 'data_sensor'
# username = '{usuario}'
# password = '{*********}'
# driver = '{ODBC Driver 18 for SQL Server}'

# # Driver={ODBC Driver 18 for SQL Server};Server=tcp:data-sensor.database.windows.net,1433;Database=data_sensor;Uid={your_user_name};Pwd={your_password_here};Encrypt=yes;TrustServerCertificate=no;Connection Timeout=30;Authentication=ActiveDirectoryPassword

# conn = pyodbc.connect('DRIVER=' + driver + ';SERVER=' + server + ';PORT=1433;DATABASE=' + database + ';UID=' + username + ';PWD=' + password)

try:
    # Configuración de la conexión a la base de datos
    server = 'tcp:data-sensor.database.windows.net'
    database = 'data_sensor'
    username = '{usuario}'
    password = '{*********}'
    driver = '{ODBC Driver 18 for SQL Server}'

    # Establecer la conexión a la base de datos
    conn = pyodbc.connect('DRIVER=' + driver + ';SERVER=' + server + ';PORT=1433;DATABASE=' + database + ';UID=' + username + ';PWD=' + password)

    cursor = conn.cursor()

    # Imprimir un mensaje si la conexión se estableció correctamente
    print("Conexión exitosa a la base de datos.")

    # Resto del código...

except pyodbc.Error as ex:
    # Imprimir un mensaje si se produce un error al establecer la conexión
    print("Error al establecer la conexión a la base de datos:", ex)

# cursor = conn.cursor()

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
