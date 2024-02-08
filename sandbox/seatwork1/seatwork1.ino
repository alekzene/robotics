double estimatedFees;
double totalFees;
double load;
const double MISC_FEES = 3500;
const double COST_PER_UNIT = 1000;
double totalDiscount;
double normalDiscount;
double normalDiscountPercentage;
double scholarshipDiscount;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // print guide
  Serial.println("Welcome to Student Fee Viewer!");
  delay(1000);
  Serial.println("\nCODE \t LOAD (UNITS) \t DISCOUNT");
  Serial.println("A \t 24 \t \t 5%");
  Serial.println("B \t 26 \t \t 6%");
  Serial.println("C \t 27 \t \t 7%");
  Serial.println("D \t 24 \t \t None");
  delay(1000);

  // get user input (Code)
  Serial.println("\nEnter your code in the input field above.");
  while (Serial.available() == 0) {};
  char enteredCode = Serial.read();
  Serial.println("\nYou entered: " + enteredCode);
  delay(1000);

  // calculate fees
  switch (enteredCode) {
    case('A'): {
      load = 24;
      normalDiscountPercentage = 0.05;
      scholarshipDiscount = 0;
    };
    case('B'): {
      load = 26;
      normalDiscountPercentage = 0.06;
      scholarshipDiscount = 5000;
    };
    case('C'): {
      load = 27;
      normalDiscountPercentage = 0.07;
      scholarshipDiscount = 3000;
    };
    case('D'): {
      load = 24;
      normalDiscountPercentage = 0;
      scholarshipDiscount = 0;
    };
    default: {
      Serial.print("Invalid input. Can't show fees.");
    }
  }

  totalFees = (load * COST_PER_UNIT) + MISC_FEES;
  normalDiscount = totalFees - (totalFees * normalDiscountPercentage);
  totalDiscount = normalDiscount + scholarshipDiscount;
  estimatedFees = totalFees - totalDiscount;

  Serial.print("Estimated Fees: ");  
  Serial.print(estimatedFees);
  delay(1000);
  exit(0);
}