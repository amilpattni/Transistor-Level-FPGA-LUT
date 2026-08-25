int WL1 = 7;
int WL2 = 6;
int WL3 = 5;
int WL4 = 4;
int BL = 9;
int BLB = 8;
const int Q1 = A0;
const int Q2 = A1;
const int Q3 = A2;
const int Q4 = A3;
int q1, q2, q3, q4;

const int LEDQ1 = 10;
const int LEDQ2 = 11;
const int LEDQ3 = 12;
const int LEDQ4 = 13;

int a = 3;
int b = 2;
int c = 1;

const int buttonPin = A4;
int setting = -1;
bool lastButtonState = HIGH;
bool buttonState = HIGH;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;
bool newSetting = true;


const int abButtonPin = A5;

int abSetting = -1;
bool lastABButtonState = HIGH;
bool abButtonState = HIGH;
unsigned long lastABDebounceTime = 0;
const unsigned long abDebounceDelay = 50;


void setup() {
  pinMode(abButtonPin, INPUT_PULLUP);
  pinMode(buttonPin, INPUT_PULLUP);
  //Serial.begin(9600);
  //Serial.println(" ");
  //Serial.print("Current setting: ");
  //Serial.println(setting);

  pinMode(Q1, INPUT);
  pinMode(Q2, INPUT);
  pinMode(Q3, INPUT);
  pinMode(Q4, INPUT);
  pinMode(LEDQ1, OUTPUT);
  pinMode(LEDQ2, OUTPUT);
  pinMode(LEDQ3, OUTPUT);
  pinMode(LEDQ4, OUTPUT);
  pinMode(BL, OUTPUT);
  pinMode(BLB, OUTPUT);
  pinMode(WL1, OUTPUT);
  pinMode(WL2, OUTPUT);
  pinMode(WL3, OUTPUT);
  pinMode(WL4, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);

  digitalWrite(WL1, 0);
  digitalWrite(WL2, 0);
  digitalWrite(WL3, 0);
  digitalWrite(WL4, 0);
  digitalWrite(BL, 0);
  digitalWrite(BLB, 1);

  digitalWrite(LEDQ1, 0);
  digitalWrite(LEDQ2, 0);
  digitalWrite(LEDQ3, 0);
  digitalWrite(LEDQ4, 0);
  digitalWrite(a, 0);
  digitalWrite(b, 0);
  digitalWrite(c, 0);

  setAB();
}

void loop() {
  bool reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == LOW) {
        setting++;
        if (setting > 6) {
          setting = 0;
        }

        newSetting = true;

        //Serial.print("Current setting: ");
        //Serial.println(setting);
      }
    }
  }
  lastButtonState = reading;

  
  bool abReading = digitalRead(abButtonPin);

  if (abReading != lastABButtonState) {
    lastABDebounceTime = millis();
  }

  if ((millis() - lastABDebounceTime) > abDebounceDelay) {
    if (abReading != abButtonState) {
      abButtonState = abReading;

      if (abButtonState == LOW) {
        abSetting++;
        if (abSetting > 3) {
          abSetting = 0;
        }

        
        newSetting = true;

        //Serial.print("AB setting: ");
        //Serial.println(abSetting + 1);
        setAB();
      }
    }
  }

  lastABButtonState = abReading;


  if (setting == 0) {AND();} else if (setting == 1) {OR();} else if (setting == 2) {NOT();} else if (setting == 3) {NAND();} else if (setting == 4) {NOR();} else if (setting == 5) {XOR();} else if (setting == 6) {XNOR();} 
  newSetting = false;
}
//AND - OR - NOT - NAND - NOR - XOR - XNOR
void AND() {
  if (newSetting) {
    ////Serial.println("AND");

    digitalWrite(BL, 0);
    digitalWrite(BLB, 1);
    delay(10);
    digitalWrite(WL1, 1);
    digitalWrite(WL2, 1);
    digitalWrite(WL3, 1);
    digitalWrite(WL4, 1);
    delay(10);
    digitalWrite(WL1, 0);
    digitalWrite(WL2, 0);
    digitalWrite(WL3, 0);
    digitalWrite(WL4, 0);
    delay(10);

    digitalWrite(BL, 1);
    digitalWrite(BLB, 0);
    delay(10);
    digitalWrite(WL4, 1);
    delay(10);
    digitalWrite(WL1, 0);
    digitalWrite(WL2, 0);
    digitalWrite(WL3, 0);
    digitalWrite(WL4, 0);
    delay(10);
    readLatch("AND");
  }
  delay(50);
}

