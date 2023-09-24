#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4); 
int trig_pin = 6;
int echo_pin = 7;
int buzzer = 12;
long duration;
int distance;

void setup() {
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(buzzer,OUTPUT);
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig_pin, 0);
  delayMicroseconds(2);

  digitalWrite(trig_pin, 1);
  delayMicroseconds(10);
  digitalWrite(trig_pin, 0);

  duration = pulseIn(echo_pin, 1);
  distance = duration * 0.034 / 2;

  Serial.print("Distance : ");
  Serial.println(distance);
  lcd.setCursor(1,0);
  lcd.write("Distance: ");
  lcd.write(distance);

  if (distance < 50);
  {
    lcd.setCursor(3,1);
     Serial.print("Danger");
     lcd.write("Danger");
     digitalWrite(buzzer,HIGH);
  }
  if (distance > 50);
  {
    lcd.setCursor(3,1);
     Serial.print("Safe");
     lcd.write("Safe");
     digitalWrite(buzzer,LOW);
  }
     
  delay (100);
}
