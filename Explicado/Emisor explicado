//EMISOR

// Incluyo las librerías de radiofrecuencia y para imprimir en la consola
#include <SPI.h>  

#include <nRF24L01.h> 

#include <printf.h> 

#include <RF24.h> 

#include <RF24_config.h> 

// Defino los pines en los que se transmite la información en variables fijas
#define CE_PIN 7 

#define CSN_PIN 8 

byte canal[6] =("00001"); //Indico el canal en el que se transmite la radiofrecuencia
// Indico los pines donde se introduce la información de la radiofrecuencia
RF24 radio(CE_PIN, CSN_PIN); 

//Defino las variables a usar como enteras
int x; // Variable eje x del segundo joystic
int y; // Variable eje y del segundo joystic
int y1; //Variable del eje y del primer joystic (función de acelerador únicamente en el motor del avión)
int datos[3]; //Declaro el array de tres posiciones de tamaño

void setup(){   // Función que sólo se ejecuta una vez

  radio.begin(); //Se inicia la radiofrecuencia mediante un comando de esa librería

  Serial.begin(9600); //Se inicia el monitor serie

  radio.openWritingPipe(canal); //Se inicia la radio en el canal indicado anteriormente como escritura (emisión)
} 

 

void loop(){ //Ejecutandose en bucle (loop)
  
  y=map(analogRead(0), 0, 1023, 0, 180); //Leer el pin 0 analógico y mapear de 0-180, los grados del servo
  x=map(analogRead(1), 0, 1023, 0, 180); //Leer el pin 1 analógico y mapear de 0-180, los grados del servo
  y1=map(analogRead(2), 0, 1023, 180, 0);//Leer el pin 2 analógico y mapear de 0-180
  datos[0]=x;	//Darle a la posición 0 del array datos el valor de la variable x
  datos[1]=y;   //Darle a la posición 1 del array datos el valor de la variable y
  datos[2]=y1;  //Darle a la posición 2 del array datos el valor de la variable y1
  bool ok = radio.write(&datos, sizeof(datos));   //Enviar por radiofrecuencia el array datos

//Mostrar todas las variables enviadas en el monitor serie
  Serial.println("------");
  Serial.print("0-");
  Serial.println(datos[0]); 
  Serial.print("1-");
  Serial.println(datos[1]);
  Serial.print("2-");
  Serial.println(datos[2]);
  Serial.print("ooooo");
  delay(5); 

 

} 
