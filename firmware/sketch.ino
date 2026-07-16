#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int currentState;

int secondCurrentState;

int noteDuration = 2;

int NOTEC4 = 31;

int micValue;

int action;

int maxActions = 3;

LiquidCrystal_I2C lcd(0x27, 16, 2); 

unsigned long lastMillis = 0;

bool gameStarted = false;
bool completed = false;
bool generatedAction = false;
bool failed = false;

float time_limit = 4000;

void setup() {
  Serial.begin(9600);

  pinMode(8, OUTPUT);
  pinMode(11, INPUT);
  pinMode(10, OUTPUT);

  tone(10, NOTEC4, noteDuration);
  noTone(10);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("PRESS ANY BUTTON TO BEGIN.");

  digitalWrite(8, HIGH);
}

void loop(){
  unsigned long currentMillis = millis();

  currentState = digitalRead(11);
  secondCurrentState = digitalRead(12);

  micValue = digitalRead(13);

  if (gameStarted) {
    if (currentMillis - lastMillis >= time_limit) {
      lastMillis = currentMillis;
      failed = true;
    }
  }
  else {
    lastMillis = currentMillis;
  }

  if (!gameStarted) {
    if (currentState == LOW || secondCurrentState == LOW) {
      gameStarted = true;
    }
  }
  else {
    if (!generatedAction) {
        tone(10, NOTEC4, noteDuration);
        noTone(10);

      digitalWrite(8, LOW);

      generatedAction = true;
      lcd.clear();

  randomSeed(analogRead(A3));

  action = random(0, maxActions);
  String directions = "";

  switch (action){
    case 0:
      directions = "Press the left button.";
      break;
    case 1:
      directions = "Press the right button.";
      break;
    case 2:
      directions = "Make noise into the mic.";
      break;
  }

  if (directions.length() <= 16) {
    lcd.print(directions);
  }
  else {
    lcd.print(directions.substring(0, 16));
    lcd.setCursor(0, 1);
    lcd.print(directions.substring(16));
  }
    }
    else if (generatedAction && !failed) {
      delay(500);
      switch (action){
      case 0:
        if (currentState == LOW) {
      completed = true;
      }
        break;
      case 1:
        if (secondCurrentState == LOW) {
      completed = true;
      }
        break;
      case 2:
        if (micValue == 1) {
      completed = true;
      }
        break;
    }
    }
  }

  if (completed) {
    tone(10, NOTEC4, noteDuration);
    noTone(10);

    lcd.clear();
    lcd.print("You are Quick");

    delay(1000);

    lcd.clear();
    lcd.print("PRESS ANY BUTTON TO BEGIN");
    completed = false;
    generatedAction = false;
    gameStarted = false;
    failed = false;

    digitalWrite(8, HIGH);
  }

  if (failed) {
    tone(10, NOTEC4, noteDuration);
    noTone(10);

    lcd.clear();
    lcd.print("Took Too Long");

    delay(1000);

    lcd.clear();
    lcd.print("PRESS ANY BUTTON TO BEGIN");
    failed = false;
    generatedAction = false;
    gameStarted = false;
    completed = false;

    digitalWrite(8, HIGH);
  }
}