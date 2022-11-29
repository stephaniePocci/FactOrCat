#include <LiquidCrystal_I2C.h>
#define echo 10
#define trig 9
#include "Talkie.h"
#include "Vocab_US_Large.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

long duration;
int distance;
int feet;
int inches;
const int buttonPin = 2;
int buttonState = 0;
Talkie voice;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(13, OUTPUT);
  pinMode(buttonPin, INPUT);
  
  lcd.init();
  lcd.backlight();

  voice.say(sp2_ON);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  // if (buttonState == HIGH) {
  //   digitalWrite(13, HIGH);
  //   lcd.print("Pressed");
  // } else {
  //   digitalWrite(13, LOW);
  // }

  if (buttonState == HIGH) { // high = on
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    duration = pulseIn(echo, HIGH);
    distance = (duration / 2) / 74;
    feet = distance / 12;
    inches = distance % 12;

    if (feet == 1) {
      voice.say(sp2_ONE);
      voice.say(sp2_FEET);
    } else if (feet == 2) {
      voice.say(sp2_TWO);
      voice.say(sp2_FEET);
    } else if (feet == 3) {
      voice.say(sp2_THREE);
      voice.say(sp2_FEET);
    } else if (feet == 4) {
      voice.say(sp2_FOUR);
      voice.say(sp2_FEET);
    } else if (feet == 5) {
      voice.say(sp2_FIVE);
      voice.say(sp2_FEET);
    } else if (feet == 6) {
      voice.say(sp2_SIX);
      voice.say(sp2_FEET);
    } else if (feet == 7) {
      voice.say(sp2_SEVEN);
      voice.say(sp2_FEET);
    } else if (feet == 8) {
      voice.say(sp2_EIGHT);
      voice.say(sp2_FEET);
    } else if (feet == 9) {
      voice.say(sp2_NINE);
      voice.say(sp2_FEET);
    } else if (feet == 10) {
      voice.say(sp2_TEN);
      voice.say(sp2_FEET);
    } else if (feet == 11) {
      voice.say(sp2_ELEVEN);
      voice.say(sp2_FEET);
    } else if (feet == 12) {
      voice.say(sp2_TWELVE);
      voice.say(sp2_FEET);
    }

    if (inches == 1) {
      voice.say(sp2_ONE);
    } else if (inches == 2) {
      voice.say(sp2_TWO);
    } else if (inches == 3) {
      voice.say(sp2_THREE);
    } else if (inches == 4) {
      voice.say(sp2_FOUR);
    } else if (inches == 5) {
      voice.say(sp2_FIVE);
    } else if (inches == 6) {
      voice.say(sp2_SIX);
    } else if (inches == 7) {
      voice.say(sp2_SEVEN);
    } else if (inches == 8) {
      voice.say(sp2_EIGHT);
    } else if (inches == 9) {
      voice.say(sp2_NINE);
    } else if (inches == 10) {
      voice.say(sp2_TEN);
    } else if (inches == 11) {
      voice.say(sp2_ELEVEN);
    } else if (inches == 12) {
      voice.say(sp2_TWELVE);
    }


    lcd.setCursor(0,0);
    lcd.print("Distance:");
    lcd.setCursor(0,1);
    lcd.print(feet);
    lcd.print("'");
    lcd.print(inches);
    delay(5000);
    lcd.clear();

  }

}