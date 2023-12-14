int X=A0;
int Y=A1;
int S=2;
int Xv;
int Yv;
int Sv;
int a;
int b;
int In1=3;
int In2=4;
int In3=5;
int In4=6;
int EnA=7;
int EnB=8;
void setup()
{
  Serial.begin(9600);
  pinMode(X,INPUT);
  pinMode(Y,INPUT);
  pinMode(S,INPUT);
  pinMode(In1,OUTPUT);
  pinMode(In2,OUTPUT);
  pinMode(In3,OUTPUT);
  pinMode(In4,OUTPUT);
  pinMode(EnA,OUTPUT);
  pinMode(EnB,OUTPUT);
  digitalWrite(S,HIGH);
}
void loop()
{
  Xv=analogRead(X);
  Yv=analogRead(Y);
  Sv=digitalRead(S);
  Serial.println(Xv);
  Serial.println(Yv);
  Serial.println(Sv);
  delay(500);
  a=(Xv-512);
  b=(Yv-512);
  if(a<=0){
    digitalWrite(EnA,-a/2);
    digitalWrite(EnB,-b/2);
    digitalWrite(In1,LOW);
    digitalWrite(In2,HIGH);
    digitalWrite(In3,LOW);
    digitalWrite(In4,HIGH);
  }
}
