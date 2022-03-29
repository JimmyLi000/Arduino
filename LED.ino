#include<SoftwareSerial.h>    
#include<Wire.h>             
SoftwareSerial I2CBT(10,11);  //TX=PIN10  RX=PIN11


void setup() {
  Serial.begin(9600);  
  I2CBT.begin(9600); 
  pinMode(7,OUTPUT);
}

void loop() {
   byte cmmd[20];
    int insize;
    while(1){
      if((insize=(I2CBT.available())) >0){ //判斷是否有訊息傳入訊息
        Serial.print("input size =");
        Serial.println(insize);
        for(int i=0; i<insize; i++){
          Serial.print(cmmd[i]=char(I2CBT.read())); //顯示訊息
          Serial.print(" ");
        }
      }
    }
  switch (inByte) {
  case 'a':
  digitalWrite(7,HIGH);
  
  break;

  case 'b':
  digitalWrite(7,LOW);
  
  break;
  }
}
