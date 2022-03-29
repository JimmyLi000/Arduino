#include "cactus_io_DHT22.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>//函式庫

#define DHT22_PIN 2
DHT22 dht(DHT22_PIN);

LiquidCrystal_I2C lcd(0x27,16,2);
long duration, distance;
int trigPin = 3;
int echoPin = 2;

void setup() {
  lcd.init();                                        
  lcd.backlight(); 
  dht.begin();
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
Serial.begin(9600);

}
void loop()
{
  float d ;
dht.readHumidity();
dht.readTemperature();
if (isnan(dht.humidity) || isnan(dht.temperature_C))
{
Serial.println("DHT sensor read failure!");
return;
}
d = dht.temperature_C;
if(d > 29){
  digitalWrite(5, HIGH);
  delay(1000);
  digitalWrite(5, LOW);
    delay(1000);
  digitalWrite(6, HIGH);
  delay(1000);
  digitalWrite(6, LOW);
    delay(1000);
   digitalWrite(7, HIGH);
  delay(1000);
  digitalWrite(7, LOW);
    delay(1000);
}else if(d > 28 && d <= 29){
   digitalWrite(5, HIGH);
  delay(1000);
  digitalWrite(5, LOW);
  delay(1000);
  digitalWrite(6, HIGH);
  delay(1000);
  digitalWrite(6, LOW);
delay(1000);
}else if(d > 27 && d <= 28){
   digitalWrite(5, HIGH);
  delay(1000);
  digitalWrite(5, LOW);
   delay(1000);
}
if(d < 27)
{
    digitalWrite(5, LOW);
      digitalWrite(6, LOW);
        digitalWrite(7, LOW);
}
 lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(d);
Serial.print("Humidity: ");
Serial.print(dht.humidity);
Serial.println(" %\t\t");
Serial.print("Temperature(C): ");
Serial.print(dht.temperature_C);
Serial.println(" *C\t");
Serial.print("Temperature(F): ");
Serial.print(dht.temperature_F);
Serial.println(" *F\t");
Serial.println("===========================");
delay(1000);
}

