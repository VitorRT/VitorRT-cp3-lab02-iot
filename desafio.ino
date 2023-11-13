// Desafio 01 e 02
const int buttonPin = 2;
const int ledPin = 13;

const int buttonPin2 = 3;
const int ledPin2 = 12;

int lastButtonState1 = HIGH;
int buttonState1;
int oppositeState;

int buttonState2;
int pressTime;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  pinMode(ledPin2, OUTPUT);
  pinMode(buttonPin2, INPUT_PULLUP);
}

void loop() {
  // Desafio 02: Botão com Tempo de Pressão
  buttonState2 = digitalRead(buttonPin2);

  if (buttonState2 == LOW) {
    pressTime = millis();
    if (pressTime >= 3000) {
      digitalWrite(ledPin2, HIGH);
    }
  }

  // Desafio 01: Botão com Debounce
  int readButton = digitalRead(buttonPin);

  if (readButton != lastButtonState1) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (readButton != buttonState1) {
      buttonState1 = readButton;

      if (buttonState1 == HIGH) {
        digitalWrite(ledPin, !digitalRead(ledPin));
        Serial.print("\n" + String(digitalRead(ledPin) ? "Ligado" : "Desligado"));
      }
    }
  }
  lastButtonState1 = readButton;
}




// desafio 03

const int ledPin = 3;
const int potPin = A0;

int MIN_RAW = 0;
int MAX_RAW = 1023;
int MIN_NIVEL = 0;
int MAX_NIVEL = 200;

int voltage;
int ledLevel;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  voltage = analogRead(potPin);
  ledLevel = mapAndConstrain(voltage, MIN_RAW, MAX_RAW, MIN_NIVEL, MAX_NIVEL);
  analogWrite(ledPin, ledLevel);
  delay(20);
}

int mapAndConstrain(int raw, int minRaw, int maxRaw, int minLevel, int maxLevel) {
  int level = map(raw, minRaw, maxRaw, minLevel, maxLevel);
  level = constrain(level, minLevel, maxLevel);
  return level;
}
