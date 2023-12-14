int pwm1=6;
int pwm2=9;
int pwm3=10;
int pwm4=11;
int dir1=2;
int dir2=3;
int dir3=4;
int dir4=5;
int a;
int i;
int b;
int l1=180;
int l2=120;
void slowdown(int i1)
{
  for(;i1>=0;i1--)
  {
      analogWrite(pwm1,i);
    analogWrite(pwm2,i);
    analogWrite(pwm3,i);
    analogWrite(pwm4,i);
    Serial.println(i);
    delay(50);
  }
}
void setup() {
pinMode(pwm1,OUTPUT);
pinMode(pwm2,OUTPUT);
pinMode(pwm3,OUTPUT);
pinMode(pwm4,OUTPUT);
pinMode(dir1,OUTPUT);
pinMode(dir2,OUTPUT);
pinMode(dir3,OUTPUT);
pinMode(dir4,OUTPUT);
Serial.begin(9600);
}

void loop() {
if (Serial.available()){
  a=Serial.read();
  switch(a){
    case '1':
    b=a;
    for(i=0; i<=l1;i++){
    analogWrite(pwm1,i);
    digitalWrite(dir1,HIGH);
    analogWrite(pwm2,i);
    digitalWrite(dir2,HIGH);
    analogWrite(pwm3,i);
    digitalWrite(dir3,HIGH);
    analogWrite(pwm4,i);
    digitalWrite(dir4,HIGH);
    Serial.println(i);
    delay(50);}
    slowdown(i);
    break;
    case '2':

    for(int i=0; i<=l1;i++){
    analogWrite(pwm1,i);
    digitalWrite(dir1,LOW);
    analogWrite(pwm2,i);
    digitalWrite(dir2,LOW);
    analogWrite(pwm3,i);
    digitalWrite(dir3,LOW);
    analogWrite(pwm4,i);
    digitalWrite(dir4,LOW);
    Serial.println(i);
    delay(50);}
    slowdown(i);
    break;
    case '3':
    for(int i=0; i<=l2;i++){
    analogWrite(pwm1,i);
    digitalWrite(dir1,HIGH);
    analogWrite(pwm2,i);
    digitalWrite(dir2,HIGH);
    analogWrite(pwm3,i);
    digitalWrite(dir3,LOW);
    analogWrite(pwm4,i);
    digitalWrite(dir4,LOW);
    Serial.println(i);
    delay(50);}
    slowdown(i);
    break;
    case '4':
    for(int i=0; i<=l2;i++){
    analogWrite(pwm1,i);
    digitalWrite(dir1,LOW);
    analogWrite(pwm2,i);
    digitalWrite(dir2,LOW);
    analogWrite(pwm3,i);
    digitalWrite(dir3,HIGH);
    analogWrite(pwm4,i);
    digitalWrite(dir4,HIGH);
    Serial.println(i);
    delay(50);}
    slowdown(i);
    break;
    case '5':
    for(int i=0; i<=l1;i++){
    analogWrite(pwm1,i);
    digitalWrite(dir1,HIGH);
    analogWrite(pwm2,i);
    digitalWrite(dir2,HIGH);
    analogWrite(pwm3,i);
    digitalWrite(dir3,LOW);
    analogWrite(pwm4,i);
    digitalWrite(dir4,LOW);
    Serial.println(i);
    delay(50);}
    slowdown(i);
    break;
    case '6':
    for(int i=0;i<=l1;i++){
    analogWrite(pwm1,i);
    digitalWrite(dir1,LOW);
    analogWrite(pwm2,i);
    digitalWrite(dir2,LOW);
    analogWrite(pwm3,i);
    digitalWrite(dir3,HIGH);
    analogWrite(pwm4,i);
    digitalWrite(dir4,HIGH);
    Serial.println(i);
    delay(50);}
    slowdown(i);
    break;
    case '7':
    analogWrite(pwm1,LOW);
    analogWrite(pwm2,LOW);
    analogWrite(pwm3,LOW);
    analogWrite(pwm4,LOW);
    break;
  }

}


}