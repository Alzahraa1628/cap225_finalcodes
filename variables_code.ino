int hardness = 0;
int TDS = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // Wait for Serial to be ready (for Leonardo boards)
  }
  Serial.println("Enter input as: TDS, Hardness");
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim(); // Remove any whitespace

    int commaIndex = input.indexOf(',');

       if (commaIndex != -1) {
      String part1 = input.substring(0, commaIndex);
      String part2 = input.substring(commaIndex + 1);

      TDS = part1.toInt(); // ✅ استخدام toInt() لتحويل String إلى int
      hardness = part2.toInt();
         
      Serial.print("The value of hardness:   ");
      Serial.println(hardness);
      Serial.print("The readings of the TDS meter: ");
      Serial.println(TDS);

      // You can add behavior here based on input
      if ((hardness <= 45) && (TDS <= 420)) {
        Serial.println("the valve open");
      } else {
        Serial.println("the valve still close");
      }
    } else {
      Serial.println("Invalid input. Use format: color,number");
    }
  }
}
