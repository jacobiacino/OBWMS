int LEDPin = 13;
int RELAY1 = 6;
int RELAY2 = 7;
int RELAY3 = 8;
int RELAY4 = 9;
int LEDstate = 0;
int relayState = 0;
int flag = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(LEDPin, OUTPUT);
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);
  digitalWrite(LEDPin, LOW);
  digitalWrite(RELAY1, HIGH);
  digitalWrite(RELAY2, HIGH);
  digitalWrite(RELAY3, HIGH);
  digitalWrite(RELAY4, HIGH);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0) {
    LEDstate = Serial.read();
    flag = 0;
  }
  if (LEDstate == '0') {
    digitalWrite(LEDPin, LOW);
    digitalWrite(RELAY1, HIGH);
    digitalWrite(RELAY2, HIGH);
    digitalWrite(RELAY3, HIGH);
    digitalWrite(RELAY4, HIGH);
    if (flag == 0) {
      Serial.println("LED: off");
      flag = 1;
    }
  } else if (LEDstate == '1') {
    digitalWrite(LEDPin, HIGH);
    digitalWrite(RELAY1, LOW);
    digitalWrite(RELAY2, LOW);
    digitalWrite(RELAY3, LOW);
    digitalWrite(RELAY4, LOW);
    if (flag == 0) {
      Serial.println("LED: on");
      flag = 1;
    }
  }
}
