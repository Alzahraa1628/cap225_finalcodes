const int valve = 2;
int turbiditypin = A1;
char receivedChar;

void setup()
{
  pinMode(valve, OUTPUT);
  Serial.begin(9600);
  
}

void loop()
{

  if (sensorValue < 0)
  {
    digitalWrite(valve, LOW);
    Serial.println("valve ON");
  }
  else
  {
    digitalWrite(valve, HIGH);
    Serial.println("valve OFF");
  }
  delay(1000);
}