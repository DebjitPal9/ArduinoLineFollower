
int m1_b=5;//Motor1  left motor
int m1_f=10; 
int m2_b=6; //Motor2  right motor 
int m2_f=11;
char ch='Z';
int i=0;
#define R_S A0 //ir sensor Right
#define L_S A1 //ir sensor Left

void setup(){ // put your setup code here, to run once

pinMode(R_S, INPUT); // declare if sensor as input  
pinMode(L_S, INPUT); // declare ir sensor as input


pinMode(m1_f, OUTPUT); 
pinMode(m2_f, OUTPUT); 
pinMode(m2_b, OUTPUT); 
pinMode(m1_b, OUTPUT);  
Serial.begin(9600);
}
void loop(){  
  
if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 0)){
  Serial.println("case 1");
  forward();}   //if Right Sensor and Left Sensor are at White color then it will call forword function

if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 0)){
  Serial.println("case 2");
  turnRight();} //if Right Sensor is Black and Left Sensor is White then it will call turn Right function  

if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 1)){
  Serial.println("case 3");
  turnLeft();}  //if Right Sensor is White and Left Sensor is Black then it will call turn Left function

if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 1)){
  Serial.println("case 4");
  Stop();
}
}

void forward(){ 
analogWrite(m1_f,65);
analogWrite(m2_f,65); 
analogWrite(m1_b,0);
analogWrite(m2_b,0);
}

void turnRight(){ //turnRight
ch='R';

analogWrite(m1_f,0);
analogWrite(m1_b,0);
analogWrite(m2_f,0); 
while(digitalRead(R_S)==1){
analogWrite(m2_b,65);
}
delay(180);
analogWrite(m1_f,60);
analogWrite(m1_b,0);
analogWrite(m2_f,0); 
analogWrite(m2_b,0);
delay(400);
analogWrite(m1_f,0);
if(digitalRead(R_S)==0&&digitalRead(L_S)==0){
  forward();
}
else if(digitalRead(L_S)==1&&digitalRead(R_S)==0){
  while(digitalRead(L_S)==1){
  analogWrite(m1_f,70);
  }
  analogWrite(m1_f,0);
}
}

void turnLeft(){ 
ch='L';

analogWrite(m1_f,0);
analogWrite(m2_f,0); 
analogWrite(m2_b,0); 
while(digitalRead(L_S)==1){
  analogWrite(m1_b,65);
}
delay(180);
analogWrite(m2_b,0);
analogWrite(m1_f,0);
analogWrite(m1_b,0);
analogWrite(m2_f,60); 
delay(400);
analogWrite(m2_f,0); 
if(digitalRead(L_S)==0&&digitalRead(R_S)==0){
  forward();
}
else if(digitalRead(R_S)==1&&digitalRead(L_S)==0){
  while(digitalRead(R_S)==1){
  analogWrite(m2_f,70);
  }
  analogWrite(m2_f,0);
}
}

void Stop(){ //stop
if(ch=='L'){
analogWrite(m1_f,0);
analogWrite(m2_f,0); 
analogWrite(m2_b,0);
analogWrite(m1_b,80);
delay(300);
analogWrite(m1_b,0);
while(digitalRead(R_S)==1&&digitalRead(L_S)==0){
  analogWrite(m2_f,70);
  delay(10);
}
 analogWrite(m2_f,0);
}
if(ch=='R'){
analogWrite(m2_f,0);
analogWrite(m1_f,0); 
analogWrite(m1_b,0);
analogWrite(m2_b,80);
delay(300);
analogWrite(m2_b,0);
while(digitalRead(L_S)==1&&digitalRead(R_S)==0){
  analogWrite(m1_f,70);
  delay(10);
}
analogWrite(m1_f,0);
}
}
