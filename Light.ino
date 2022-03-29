#include <Wire.h>
#include <LiquidCrystal_I2C.h>//函式庫

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
lcd.init();                                        
lcd.backlight(); 
pinMode(12, OUTPUT);
pinMode(11, OUTPUT);
pinMode(10, OUTPUT);

pinMode(A0, INPUT);
Serial.begin(9600);
}
void loop() {
int p_value = analogRead(A0);
int d= p_value;



Serial.println(p_value);
delay(1000);

if(d < 300){
 digitalWrite(12,HIGH );
 tone(9,1046,500);
 delay(1000);
 digitalWrite(12, LOW);
  digitalWrite(10, LOW);
  
}else if(d > 500  && d <= 700){
  digitalWrite(11,HIGH );
  tone(9,1046,500);
  delay(2000);
  digitalWrite(11, LOW);
    digitalWrite(10, LOW);

    
  }else if(d > 700){
    digitalWrite(10,HIGH );
  
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(d);
}

