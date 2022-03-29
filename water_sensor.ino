/*LED*/
#define LED_PIN5 7 //定義LED紅 PIN為11
#define LED_PIN6 6 //定義LED黃 PIN為12                                        ,
#define LED_PIN7 5 //定義LED7綠 PIN為13
/*LCD*/
#include <LiquidCrystal_I2C.h> //LCD library
#include <Wire.h> 
LiquidCrystal_I2C lcd(0x27,16,2);  //設定LCD位置0x27,設定LCD大小為16*2
/*水位感測器*/
#define WaterPin 0
#define Alert 3
double data, depth;

void setup()
{
lcd.init(); //初始化LCD 
lcd.backlight(); //開啟背光
pinMode(LED_PIN5, OUTPUT);//設定PIN 11為輸出模式
pinMode(LED_PIN6, OUTPUT);//設定PIN 12為輸出模式
pinMode(LED_PIN7, OUTPUT);//設定PIN 13為輸出模式
Serial.begin(9600);

}
void loop()
{
data = analogRead(WaterPin);
depth = (data / 670) * 4;
Serial.print(depth);
Serial.println("cm");
if (depth>1 && depth<2){
    digitalWrite(LED_PIN5, HIGH);//PIN 5輸出為HIGH,LED點亮
    digitalWrite(LED_PIN6, LOW);//PIN 6輸出為LOW,LED熄滅
    digitalWrite(LED_PIN7, LOW);//PIN 7輸出為LOW,LED熄滅
    lcd.clear();
    lcd.print(depth);
    lcd.setCursor(0, 1);
    lcd.print("Safety");
    noTone(9); //noTone停止發出聲音PIN 9
    delay(1000); 
  }
else if(depth>2 && depth<3){
    digitalWrite(LED_PIN5,LOW );//PIN 5輸出為LOW,LED點亮
    digitalWrite(LED_PIN6, HIGH);//PIN 6輸出為HIGH,LED熄滅
    digitalWrite(LED_PIN7, LOW);//PIN 7輸出為LOW,LED熄滅
    lcd.clear();
    lcd.print(depth);
    lcd.setCursor(0, 1);
    lcd.print("Attention");
    tone(9,1046,1000);//tone (使用9號腳位,使用1046(DO發音),持續1秒)
    delay(1000);
  }
else if(depth>3){
    digitalWrite(LED_PIN5, LOW);//PIN 5輸出為LOW,LED點亮
    digitalWrite(LED_PIN6, LOW);//PIN 6輸出為LOW,LED熄滅
    digitalWrite(LED_PIN7, HIGH);//PIN 7輸出為HIGH,LED熄滅
    lcd.clear();
    lcd.print(depth);
    lcd.setCursor(0, 1);
    lcd.print("Urgent");
    tone(9,1046,5000);//tone (使用9號腳位,使用1046(DO發音),持續5秒)
    delay(5000);
  }  
}


