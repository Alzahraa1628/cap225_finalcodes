int waterdetector1 = A2;
int waterdetector2 = A3;
void setup() {
  pinMode(waterdetector1, INPUT); // Corrected to INPUT for water detectors
  pinMode(waterdetector2, INPUT); // Corrected to INPUT for water detectors
}

void loop() {
  float readingswaterdetector1 = analogRead(waterdetector1);
  float readingswaterdetector2 = analogRead(waterdetector2);
  if (readingswaterdetector1 > 40) {
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(yellow, LOW); 
  } else if (readingswaterdetector2 > 40) {
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    digitalWrite(red, LOW);
  } else {
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
  }
}
