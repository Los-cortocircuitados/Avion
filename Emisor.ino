//Incluir Librerías

#include <SPI.h>  

#include <nRF24L01.h> 

#include <printf.h> 

#include <RF24.h> 

#include <RF24_config.h> 


//Definir dos pines de la raiofrecuencia
#define CE_PIN 7 

#define CSN_PIN 8 

byte canal[6] =("00001"); 

RF24 radio(CE_PIN, CSN_PIN); //Introduzco la información de los pines de la radiofrecuencia

int x; 

int y;
int y1;
int p;
int datos[4];

void setup(){ 

  radio.begin(); 

  Serial.begin(9600); 

  radio.openWritingPipe(canal); 
  pinMode(2, INPUT);

} 

 

void loop(){ 
  
  y=map(analogRead(0), 0, 1023, 0, 180); 
  x=map(analogRead(1), 0, 1023, 0, 180); 
  y1=map(analogRead(2), 0, 1023, 180, 0);
  datos[0]=x;
  datos[1]=y;
  datos[2]=y1;
  datos[3]=p;
  bool ok = radio.write(&datos, sizeof(datos)); 

  Serial.println("------");
  Serial.print("0-");
  Serial.println(datos[0]); 
  Serial.print("1-");
  Serial.println(datos[1]);
  Serial.print("2-");
  Serial.println(datos[2]);
  Serial.print("ooooo");
  p=digitalRead(2);
  Serial.print(p);
  
 

  delay(5); 

 

} 
