int blueLED = 10;
char person = '0';
int greenLED = 6;
int orangeLED = 5;
int yellowLED = 9;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(blueLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(orangeLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  if (Serial.available() > 0) {    // is a character available?
    person = Serial.read(); 
    // get the character
    // check if a number was received
    if ((person > '0') && (person <= '9')) {
      Serial.print("Number received: ");
      Serial.println(person);
      if (person == '2') {
        Serial.println("green LED");
        if(digitalRead(greenLED) == HIGH){
          Serial.print("person ");
          Serial.print(person);
          Serial.println(" already checked-in");
          return;
        }
        digitalWrite(greenLED, HIGH);
      }
      else if (person == '1') {
        Serial.println("blue LED");
        if(digitalRead(blueLED) == HIGH){
          Serial.print("person ");
          Serial.print(person);
          Serial.println(" already checked-in");
          return;
        }
        digitalWrite(blueLED, HIGH);
      }  
      else if (person == '3') {
        Serial.println("yellow LED");
        if(digitalRead(yellowLED) == HIGH){
          Serial.print("person ");
          Serial.print(person);
          Serial.println(" already checked-in");
          return;
        }
        digitalWrite(yellowLED, HIGH);
      }  
      else if (person == '4') {
        Serial.println("orange LED");
        if(digitalRead(orangeLED) == HIGH){
          Serial.print("person ");
          Serial.print(person);
          Serial.println(" already checked-in");
          return;
        }
        digitalWrite(orangeLED, HIGH);
      }
    }
  }
}
