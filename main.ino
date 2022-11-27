#include <LiquidCrystal_I2C.h>
#define echo 10
#define trig 9

LiquidCrystal_I2C lcd(0x27, 16, 2);

long duration;
int distance;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
  lcd.init();
  lcd.backlight();
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = (duration / 2) / 74;

  lcd.setCursor(0,0);
  lcd.print("Inches.");
  lcd.setCursor(0,1);
  lcd.print(distance);
  delay(1000);
  lcd.clear();
}