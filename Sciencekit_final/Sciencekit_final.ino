#include <AccelStepper.h>
#include <wire.h>
P11=3;
P12=4;
P21=5;
P22=6;
char a;
AccelStepper Stepper1(1,9,10);
int i=0;

void setup() {
  Serial.begin(9600);
  Stepper1.setMaxSpeed(10000);
  Stepper1.setAcceleration(1000);
  Stepper1.setCurrentPosition(0);
  pinMode(P11,OUTPUT);
  pinMode(P12,OUTPUT);
  pinMode(P21,OUTPUT);
  pinMode(P22,OUTPUT);

}

void loop() {
  if (Serial.available()){
    a=Serial.read();
    Switch(a){
      case 'T':
      digitalWrite(P11,HIGH);
      digitalWrite(P12,LOW);
      delay(1500);
      digitalWrite(P11,LOW);
      digitalWrite(P12,LOW);
      break;
      case 'Y':
      digitalWrite(P21,HIGH);
      digitalWrite(P22,LOW);
      delay(1500);
      digitalWrite(P21,LOW);
      digitalWrite(P22,LOW);
      break;
      case 'U':
      for(int i=0; i<=15; i++){
      Stepper1.moveTo(1067);
      Stepper1.runToPosition();
      Stepper1.moveTo(0);
      Stepper1.runToPosition();
      }

    }
  }

}
