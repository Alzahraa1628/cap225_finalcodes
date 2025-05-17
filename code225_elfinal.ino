const int Turbidity = A1;
int hardness = 0;
int TDS = 0;

int waterdetector1 = A2;
int waterdetector2 = A3;

const int valve = 2;
const int pump = 8;

int red = 5;
 int green = 6;
 int yellow = 7;

void setup() {
  pinMode(Turbidity, INPUT);
  pinMode(valve, OUTPUT);
  pinMode(pump, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(waterdetector1, INPUT);
  pinMode(waterdetector2, INPUT);
  Serial.begin(9600);

  while (!Serial) {
    ; // Wait for Serial to be ready (for Leonardo boards)
  }
  Serial.println("Enter input as: TDS, Hardness");
}


void loop() {
  int sensorValue = analogRead(Turbidity);
  float voltage = sensorValue * (5.0 / 1024.0);
  float ppm = mapFloat(voltage, 2.5, 4.2, 0, 100);

  float readingswaterdetector1 = analogRead(waterdetector1);
  float readingswaterdetector2 = analogRead(waterdetector2);
      // the following code is for hardness and tds 
    if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim(); // Remove any whitespace

    int commaIndex = input.indexOf(',');

       if (commaIndex != -1) {
      String part1 = input.substring(0, commaIndex);
      String part2 = input.substring(commaIndex + 1);

      TDS = part1.toInt();
      hardness = part2.toInt();
         
      Serial.print("The value of hardness:   ");
      Serial.println(hardness);
      Serial.print("The readings of the TDS meter: ");
      Serial.println(TDS);
      Serial.print("Turbidity sensor reading (PPM):");
      Serial.println(ppm, 2);


  
  if (readingswaterdetector1 > 40) {
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(yellow, LOW);

      // You can add behavior here based on input
      if ((hardness <= 45) && (TDS <= 420) && (ppm < 20) ) {
            digitalWrite(valve, HIGH);
            Serial.println("valve ON");
      } else {
        if (hardness > 45){
          Serial.println("Hardness high!");
          Serial.print("The value of hardness:   ");
      Serial.println(hardness);
          }
        else if (TDS > 420){
          Serial.println("TDS high!");
          Serial.print("The readings of the TDS meter: ");
          Serial.println(TDS);
        } 
        else if (ppm > 20){
          Serial.println("Turbidity high!");
          Serial.print("Turbidity (PPM): ");
          Serial.println(ppm, 2);
        } 
        digitalWrite(valve, LOW);
        Serial.println("valve OFF");
        }
    } else {
Serial.println("Invalid input. Use format: TDS,Hardness");    }
  }
  } else if (readingswaterdetector2 > 40) { //the waterdetector is just for the pump
    digitalWrite(pump, HIGH);
    Serial.println("the pump is working...");
    digitalWrite(yellow, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(red, LOW);
  } else {
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(pump, LOW);
  }
  delay(500); 

}
float mapFloat(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}












