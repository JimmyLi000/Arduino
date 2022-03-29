#include <Wire.h>
#include <LiquidCrystal_I2C.h>//函式庫
#define PIRout 1
LiquidCrystal_I2C lcd(0x27,16,2);  //LCD
#define LED 8
long duration, distance; //超音波
int trigPin = 3;
int echoPin = 2;

void setup()
{
lcd.init();                                        
lcd.backlight(); 

pinMode(PIRout,INPUT);
pinMode(LED,INPUT);

pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);

Serial.begin(9600);
}
void loop()
{
digitalWrite(trigPin, LOW);
delayMicroseconds(5);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin,HIGH);
distance = (duration / 2) / 29.1;   //超音波公式

int out_val = digitalRead(PIRout); //讀取 PIR 的輸出值


if (out_val == HIGH && distance > 20 && distance <= 30)
{
     digitalWrite(LED,HIGH);
  lcd.clear();
   lcd.setCursor(0, 0);
   lcd.print("Attention");   //LCD顯示
   lcd.setCursor(0, 1);
   lcd.print(distance);
   lcd.print("cm");//LCD顯示
   
}else if(out_val == HIGH && distance < 20)
{
digitalWrite(LED,HIGH);
    delay(1000);
    digitalWrite(LED,LOW);
    delay(1000);
 lcd.clear();
   lcd.setCursor(0, 0);
   lcd.print("Urgent");   //LCD顯示
   lcd.setCursor(0, 1);
   lcd.print(distance);
   lcd.print("cm");//LCD顯示
   delay(500);
    
}
if(out_val == LOW)
{
  digitalWrite(LED,LOW);
  lcd.clear();
}
 
}
