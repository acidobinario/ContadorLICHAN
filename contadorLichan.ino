
#define counter A0 //contador
#define flipFlop 1 //flip-flop
#define Reset A1
#define b0 8 //bcd 1
#define b1 9 //bcd 2
#define b2 10 //bcd 3
#define b3 11 //bcd 4
#define led 13 // LED

//A to G 7Segment Display
#define a 2
#define b 3
#define c 4
#define d 5
#define e 6
#define f 7
#define g 12

//int val;
bool compareState = false;
int counterState;
int lastCounterState;
int counterPushCounter;

int bcd1;
int bcd2;
int bcd3;
int bcd4;

void setup() {
  Serial.begin(9600);
  Serial.println("counter");
  
  // INPUT: 
  pinMode(counter, INPUT);
  pinMode(flipFlop, INPUT);
  pinMode(Reset, INPUT);
  pinMode(b0, INPUT_PULLUP);
  pinMode(b1, INPUT_PULLUP);
  pinMode(b2, INPUT_PULLUP);
  pinMode(b3, INPUT_PULLUP);
  //display
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(12,OUTPUT);
  
// OUTPUT:
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);
//  val = 0;
  cero();
  delay(100);
}

void loop() { 
  digitalWrite(led, HIGH); 
  count();// sacar el else if si se quiere mantener el numero contado hasta el proximo 1 del FlipFlop
//  if (digitalRead(flipFlop) == LOW && digitalRead(counter) == HIGH){
//    counterPushCounter = 0;
//    cero();
//    }

  compare();  
  Display();
  
}

void count(){
  counterState = digitalRead(counter);
 
  
  if (counterState != lastCounterState) {
    //delay(90);
    if (counterState == LOW && digitalRead(flipFlop) == HIGH) {   
      counterPushCounter++;
      Serial.println(counterPushCounter);
    }
    delay(50);
  }
  
    lastCounterState = counterState;
}

void compare(){
  bcd4 = digitalRead(b0);
  bcd3 = digitalRead(b1);
  bcd2 = digitalRead(b2);
  bcd1 = digitalRead(b3);
//  if((bcd1 == 1 && bcd2 == 1 && bcd3 == 1 && bcd4 == 1) && counterPushCounter == 0){
//    counterPushCounter = 0;
//    Serial.println(0);
//    } //0

  if((bcd1 == HIGH && bcd2 == HIGH && bcd3 == HIGH && bcd4 == LOW) && counterPushCounter == 1){
    digitalWrite(led, LOW);
    compareState = true;
    delay(100);
    one();
    while(compareState == true){
      if(digitalRead(Reset) == HIGH && digitalRead(counter) == HIGH){
        compareState = false;
        digitalWrite(led, HIGH);
        counterPushCounter = 0;
        delay(100);
        break;
        delay(10);
      }
    }
  } //1
  if((bcd1 == HIGH && bcd2 == HIGH && bcd3 == LOW && bcd4 == HIGH) && counterPushCounter == 2){
    digitalWrite(led, LOW);
    two();
    delay(100);
    compareState = true;
    while(compareState == true){
      if(digitalRead(Reset) == HIGH && digitalRead(counter) == HIGH){
        compareState = false;
        digitalWrite(led, HIGH);
        counterPushCounter = 0;
        delay(100);
        break;}
        delay(10);
    }
  } //2
  if((bcd1 == HIGH && bcd2 == HIGH && bcd3 == LOW && bcd4 == LOW) && counterPushCounter == 3){
    digitalWrite(led, LOW);
    three();
    delay(100);
    compareState = true;
    while(compareState == true){
      if(digitalRead(Reset) == HIGH && digitalRead(counter) == HIGH){
        compareState = false;
        digitalWrite(led, HIGH);
        counterPushCounter = 0;
        delay(100);
        break;}
        delay(10);
    }
  } //3
  if((bcd1 == HIGH && bcd2 == LOW && bcd3 == HIGH && bcd4 == HIGH) && counterPushCounter == 4){
    digitalWrite(led, LOW);
    four();
    delay(100);
    compareState = true;
    while(compareState ==true){
      if(digitalRead(Reset) == HIGH && digitalRead(counter) == HIGH){
        compareState = false;
        digitalWrite(led, HIGH);
        counterPushCounter = 0;
        delay(100);
        break;}
        delay(10);
    }
  } //4
  if((bcd1 == HIGH && bcd2 == LOW && bcd3 == HIGH && bcd4 == LOW) && counterPushCounter == 5){
    digitalWrite(led, LOW);
    five();
    delay(100);
    compareState = true;
    while(compareState == true){
      if(digitalRead(Reset) == HIGH && digitalRead(counter) == HIGH){
        compareState = false;
        digitalWrite(led, HIGH);
        counterPushCounter = 0;
        delay(100);
        break;}
        delay(10);
    }
  } //5
  if((bcd1 == HIGH && bcd2 == LOW && bcd3 == LOW && bcd4 == HIGH) && counterPushCounter == 6){
    digitalWrite(led, LOW);
    six();
    delay(100);
    compareState = true;
    while(compareState == true){
      if(digitalRead(Reset) == HIGH && digitalRead(counter) == HIGH){
        compareState = false;
        digitalWrite(led, HIGH);
        counterPushCounter = 0;
        delay(100);
        break;}
        delay(10);
    }
  } //6
  if((bcd1 == HIGH && bcd2 == LOW && bcd3 == LOW && bcd4 == LOW) && counterPushCounter == 7){
    digitalWrite(led, 0);
    seven();
    delay(100);
    compareState = true;
    while(compareState == true){
      if(digitalRead(Reset) == HIGH && digitalRead(counter) == HIGH){
        compareState = false;
        digitalWrite(led, 1);
        counterPushCounter = 0;
        delay(100);
        break;}
        delay(10);
        
    }
  } //7
  if((bcd1 == LOW && bcd2 == HIGH && bcd3 == HIGH && bcd4 == HIGH) && counterPushCounter == 8){
    digitalWrite(led, 0);
    eight();
    delay(100);
    compareState = true;
    while(compareState == true){
      if(digitalRead(Reset) == HIGH && digitalRead(counter) == HIGH){
        compareState = false;
        digitalWrite(led, 1);
        counterPushCounter = 0;
        delay(100);
        break;}
        delay(10);
    }
  } //8
  if((bcd1 == LOW && bcd2 == HIGH && bcd3 == HIGH && bcd4 == LOW) && counterPushCounter == 9){
    digitalWrite(led, 0);
    nine();
    delay(100);
    compareState = true;
    while(compareState == true){
      if(digitalRead(Reset) == HIGH && digitalRead(counter) == HIGH){
        compareState = false;
        digitalWrite(led, 1);
        delay(100);
        counterPushCounter = 0;
        break;}
        delay(10);
        
    }
  } //9

}

