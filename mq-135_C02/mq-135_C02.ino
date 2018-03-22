#include "MQ135.h"
#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 10);
#define ANALOGPIN A0    //  Define Analog PIN on Arduino Board
#define RZERO 206.85    //  Define RZERO Calibration Value
MQ135 gasSensor = MQ135(ANALOGPIN);
String msg;
void setup()
{
  mySerial.begin(9600);
  Serial.begin(9600);
  float rzero = gasSensor.getRZero();
  delay(3000);
  Serial.print("MQ135 RZERO Calibration Value : ");
  Serial.println(rzero);
}

void loop() {
  float ppm = gasSensor.getPPM();
  delay(1000);
  digitalWrite(13,HIGH);
  Serial.print("CO2 ppm value : ");
  Serial.println(ppm);
  if(ppm>300){
    SendMessage("Danger");
    Serial.println("Message sent");
    exit(0);
  }
}

void SendMessage(String msg)
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+917095227840\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println(msg);// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}
