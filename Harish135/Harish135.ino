int sensorvalue;
float vol;

void setup() 
{
  Serial.begin(9600);
  Serial.println("-------------------");
  Serial.println("Heloo");
}

void loop() 
{
  Serial.println("-----------------");
  sensorvalue = analogRead(A0);
  Serial.println("PPM=");
  Serial.println(sensorvalue);
  delay(1000);
   
}