void Display(){
  switch (counterPushCounter){
    case 0:
      cero();
      break;
    case 1:
      one();
      break;
    case 2:
      two();
      break;
    case 3:
      three();
      break;
    case 4:
      four();
      break;
    case 5:
      five();
      break;
    case 6:
      six();
      break;
    case 7:
      seven();
      break;
    case 8:
      eight();
      break;
    case 9:
      nine();
      break;
    case 10:
      {
      counterPushCounter = 0;
      cero();
      break;
      }
  }
}
void cero(){
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,0);
  digitalWrite(d,0);
  digitalWrite(e,0);
  digitalWrite(f,0);
  digitalWrite(g,1);
  }
void one(){
  digitalWrite(a,1);
  digitalWrite(b,0);
  digitalWrite(c,0);
  digitalWrite(d,1);
  digitalWrite(e,1);
  digitalWrite(f,1);
  digitalWrite(g,1);
  }
void two(){
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,1);
  digitalWrite(d,0);
  digitalWrite(e,0);
  digitalWrite(f,1);
  digitalWrite(g,0);
  }
void three(){
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,0);
  digitalWrite(d,0);
  digitalWrite(e,1);
  digitalWrite(f,1);
  digitalWrite(g,0);
  }
void four(){
  digitalWrite(a,1);
  digitalWrite(b,0);
  digitalWrite(c,0);
  digitalWrite(d,1);
  digitalWrite(e,1);
  digitalWrite(f,0);
  digitalWrite(g,0);
  }
void five(){
  digitalWrite(a,0);
  digitalWrite(b,1);
  digitalWrite(c,0);
  digitalWrite(d,0);
  digitalWrite(e,1);
  digitalWrite(f,0);
  digitalWrite(g,0);
  }
void six(){
  digitalWrite(a,0);
  digitalWrite(b,1);
  digitalWrite(c,0);
  digitalWrite(d,0);
  digitalWrite(e,0);
  digitalWrite(f,0);
  digitalWrite(g,0);
  }
void seven(){
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,0);
  digitalWrite(d,1);
  digitalWrite(e,1);
  digitalWrite(f,1);
  digitalWrite(g,1);
  }
void eight(){
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,0);
  digitalWrite(d,0);
  digitalWrite(e,0);
  digitalWrite(f,0);
  digitalWrite(g,0);
  }
void nine(){
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,0);
  digitalWrite(d,0);
  digitalWrite(e,1);
  digitalWrite(f,0);
  digitalWrite(g,0);
  }





