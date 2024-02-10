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
  Serial.println("\nWelcome to Student Fee Viewer!");
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
  Serial.print("You entered: ");
  Serial.println(enteredCode);
  delay(1000);

  // check input (Code)
  switch (enteredCode) {
    case('A'): {
      load = 24;
      normalDiscountPercentage = 0.05;
      scholarshipDiscount = 0;
      break;
    };
    case('B'): {
      load = 26;
      normalDiscountPercentage = 0.06;
      scholarshipDiscount = 5000;
      break;
    };
    case('C'): {
      load = 27;
      normalDiscountPercentage = 0.07;
      scholarshipDiscount = 3000;
      break;
    };
    case('D'): {
      load = 24;
      normalDiscountPercentage = 0;
      scholarshipDiscount = 0;
      break;
    };
    default: {
      Serial.print("Invalid input. Can't show fees.");
    }
  }

  delay(1000);

  Serial.println("\nCalculating Fees... ");
  delay(1000);  

  // calculate estimated fees
  totalFees = (load * COST_PER_UNIT) + MISC_FEES;
  normalDiscount = totalFees - (totalFees * normalDiscountPercentage);
  totalDiscount = normalDiscount + scholarshipDiscount;
  estimatedFees = totalFees - totalDiscount;

  // print status
  Serial.print("\nStatus: ");  
  if (scholarshipDiscount == 0) {
    Serial.print("No Scholarship");
  }
  else {
    Serial.print("With Scholarship");
  }

  // print estimated fees
  Serial.print("\nEstimated Fees: ");  
  Serial.println(estimatedFees);
  delay(1000);
  exit(0);
}