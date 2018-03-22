#include <MQ135.h>
#define ANALOGPIN A0
void setup() {
  pinMode(ANALOGPIN,INPUT);
  Serial.begin(9600);
}

void loop() {
  MQ135 gasSensor = MQ135(ANALOGPIN);
  float rzero = gasSensor.getRZero();
  Serial.println(rzero);
  delay(1000);
}
