char patternCode;
int pin1 = 4; 
int pin2 = 7; 
int pin3 = 8; 
int pin4 = 12; 
int pin5 = 13; 

void setup() {
  Serial.begin(9600);
  
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  
  Serial.println("Welcome to The Light Show!");
  Serial.println("PATTERN OPTIONS");
  Serial.println("CODE \t PATTERN NAME");
  Serial.println("B \t Boogie Woogie");
  Serial.println("C \t Cha Cha");
  Serial.println("W \t Woah");

  Serial.println("Enter pattern code via Serial Monitor.");
  while (Serial.available() == 0) {};
  patternCode = Serial.read();
  Serial.print("You entered: ");
  Serial.println(patternCode);
}

void loop() {
  switch (patternCode) {
    
    case 'B' : {
      
      // boogie woogie [5x]
      int iterations = 5;
      while (iterations > 0) {
        
        // 1, 3, 5 [alternately 4x]
        int count  = 4;
        while (count > 0) {
          digitalWrite(pin1, HIGH);
          delay(600);
          digitalWrite(pin1, LOW);
          delay(600);
          digitalWrite(pin3, HIGH);
          delay(600);
          digitalWrite(pin3, LOW);
          delay(600);
          digitalWrite(pin5, HIGH);
          delay(600);
          digitalWrite(pin5, LOW);
          delay(600);
          count--;
        }

        // 2, 4 [same time 2x]
        count = 2;
        while (count > 0) {
          digitalWrite(pin2, HIGH);
          digitalWrite(pin4, HIGH);
          delay(600);
          digitalWrite(pin2, LOW);
          digitalWrite(pin4, LOW);
          delay(600);
          count--;
        }

        iterations--;
      }
      break;
    }

    case 'C' : {

      // cha cha [5x]
      int iterations = 5;
      while (iterations > 0) {
        
        // 1, 5, 4, 3, 2, 2 [2x]
        int count = 2;
        while (count > 0) {
          digitalWrite(pin1, HIGH);
          delay(600);
          digitalWrite(pin1, LOW);
          delay(600);
          digitalWrite(pin5, HIGH);
          delay(600);
          digitalWrite(pin5, LOW);
          delay(600);
          digitalWrite(pin4, HIGH);
          delay(600);
          digitalWrite(pin4, LOW);
          delay(600);
          digitalWrite(pin3, HIGH);
          delay(600);
          digitalWrite(pin3, LOW);
          delay(600);
          digitalWrite(pin2, HIGH);
          delay(600);
          digitalWrite(pin2, LOW);
          delay(600);
          digitalWrite(pin2, HIGH);
          delay(600);
          digitalWrite(pin2, LOW);
          delay(600);
          count--;
        }
  
        // 1, 2, 3, 4, 5 [same time 2x]
        count = 2;
        while (count > 0) {
          digitalWrite(pin1, HIGH);
          digitalWrite(pin2, HIGH);
          digitalWrite(pin3, HIGH);
          digitalWrite(pin4, HIGH);
          digitalWrite(pin5, HIGH);
          delay(600);
          digitalWrite(pin1, LOW);
          digitalWrite(pin2, LOW);
          digitalWrite(pin3, LOW);
          digitalWrite(pin4, LOW);
          digitalWrite(pin5, LOW);
          delay(600);
          count--;
        }
      }
      break;
    }

    case 'W' : {

      digitalWrite(pin1, HIGH);
      digitalWrite(pin2, HIGH);
      digitalWrite(pin3, HIGH);
      digitalWrite(pin4, HIGH);
      digitalWrite(pin5, HIGH);
      delay(600);
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, LOW);
      digitalWrite(pin4, LOW);
      digitalWrite(pin5, LOW);
      delay(600);
      digitalWrite(pin1, HIGH);
      digitalWrite(pin2, HIGH);
      digitalWrite(pin3, HIGH);
      digitalWrite(pin4, HIGH);
      digitalWrite(pin5, HIGH);
      delay(500);
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, LOW);
      digitalWrite(pin4, LOW);
      digitalWrite(pin5, LOW);
      delay(500);

      digitalWrite(pin1, HIGH);
      digitalWrite(pin2, HIGH);
      digitalWrite(pin3, HIGH);
      digitalWrite(pin4, HIGH);
      digitalWrite(pin5, HIGH);
      delay(100);
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, LOW);
      digitalWrite(pin4, LOW);
      digitalWrite(pin5, LOW);
      delay(100);
      digitalWrite(pin1, HIGH);
      digitalWrite(pin2, HIGH);
      digitalWrite(pin3, HIGH);
      digitalWrite(pin4, HIGH);
      digitalWrite(pin5, HIGH);
      delay(100);
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, LOW);
      digitalWrite(pin4, LOW);
      digitalWrite(pin5, LOW);
      delay(100);
      digitalWrite(pin1, HIGH);
      digitalWrite(pin2, HIGH);
      digitalWrite(pin3, HIGH);
      digitalWrite(pin4, HIGH);
      digitalWrite(pin5, HIGH);
      delay(100);
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, LOW);
      digitalWrite(pin4, LOW);
      digitalWrite(pin5, LOW);
      delay(100);
    }

    default : {
      Serial.println("Invalid Input.");
    }
    break;
   }
  exit(0);
 }
