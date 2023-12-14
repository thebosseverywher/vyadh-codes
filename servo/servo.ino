#include<Servo.h>

Servo serX;
Servo serY;
void setup() {

  serX.attach(7);
  serY.attach(6);
}

void loop() {
  serX.write(180);
  serY.write(180);
  delay(1000);
  serX.write(0);
  serY.write(0);
  delay(1000);



}
