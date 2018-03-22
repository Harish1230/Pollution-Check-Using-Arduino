int sensorValue;
float voltage;
double LPG_PPM;
double Methane_PPM;
double CO_PPM;
int e=2.7;
void setup() 
{
Serial.begin(9600);
}

void loop() 
{
  Serial.println("-----------------------");
  int sensorValue = analogRead(A0);
  float voltage= sensorValue * (5.0 / 1024.0);
  Serial.println(voltage);
  double LPG_PPM = 26.572*exp(1.2894*23.5); //LPG sensor
  double Methane_PPM = 10.938*exp(1.774*23.5);//Methane sensor
  double CO_PPM = 3.027*exp(1.0698*23.5);//CO sensor
  Serial.print("LPG=");
  Serial.println(LPG_PPM);
  Serial.print("Methane=");
  Serial.println(Methane_PPM);
  Serial.print("CO=");
  Serial.println(CO_PPM);
  delay(1000);  
}

