const int sensorPin = A1;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  float voltage = sensorValue * (5.0 / 1024.0);

  // Map voltage to NTU/PPM (max 100)
  float ppm = mapFloat(voltage, 2.5, 4.2, 0, 100);
  if (ppm < 0) ppm = 0;
  if (ppm > 100) ppm = 100;

  Serial.print("Voltage: ");
  Serial.print(voltage, 2);
  Serial.print(" V | PPM (estimated): ");
  Serial.println(ppm, 2);

  delay(1000);
}

float mapFloat(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
