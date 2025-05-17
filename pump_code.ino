const int pump = 8;
int waterdetector2 = A3;

void setup() {
  pinMode(pump, OUTPUT);
}

void loop() {
  if(waterdetector2 > 40){
    digialWrite(pump, HIGH);
    Serial.println("the pump is working");
  } else{
    digialWrite(pump, LOW);
    Serial.println("the pump is working");
  }
}
