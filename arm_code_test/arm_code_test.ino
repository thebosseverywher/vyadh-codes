#include <Wire.h>
#include <AccelStepper.h>
#include <MultiStepper.h>

String j1;
int cur=0;
int target1,target2,target3,prev1,prev2,prev3,dif1,dif2,dif3 = 0;
AccelStepper Stepper1(1,9,8);
AccelStepper Stepper2(1,7,6);
AccelStepper Stepper3(1,4,7);

void sp( String j, int c);

void setup() {
  Serial.begin(9600);
 Stepper1.setMaxSpeed(10000);
 Stepper1.setAcceleration(900);
 Stepper1.setCurrentPosition(0);

 Stepper2.setMaxSpeed(10000);
 Stepper2.setAcceleration(900);
 Stepper2.setCurrentPosition(0);
 
 Stepper3.setMaxSpeed(500);
 Stepper3.setAcceleration(200);
 Stepper3.setCurrentPosition(0);
 
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
      step=(theta*200)/360;
      Stepper1.moveTo(step);
      Stepper1.run();
     
      break;
      case 2:
      s = float(target2-prev2)/float(maxterm);
      q = float(d)*s;
      theta = float(prev2) + q;
      step=(theta*200)/360;
      Stepper2.moveTo(step);
      Stepper2.run();
    
      break;
      case 3:
      s = float(target3-prev3)/float(maxterm);
      q = float(d)*s;
      theta = float(prev3) + q;
      step=(theta*200)/360;
      Stepper3.moveTo(step);
      Stepper3.run();
      Serial.println();
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

  //delay(100);
  
}


int max3(int a,int b, int c){
  int max1 = max(a,b);
  int max2 = max(max1,c);
  return max2;
}


void sp(String j, int c){
  int deg = j.toInt();
  Serial.print(deg);
  Serial.print(" ");
  switch(c){
  case 0:
  target1 = deg;
  break;
  case 1:
  target2 = deg;
  break;
  case 2:
  target3 = deg;
  break;
  }
  
}
