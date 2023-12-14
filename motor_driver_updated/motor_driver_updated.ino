int pwm1=3;
int pwm2=5;
int pwm3=9;
int pwm4=11;
int dir1=2;
int dir2=4;
int dir3=8;
int dir4=10;
char a;
int i;

void slowdown(){
  for(;i>=0;i=i-10){
    analogWrite(pwm1,i);
    analogWrite(pwm2,i);
    analogWrite(pwm3,i);
    analogWrite(pwm4,i);
    Serial.println(i);
    delay(50);
    if(i==0){
      break;
    }
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
    case 'F':
    for(i=0; i<=200;i++){
    analogWrite(pwm1,i);
    digitalWrite(dir1,HIGH);
    analogWrite(pwm2,i);
    digitalWrite(dir2,HIGH);
    analogWrite(pwm3,i);
    digitalWrite(dir3,HIGH);
    analogWrite(pwm4,i);
    digitalWrite(dir4,HIGH);
    Serial.println(i);
    delay(20);}
    break;
    case 'B':
    
    for(int i=0; i<=200;i++){
    analogWrite(pwm1,i);
    digitalWrite(dir1,LOW);
    analogWrite(pwm2,i);
    digitalWrite(dir2,LOW);
    analogWrite(pwm3,i);
    digitalWrite(dir3,LOW);
    analogWrite(pwm4,i);
    digitalWrite(dir4,LOW);
    Serial.println(i);
    delay(20);}
    break;
    case 'x':
    
    for(int i=0; i<=150;i++){
    analogWrite(pwm1,i);
    digitalWrite(dir1,HIGH);
    analogWrite(pwm2,i);
    digitalWrite(dir2,HIGH);
    analogWrite(pwm3,i-75);
    digitalWrite(dir3,LOW);
    analogWrite(pwm4,i-75);
    digitalWrite(dir4,LOW);
    Serial.println(i);
    delay(20);}
    break;
    case 'y':
    
    for(int i=0; i<=150;i++){
    analogWrite(pwm1,i-75);
    digitalWrite(dir1,LOW);
    analogWrite(pwm2,i-75);
    digitalWrite(dir2,LOW);
    analogWrite(pwm3,i);
    digitalWrite(dir3,HIGH);
    analogWrite(pwm4,i);
    digitalWrite(dir4,HIGH);
    Serial.println(i);
    delay(20);}
    break;
    case 'R':
    
    for(int i=0; i<=200;i++){
    analogWrite(pwm1,i);
    digitalWrite(dir1,HIGH);
    analogWrite(pwm2,i);
    digitalWrite(dir2,HIGH);
    analogWrite(pwm3,i);
    digitalWrite(dir3,LOW);
    analogWrite(pwm4,i);
    digitalWrite(dir4,LOW);
    Serial.println(i);
    delay(20);}
    break;
    case 'L':
    
    for(int i=0;i<=200;i++){
    analogWrite(pwm1,i);
    digitalWrite(dir1,LOW);
    analogWrite(pwm2,i);
    digitalWrite(dir2,LOW);
    analogWrite(pwm3,i);
    digitalWrite(dir3,HIGH);
    analogWrite(pwm4,i);
    digitalWrite(dir4,HIGH);
    Serial.println(i);
    delay(20);}
case 'S':
    slowdown();
    analogWrite(pwm1,LOW);
    analogWrite(pwm2,LOW);
    analogWrite(pwm3,LOW);
    analogWrite(pwm4,LOW);
    break;
  }

}


}