
int m1_b=5;//Motor1  left motor
int m1_f=10; 
int m2_b=6; //Motor2  right motor 
int m2_f=11;
char ch='L';
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
analogWrite(m1_f,80);
analogWrite(m2_f,80); 
analogWrite(m1_f,0);
analogWrite(m2_f,0);
}

void turnRight(){ //turnRight
ch='R';
analogWrite(m1_f,0);
analogWrite(m1_b,0);
analogWrite(m2_f,0); 
analogWrite(m2_b,80);
delay(300);
analogWrite(m1_f,80);
analogWrite(m1_b,0);
analogWrite(m2_f,0); 
analogWrite(m2_b,0);
delay(400);
analogWrite(m1_f,0);
if(R_S==0&&L_S==0){
  forward();
  delay(150);
}
else if(L_S==1&&R_S==0){
  while(L_S==1){
  analogWrite(m1_f,80);
  delay(50);
  }
}else
analogWrite(m1_f,0);
}

void turnLeft(){ 
ch='L';
analogWrite(m1_f,0);
analogWrite(m1_b,80);
analogWrite(m2_f,0);  
analogWrite(m2_b,0);
delay(300);
analogWrite(m1_f,0);
analogWrite(m1_b,0);
analogWrite(m2_f,80); 
analogWrite(m2_b,0);
delay(400);
analogWrite(m2_f,0); 
if(L_S==0&&R_S==0){
  forward();
  delay(150);
}
else if(R_S==1&&L_S==0){
  while(R_S==1){
  analogWrite(m2_f,80);
  delay(50);
  }
}
analogWrite(m2_f,0);
}

void Stop(){ //stop
if(ch=='L'){
analogWrite(m1_f,0);
analogWrite(m1_b,0);
analogWrite(m2_f,0); 
analogWrite(m2_b,0);
analogWrite(m1_b,80);
delay(300);
analogWrite(m1_b,0);
while(R_S==1&&L_S==0){
  analogWrite(m2_f,80);
  delay(50);
}
}
if(ch=='R'){
analogWrite(m2_f,0);
analogWrite(m2_b,0);
analogWrite(m1_f,0); 
analogWrite(m1_b,0);
analogWrite(m2_b,80);
delay(300);
analogWrite(m2_b,0);
while(L_S==1&&R_S==0){
  analogWrite(m1_f,80);
  delay(50);
}
analogWrite(m1_f,0);
}
}
