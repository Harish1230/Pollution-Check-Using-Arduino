void setup() {
  pinMode(A1,INPUT);
  Serial.begin(9600);

}

void loop() {
  int al=analogRead(A1);
  float av=0.0048828*al;
  float ap=(2000/5)*av;
  Serial.print(ap);
  Serial.println(" ppm");
  delay(2000);
}
