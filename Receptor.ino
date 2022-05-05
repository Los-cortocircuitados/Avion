
// RECEPTOR

#include <Servo.h> 
#include <SPI.h>
#include <RF24.h>

#define CE_PIN 7
#define CSN_PIN 8
#define pindata 5

const byte addresses[][6] = {"00001"}; 

RF24 radio(CE_PIN, CSN_PIN);


int datos[4];
int motor;
int servo1;
int servo2;
const int pos_0 = 130; // Posición inicial servos

Servo Motor;

Servo servo_1;
Servo servo_2;
Servo servo_3;

void setup()
{
  Serial.begin(9600);

  radio.begin();
  radio.openReadingPipe(1, addresses[0]);  
  //radio.openReadingPipe(2, addresses[1]);
  radio.startListening();

Motor.attach(10);
Motor.writeMicroseconds(2000);

servo_1.attach(5);
servo_1.write(pos_0);

servo_2.attach(4);
servo_2.write(pos_0);

}
void camera() {
      digitalWrite(pindata, HIGH);
    pinMode(pindata, INPUT);
      delay(10000000); // Duración del vídeo
    pinMode(pindata, OUTPUT);
      delay(100);
  }
void loop() {

radio.read(&datos,sizeof(datos));

  Serial.println("------");
  Serial.print("0-"); // Motor
  Serial.println(datos[0]);
  
  Serial.print("1-"); // Servo (1)
  Serial.println(datos[1]);
  
  Serial.print("2-");
  Serial.println(datos[2]);
  
  Serial.print("3-");
  Serial.println(datos[3]);
  servo1=map(datos[0], 0, 180, 55, 125);
  servo2=map(datos[1], 0, 180, 55, 125);
  
  servo_1.write(servo1);
  servo_2.write(servo2);

  motor=map(datos[2], 0, 180, 50, 140);
  Motor.write(motor);
  delay(5);
  if (datos[3]== 0) {
    camera();
  }
}