void OR() {
  if (newSetting) {
    ////Serial.println("OR");
    
    digitalWrite(BL, 0);
    digitalWrite(BLB, 1);
    delay(10);
    digitalWrite(WL1, 1);
    digitalWrite(WL2, 1);
    digitalWrite(WL3, 1);
    digitalWrite(WL4, 1);
    delay(10);
    digitalWrite(WL1, 0);
    digitalWrite(WL2, 0);
    digitalWrite(WL3, 0);
    digitalWrite(WL4, 0);
    delay(10);
    
    digitalWrite(BL, 1);
    digitalWrite(BLB, 0);
    delay(10);
    digitalWrite(WL2, 1);
    digitalWrite(WL3, 1);
    digitalWrite(WL4, 1);
    delay(10);
    digitalWrite(WL1, 0);
    digitalWrite(WL2, 0);
    digitalWrite(WL3, 0);
    digitalWrite(WL4, 0);
    delay(10);
    readLatch("OR");
  }
  delay(50);
}

void NOT() {
  if (newSetting) {
    ////Serial.println("NOT");

    digitalWrite(BL, 0);
    digitalWrite(BLB, 1);
    delay(10);
    digitalWrite(WL1, 1);
    digitalWrite(WL2, 1);
    digitalWrite(WL3, 1);
    digitalWrite(WL4, 1);
    delay(10);
    digitalWrite(WL1, 0);
    digitalWrite(WL2, 0);
    digitalWrite(WL3, 0);
    digitalWrite(WL4, 0);
    delay(10);
    
    digitalWrite(BL, 1);
    digitalWrite(BLB, 0);
    delay(10);
    digitalWrite(WL2, 1);
    delay(10);
    digitalWrite(WL1, 0);
    digitalWrite(WL2, 0);
    digitalWrite(WL3, 0);
    digitalWrite(WL4, 0);
    delay(10);
    readLatch("NOT");
  }
  delay(50);
}

void NAND() {
  if (newSetting) {
    ////Serial.println("NAND");

    digitalWrite(BL, 0);
    digitalWrite(BLB, 1);
    delay(10);
    digitalWrite(WL1, 1);
    digitalWrite(WL2, 1);
    digitalWrite(WL3, 1);
    digitalWrite(WL4, 1);
    delay(10);
    digitalWrite(WL1, 0);
    digitalWrite(WL2, 0);
    digitalWrite(WL3, 0);
    digitalWrite(WL4, 0);
    delay(10);
    
    digitalWrite(BL, 1);
    digitalWrite(BLB, 0);
    delay(10);
    digitalWrite(WL1, 1);
    digitalWrite(WL2, 1);
    digitalWrite(WL3, 1);
    delay(10);
    digitalWrite(WL1, 0);
    digitalWrite(WL2, 0);
    digitalWrite(WL3, 0);
    digitalWrite(WL4, 0);
    delay(10);
    readLatch("NAND");
  }
  delay(50);
}

void NOR() {
  if (newSetting) {
    ////Serial.println("NOR");

    digitalWrite(BL, 0);
    digitalWrite(BLB, 1);
    delay(10);
    digitalWrite(WL1, 1);
    digitalWrite(WL2, 1);
    digitalWrite(WL3, 1);
    digitalWrite(WL4, 1);
    delay(10);
    digitalWrite(WL1, 0);
    digitalWrite(WL2, 0);
    digitalWrite(WL3, 0);
    digitalWrite(WL4, 0);
    delay(10);
    
    digitalWrite(BL, 1);
    digitalWrite(BLB, 0);
    delay(10);
    digitalWrite(WL1, 1);
    delay(10);
    digitalWrite(WL1, 0);
    digitalWrite(WL2, 0);
    digitalWrite(WL3, 0);
    digitalWrite(WL4, 0);
    delay(10);
    readLatch("NOR");
  }
  delay(50);
}

