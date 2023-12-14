int pwm1=10;
int dir1=11;
void setup() {
pinMode(dir1,OUTPUT);
pinMode(pwm1,OUTPUT);

}

void loop() {
digitalWrite(dir1,HIGH);
analogWrite(pwm1,150);
delay(3000);
digitalWrite(dir1,LOW);
analogWrite(pwm1,150);
delay(3000);
digitalWrite(pwm1,LOW);
delay(3000);

}
