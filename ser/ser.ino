#include <Servo.h>
Servo Servo1;
int i=0;
void setup() {
 Serial.begin(9600);
 Servo1.attach(9);Servo1.write(180);
  
}

void loop() {

 
 
}
