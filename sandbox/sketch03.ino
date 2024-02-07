int availableBytes;
int readByte;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Enter a number from 1 to 10.");
  delay(3000);
  availableBytes = Serial.available();
}

void loop() {
  while ( availableBytes - 1 > 0 ) {
      readByte = Serial.read();
      Serial.print(readByte- '0');
      availableBytes--;
  }
  delay(1000);
  exit(0); 
}
