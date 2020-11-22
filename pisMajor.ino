const int button = 3;
int ledPin = 13;
int LDR = A0;
char serial;
#include <SoftwareSerial.h>
#define BT_SERIAL_RX 11
#define BT_SERIAL_TX 10
SoftwareSerial BluetoothSerial(BT_SERIAL_RX, BT_SERIAL_TX);


void setup(){
  pinMode(ledPin,OUTPUT);
  pinMode(ledPin,OUTPUT);
  pinMode(button,INPUT);
  Serial.begin(9600);
  BluetoothSerial.begin(9600);
  int ldrread = analogRead(LDR);
  Serial.println(ldrread);
  delay(300);
}

void loop(){
  int buttonstate = digitalRead(button);
  if (buttonstate == LOW){
    startprocess();
  }
  else{
    digitalWrite(ledPin,HIGH);
  }
}
void startprocess(){
  int ldrread = analogRead(LDR);
  digitalWrite(ledPin,LOW);
  delay(5000);
  Serial.println((ldrread)*10);
  if (Serial.available() > 0){
    int serial = Serial.read();
  }
  BluetoothSerial.write((serial)*10);
  BluetoothSerial.println((serial)*10);
}