void XOR() {
  if (newSetting) {
    ////Serial.println("XOR");

    digitalWrite(BL, 0);
    digitalWrite(BLB, 1);
    delay(10);
    digitalWrite(WL1, 1);
    digitalWrite(WL2, 1);
    digitalWrite(WL3, 1);
    digitalWrite(WL4, 1);
    delay(10);
    digitalWrite(WL1, 0);
    digitalWrite(WL2, 0);
    digitalWrite(WL3, 0);
    digitalWrite(WL4, 0);
    delay(10);
    
    digitalWrite(BL, 1);
    digitalWrite(BLB, 0);
    delay(10);
    digitalWrite(WL2, 1);
    digitalWrite(WL3, 1);
    delay(10);
    digitalWrite(WL1, 0);
    digitalWrite(WL2, 0);
    digitalWrite(WL3, 0);
    digitalWrite(WL4, 0);
    delay(10);
    readLatch("XOR");
  }
  delay(50);
}

void XNOR() {
  if (newSetting) {
    ////Serial.println("XNOR");

    digitalWrite(BL, 0);
    digitalWrite(BLB, 1);
    delay(10);
    digitalWrite(WL1, 1);
    digitalWrite(WL2, 1);
    digitalWrite(WL3, 1);
    digitalWrite(WL4, 1);
    delay(10);
    digitalWrite(WL1, 0);
    digitalWrite(WL2, 0);
    digitalWrite(WL3, 0);
    digitalWrite(WL4, 0);
    delay(10);
    
    digitalWrite(BL, 1);
    digitalWrite(BLB, 0);
    delay(10);
    digitalWrite(WL1, 1);
    digitalWrite(WL4, 1);
    delay(10);
    digitalWrite(WL1, 0);
    digitalWrite(WL2, 0);
    digitalWrite(WL3, 0);
    digitalWrite(WL4, 0);
    delay(10);
    readLatch("XNOR");
  }
  delay(50);
}

void readLatch(const char* label){

  if (analogRead(Q1) > 600){q1=1;}else{q1=0;}
  if (analogRead(Q2) > 600){q2=1;}else{q2=0;}
  if (analogRead(Q3) > 600){q3=1;}else{q3=0;}
  if (analogRead(Q4) > 600){q4=1;}else{q4=0;}

  //Serial.println(label);
  //Serial.print("  Q1=");
  //Serial.println(q1);

  //Serial.print("  Q2=");
  //Serial.println(q2);

  //Serial.print("  Q3=");
  //Serial.println(q3);

  //Serial.print("  Q4=");
  //Serial.println(q4);
    

  showLED();
}

void showLED(){
  if (q1 == 1){digitalWrite(LEDQ1, 1);}else{digitalWrite(LEDQ1, 0);}
  if (q2 == 1){digitalWrite(LEDQ2, 1);}else{digitalWrite(LEDQ2, 0);}
  if (q3 == 1){digitalWrite(LEDQ3, 1);}else{digitalWrite(LEDQ3, 0);}
  if (q4 == 1){digitalWrite(LEDQ4, 1);}else{digitalWrite(LEDQ4, 0);}
}

void setAB() {
  if (abSetting == 0) {
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    //Serial.println("a=0 b=0");
  }
  else if (abSetting == 1) {
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    //Serial.println("a=0 b=1");
  }
  else if (abSetting == 2) {
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    //Serial.println("a=1 b=0");
  }
  else if (abSetting == 3) {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    //Serial.println("a=1 b=1");
  }
  outputMUX();
}

void outputMUX(){
  if (abSetting == 0) {
    if (q1 == 1){digitalWrite(c, 1);}else{digitalWrite(c, 0);}
  }
  else if (abSetting == 1) {
    if (q2 == 1){digitalWrite(c, 1);}else{digitalWrite(c, 0);}
  }
  else if (abSetting == 2) {
    if (q3 == 1){digitalWrite(c, 1);}else{digitalWrite(c, 0);}
  }
  else if (abSetting == 3) {
    if (q4 == 1){digitalWrite(c, 1);}else{digitalWrite(c, 0);}
  }
}