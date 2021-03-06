// RECEPTOR
// Incluir las librerías
#include <Servo.h> // Control del servo y del motor
#include <SPI.h> // Librerías de la radiofrecuencia
#include <RF24.h>

// Defino los pines en sus posiciones
#define CE_PIN 7
#define CSN_PIN 8
#define pindata 5

//Canal de la radiofrecuencia
const byte addresses[][6] = {"00001"}; 

// Indico los pines de entrada de la radiofrecuencia
RF24 radio(CE_PIN, CSN_PIN);

// Declaro las variables y el array
int datos[4]; // Declaró el array datos de 4 posiciones para recibir la radiofrecuencia

//Declaro las variables que contengan el pin en el que se encuentran
int motor; // Pin del motor
int servo1; //Pin de un servo de los alerones
int servo2; //Pin de un servo de los alerones
const int pos_0 = 130; // Posición inicial servos

// Indico que los pines indicados anteriormente se aplicarán sobre la librería del servo
Servo Motor;
Servo servo_1;
Servo servo_2;

void setup() //Código que se ejecute sólo una vez
{
  Serial.begin(9600);	//Inicio el monitor serie

  radio.begin();	//Inicio la radio
  radio.openReadingPipe(1, addresses[0]);  //Inicio la función de lectura 1 de la radio en la dirección 
  radio.startListening();		   //Inicio de la radio escuchando (receptor)

Motor.attach(10);			   //Motor en el pin 10
Motor.writeMicroseconds(2000);		   //Microsegundos del motor rango(1000-2000)

servo_1.attach(5);			   //Servo 1 de un alerón en el pin 5
servo_1.write(pos_0);			   //Servo 1 de un alerón se fija a la posición inicial

servo_2.attach(4);			   //Servo 2 de un alerón en el pin 4
servo_2.write(pos_0);			   //Servo 2 de un alerón se fija a la posición inicial

}
void camera() {				   //Declaro la función cámara, que controla la grabación.
      digitalWrite(pindata, HIGH);	   //Activar el pin que enciende la cámara
    pinMode(pindata, INPUT);		   //Hacer el pin 5 (pindata) de lectura
      delay(10000000); 			   // Duración del vídeo
    pinMode(pindata, OUTPUT);		   //Cambiar el modo del pin 5 a salida
      delay(100);
  }
void loop() {				   //Función que se repite en bucle (loop)

radio.read(&datos,sizeof(datos));	  //Lectura del array datos

//Impresión de todos los valores recibidos en el monitor 
  Serial.println("------");
  Serial.print("0-"); // Motor
  Serial.println(datos[0]);
  
  Serial.print("1-"); // Servo (1)
  Serial.println(datos[1]);
  
  Serial.print("2-");
  Serial.println(datos[2]);
  
  Serial.print("3-");
  Serial.println(datos[3]);
  servo1=map(datos[0], 0, 180, 55, 125);	//Mapeo los datos que le voy a pasar a los servos para que sólo se muevan los alerones de 55-125, creando sendas variables para cada servo
  servo2=map(datos[1], 0, 180, 55, 125);
  
  servo_1.write(servo1);			//Introduzco el valor de las variables en los servos
  servo_2.write(servo2);

  motor=map(datos[2], 0, 180, 50, 140);		//Introduzco el valor del joystic del motor con los valores mapeados de 50-140, abarcando todo el rango del motor, del mínimo a máximas revoluciones
  Motor.write(motor);				//Le doy al motor el valor de la variable motor calculada anteriormente
  delay(5);					//5 milisegundos de espera
  if (datos[3]== 0) {				//Si la variable datos en la cuarta posición ha recibido un 0 se activa la cámara
    camera();
  }
}
