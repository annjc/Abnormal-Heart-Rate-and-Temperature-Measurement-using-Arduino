double alpha=0.75;
double change=0.0;
double minval=0.0;
double Thermister(int RawADC)
{
double Temp;
Temp=log(((10240000/RawADC)-10000));
Temp=1/(0.001129148+(0.000234125+(0.0000000876741*Temp*Temp))*Temp);
Temp=Temp-273.15;
return Temp;
}
void setup() {
Serial.begin(9600);
}

void loop() {
  static double oldValue=0;
  static double oldChange=0;

  int rawValue=analogRead(A1);
  double value=alpha*oldValue+(1-alpha)*rawValue;

  Serial.print(rawValue);
  Serial.print(",");
  Serial.println(value);
  oldValue=value;
  Serial.print(Thermister(analogRead(A0)));
  Serial.println("C");
  if(rawValue>100||value<57)
  {
    Serial.println("Abnormal heartrate!");
  }
  delay(2000);
}
