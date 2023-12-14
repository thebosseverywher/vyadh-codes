#include <Wire.h>
#include <AccelStepper.h>
AccelStepper Stepper1(1,9,10);
float factor=6400/6;
int a=0;
String Q;
//in1=3
//in3=4
//in5=5
//in2=6
//in4=7
//in6=8

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Stepper1.setMaxSpeed(10000);
Stepper1.setAcceleration(900);
Stepper1.setCurrentPosition(0);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);


}

void loop() {
while(Serial.available()>0){
  String Q=Serial.readString();

  Q.trim();
  if(Q=="c3" || Q=="d4" || Q=="e5"){
    Stepper1.moveTo(0);
    Stepper1.runToPosition();
    Serial.println(Q);
    delay(2000);
    pump();
    }
    
  
  else if(Q=="b3" || Q=="c4" || Q=="d5"){
    Stepper1.moveTo(-1067);
    Stepper1.runToPosition();
    Serial.println(Q);
    pump();

  }
  
  else if(Q=="a3" || Q=="b4" || Q=="c5"){
    Stepper1.moveTo(-2132);
    Stepper1.runToPosition();
    Serial.println(Q);
    pump();
    }
  
  else if(Q=="f3" || Q=="a4" || Q=="b5"){
    Stepper1.moveTo(-3200);
    Stepper1.runToPosition();
    Serial.println(Q); 
    pump(); 
    }
  
  else if(Q=="e3" || Q=="f4" || Q=="a5"){
    Stepper1.moveTo(-4265);
    Stepper1.runToPosition();
    Serial.println(Q);
    pump();
    }
  else if(Q=="d3" || Q=="e4" || Q=="f5"){
    Stepper1.moveTo(-5336);
    Stepper1.runToPosition();
    Serial.println(Q);
    pump();
    }
  else{
    Serial.println("hehe");
  } 
  }
}

void pump(){
  a=Q[1];
    digitalWrite(a,HIGH);
    digitalWrite(2,LOW);
    digitalWrite(4,LOW);
    digitalWrite(6,LOW);
    delay(1000);
    digitalWrite(a,LOW);
    digitalWrite(2,LOW);
    digitalWrite(4,LOW);
    digitalWrite(6,LOW);
}