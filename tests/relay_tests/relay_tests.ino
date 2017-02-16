#define RELAY1 2
#define RELAY2 3

char b;

boolean relay1State = false;
boolean relay2State = false;

void setup()
{
  Serial.begin(9600);
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY1, OUTPUT);
  
  digitalWrite(RELAY1, LOW);
  digitalWrite(RELAY2, LOW);
}

void loop()
{
  if (Serial.available()) {
    b = Serial.read();
    if (b == 'O') {
      if (relay1State) {
        digitalWrite(RELAY1, LOW);
      } else {
        digitalWrite(RELAY1, HIGH);
      }
      relay1State = !relay1State;
    } else if (b == 'F') {
      if (relay2State) {
        digitalWrite(RELAY2, LOW);
      } else {
        digitalWrite(RELAY2, HIGH);
      }
      relay2State = !relay2State;
    }
  }
} 
