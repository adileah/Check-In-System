void setup() {
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(A2, INPUT_PULLUP);
  Serial.begin(9600);
}
int current = 1;
int previous = 1;
int time = 3;
void loop() {
  current = digitalRead(A2);
  if((current == 0) && (previous == 1)){
    if(digitalRead(5) == LOW){
      digitalWrite(5, HIGH);
      Serial.println("person 1 checked in");
    }
    else if(digitalRead(6) == LOW){
      digitalWrite(6, HIGH);
      Serial.println("person 2 checked in");
    }
    else if(digitalRead(9) == LOW){
      digitalWrite(9, HIGH);
      Serial.println("person 3 checked in");
    }
    else if(digitalRead(10) == LOW){
      digitalWrite(10, HIGH);
      Serial.println("person 4 checked in");
    }
  }
  if(digitalRead(10) == HIGH){
    delay(3000);
    digitalWrite(11, HIGH);
    Serial.println("everyone has checked in");
    time--;
  }
  
  if(time == 0){
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    time = 3;
    Serial.println("everyone has checked out");
  }
  previous = digitalRead(A2);
}
