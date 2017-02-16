#include <OneWire.h>
#include <DallasTemperature.h>

# define ONE_WIRE_BUS 11

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

int LEDPin = 13;
int RELAY1 = 6;
int RELAY2 = 7;
int RELAY3 = 8;
int RELAY4 = 9;
char serialIn;
int LEDcurr = 0;
int tempCount = 0;
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
  sensors.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0) {
    serialIn = Serial.read();
    flag = 0;
  }
  if (serialIn == '0') {
    digitalWrite(LEDPin, LOW);
    printToConsole("LED: OFF");
  } else if (serialIn == '1') {
    digitalWrite(LEDPin, HIGH);
    printToConsole("LED: ON");
  } else if (serialIn == 'a') {
    digitalWrite(RELAY1, HIGH);
    printToConsole("RELAY 1: OFF");
  } else if (serialIn == 'A') {
    digitalWrite(RELAY1, LOW);
    printToConsole("RELAY 1: ON");
  } else if (serialIn == 'b') {
    digitalWrite(RELAY2, HIGH);
    printToConsole("RELAY 2: OFF");
  } else if (serialIn == 'B') {
    digitalWrite(RELAY2, LOW);
    printToConsole("RELAY 2: ON");
  } else if (serialIn == 'c') {
    digitalWrite(RELAY3, HIGH);
    printToConsole("RELAY 3: OFF");
  } else if (serialIn == 'C') {
    digitalWrite(RELAY3, LOW);
    printToConsole("RELAY 3: ON");
  } else if (serialIn == 'd') {
    digitalWrite(RELAY4, HIGH);
    printToConsole("RELAY 4: OFF");
  } else if (serialIn == 'D') {
    digitalWrite(RELAY4, LOW);
    printToConsole("RELAY 2: ON");
  }
  printTemp();
}

void printToConsole(String msg) {
  if (flag == 0) {
    Serial.println(msg);
    flag = 1;
  }
}

void printTemp() {
  if (tempCount % 10 == 0) {
    sensors.requestTemperatures();
    Serial.println(sensors.getTempFByIndex(0));
  }
}

