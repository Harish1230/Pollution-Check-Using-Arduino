void setup() {
  pinMode(A1,INPUT);
  Serial.begin(9600);
}

void loop() {
  int value=analogRead(A0);
  Serial.print(value);
  Serial.println(" ppm");
  /*if(value>=10 && value<=300)
    Serial.println("ammonia is detected");
    Serial.println("alcohol is detected");
  if(value>=10 && value<=1000)
    Serial.println("benzene is detected");
  delay(2000);*/
}
