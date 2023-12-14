#include <wire.h>
#define outputA 6
#define outputB 7
#define outputC 8
#define outputD 9
#define outputE 10
#define outputF 11
#define dir1 2
#define dir2 3
#define dir3 4
#define pwm1 A0
#define pwm2 A1
#define pwm3 A2

 String j1;
 int cur=0;
 int target1,target2,target3,prev1,prev2,prev3,dif1,dif2,dif3=0;
 int countera = 0; 
 int counterb = 0; 
 int counterc = 0; 
 int aState;
 int aLastState;  
 int bState;
 int bLastState; 
 int cState;
 int cLastState; 

 void sp( String j, int c);

 void setup() { 
   pinMode (outputA,INPUT);
   pinMode (outputB,INPUT);
   pinMode (outputC,INPUT);
   pinMode (outputD,INPUT);
   pinMode (outputE,INPUT);
   pinMode (outputF,INPUT);
   pinMode (dir1,OUTPUT);
   pinMode (dir2,OUTPUT);
   pinMode (dir3,OUTPUT);
   pinMode (pwm1,OUTPUT);
   pinMode (pwm2,OUTPUT);
   pinMode (pwm3,OUTPUT);
   
   Serial.begin (9600);
   // Reads the initial state of the outputA
   aLastState = digitalRead(outputA);   bLastState = digitalRead(outputC); cLastState = digitalRead(outputE); 
 } 

 void loop() { 

  int servoc =0;
  
  while(Serial.available()>0){
    int p =0;
    String input = Serial.readString();
    //Serial.println(input);
    //delay(100);
    int i=0;
    for (auto c : input){      
      if(input[i]==','||input[i]=='\n'){ 
        cur = i;
        j1= input.substring(p,cur); 
        sp(j1,servoc);
        
        p = cur+1;
        servoc += 1;
      }
      i++;
      
    }
    
    Serial.println();
    Serial.println("target");
    Serial.print(target1);
    Serial.print(",");
    Serial.print(target2);
    Serial.print(",");
    Serial.println(target3);
    
    dif1 = abs(target1 - prev1);
    dif2 = abs(target2 - prev2);
    dif3 = abs(target3 - prev3);

  int maxterm = max3(dif1,dif2,dif3);
  //Serial.println(maxterm);
  //Serial.println("loop ");
  
  for(float d=1; d<=maxterm; d++){
     for(int h = 1; h<= 3; h++){
      float s,q,theta;
      switch(h){
      case 1:
      s = float(target1-prev1)/float(maxterm);
      q = float(d)*s;
      theta = float(prev1) + q;
      int num1=round(target1/0.47);
      aState = digitalRead(outputA);
      if(dif1 > 0){
        digitalWrite(dir1,HIGH);
        analogWrite(pwm1,255);
      } else{
        digitalWrite(dir1,LOW);
        analogWrite(pwm1,255);
      }
    
    
      if (aState != aLastState){     
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(outputB) != aState) { 
       countera ++;
     } else {
       countera --;
     }
     if(num1==countera){
      analogWrite(pwm1,0);

     }
     Serial.print("  Positiona: ");
     Serial.print(countera);
      }
     aLastState = aState;
      
     
      break;
      case 2:
      s = float(target2-prev2)/float(maxterm);
      q = float(d)*s;
      theta = float(prev2) + q;
      int num2=round(target2/0.25);
      bState = digitalRead(outputC);
      if(dif2 > 0){
        digitalWrite(dir2,HIGH);
        analogWrite(pwm2,255);
      } else{
        digitalWrite(dir2,LOW);
        analogWrite(pwm2,255);
      }
    
    
      if (bState != bLastState){     
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(outputD) != bState) { 
       counterb ++;
     } else {
       counterb --;
     }
     if(num2==counterb){
      analogWrite(pwm2,0);

     }
     Serial.print("  Positionb: ");
     Serial.println(counterb);
      }
     bLastState = bState;
      
      
    
      break;
      case 3:
      s = float(target3-prev3)/float(maxterm);
      q = float(d)*s;
      theta = float(prev3) + q;
      int num3=round(target3/0.25);
      cState = digitalRead(outputE);
      if(dif3 > 0){
        digitalWrite(dir3,HIGH);
        analogWrite(pwm3,255);
      } else{
        digitalWrite(dir3,LOW);
        analogWrite(pwm3,255);
      }
    
    
      if (cState != cLastState){     
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(outputF) != cState) { 
       counterc ++;
     } else {
       counterc --;
     }
     if(num3==counterc){
      analogWrite(pwm3,0);

     }
     Serial.print("  Positionc: ");
     Serial.println(counterc);
      }
     cLastState = cState;
      
     break;
      }
     
     
      }
     delay(10);

    
  
      }
  prev1 = target1;
  prev2 = target2;
  prev3 = target3;
  Serial.println("previous"),
  Serial.print(prev1);
  Serial.print(",");
  Serial.print(prev2);
  Serial.print(",");
  Serial.println(prev3);
    
  
    
 }
  
  }
 