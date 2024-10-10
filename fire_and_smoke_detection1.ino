#include <Adafruit_LiquidCrystal.h>
#include <Adafruit_LEDBackpack.h>
Adafruit_LiquidCrystal lcd_1(0);
#define BUZZER 4
#define LED_1  7
#define LED_2  6
#define LED_3  5
#define PIN_GAS A0

void setup(){
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  lcd_1.begin(16, 2);
  lcd_1.setBacklight(1);
  Serial.begin(9600);
}

void loop(){ 
  
  int g = analogRead(PIN_GAS);
  digitalWrite(LED_1,(g>=90) ? HIGH : LOW);
  digitalWrite(LED_2,(g>=150) ? HIGH : LOW);
  digitalWrite(LED_3,(g >260) ? HIGH : LOW);
  
  
  if(g>=260) {
    tone(BUZZER, 1000, 250);
  }
  
  Serial.println(g);
  lcd_1.setCursor(0, 1);
  lcd_1.print(g);
  delay(250);
  lcd_1.clear();
}