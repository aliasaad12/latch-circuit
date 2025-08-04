#define BUTTON_PIN 2
#define TRANSISTOR_PIN 8
#define AUTO_OFF_DELAY 10000

unsigned long lastPressTime = 0;
unsigned long currentMillis;
bool deviceState = false;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(TRANSISTOR_PIN, OUTPUT);
  digitalWrite(TRANSISTOR_PIN, LOW);
  Serial.begin(9600);
}

void loop() {
  currentMillis = millis();
  bool buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == LOW) {
    delay(50);
    lastPressTime = currentMillis;
    deviceState = !deviceState;
    digitalWrite(TRANSISTOR_PIN, deviceState ? HIGH : LOW);
  }
}