void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
}

void loop() {
  if(Serial.available()>0)
  {
    int tmp = Serial.read()-48;
    if(tmp == 1)
    {
      digitalWrite(13,HIGH);analogWrite(A1,0);analogWrite(A1,0);
    }
    
    if(tmp == 2)
    {
      digitalWrite(13,HIGH);analogWrite(A1,255);analogWrite(A1,255);
    }
    
    if(tmp == 9)
    {
      int s=0;   //秒
      int m=0;   //分
      int h=0;   //時
      int d=0;   //天
      while(1)
      {
        s=s+1;
        delay(5);// 50/1000=0.05s
        if(s >= 60)
        {
          s=0;
          m++;
        }
        if(m>=60)
        {
          h=0;
          d++;
        }
        if(m>=60)
        {
          m=0;
          h++;
        }
        if(h>=24)
        {
          h=0;
          d++;
        }
        Serial.print(d);
        Serial.print(" : ");
        
        Serial.print(h);
        Serial.print(" : ");
      
        Serial.print(m);
        Serial.print(" : ");
    
        Serial.println(s);
       
        

      }
    }//(tmp == 9)
  }//(Serial.available()>0)
}//loop
