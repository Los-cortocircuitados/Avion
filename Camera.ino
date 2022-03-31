
#define pindata 3
#define pinbutton A0

void mainmenu() {

Serial.begin(9600);

Serial.println("========================================");
Serial.println("           Camera CCTV -- FUZZ          ");
Serial.println("========================================");
Serial.println("");
Serial.println("               MAIN MENU                ");
Serial.println("");
Serial.println("Select mode:");
Serial.println("");
Serial.println("1. Auto");
Serial.println("2. Take a video");
Serial.println("3. Take a photo");

}
void spaces() {
  
    Serial.println("");
    Serial.println("");
    Serial.println("");
    Serial.println("");
    Serial.println("");
    Serial.println("");
    Serial.println("");
    Serial.println("");
    Serial.println("");
    Serial.println("");
    Serial.println("");
    Serial.println("");
    Serial.println("");
    Serial.println("");
    Serial.println("");
    
}


void setup() {
mainmenu();
pinMode(pindata, OUTPUT);

}

void loop() {

int option = (Serial.read()- 48);

switch (option) {
  case 1:
    spaces();
    Serial.println("You have selected 'Auto'");
    for(int i = 0; i >= 0; i++) {
      Serial.print("Injecting payload: ");
      Serial.print("");
        Serial.print(i);
      Serial.print("       ");
       Serial.print("(");
       Serial.print(5 * i / 1024);
       Serial.println(")");
      analogWrite(pindata, i);
      delay(500);
    }
    
      break;
  case 2:
    spaces();
    Serial.println("You have selected 'Take a video'");
    Serial.println("");
    Serial.print("Inyecting payload: ");
    digitalWrite(pindata, HIGH);
    pinMode(pindata, INPUT);
      delay(10000); // Duración del vídeo
    pinMode(pindata, OUTPUT);
      delay(100);
    pinMode(pindata, INPUT);

    break;
  case 3:
    spaces();
    Serial.println("You have selected 'Take a photo'");
    Serial.println("");
    Serial.print("Inyecting payload: ");
    digitalWrite(pindata, HIGH);
    pinMode(pindata, INPUT);
      delay(1);
    pinMode(pindata, OUTPUT);
      delay(100);

    break;
  
}
}
