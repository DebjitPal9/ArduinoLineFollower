
int m1_b=5;//Motor1  L298 Pin in1
int m1_f=10; 
int m2_b=6; //Motor1  L298 Pin in1 
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
if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 0))
{}
else
return ;
analogWrite(m1_f,150);
analogWrite(m1_b,0);
analogWrite(m2_f,150); //Left Motor forword Pin 
analogWrite(m2_b,0); //Left Motor forword Pin 
}

void turnRight(){ //turnRight
ch='R';
analogWrite(m1_f,0);
analogWrite(m1_b,0);
analogWrite(m2_f,0); //Left Motor forword Pin 
analogWrite(m2_b,150);
delay(250);
analogWrite(m1_f,150);
analogWrite(m1_b,0);
analogWrite(m2_f,0); //Left Motor forword Pin 
analogWrite(m2_b,0);
delay(300);

//delay(1000);
}

void turnLeft(){ //turnLeft
ch='L';
analogWrite(m1_f,0);
analogWrite(m1_b,150);
analogWrite(m2_f,0); //Left Motor forword Pin 
analogWrite(m2_b,0);
delay(250);
analogWrite(m1_f,0);
analogWrite(m1_b,0);
analogWrite(m2_f,150); //Left Motor forword Pin 
analogWrite(m2_b,0);
delay(300);

//delay(1000);
}

void Stop(){ //stop
for(i=0;i<1;i++){
if(ch=='L')
turnLeft();
if(ch=='R')
turnRight();
}
/*if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 1))
{}
else
{return;}*/
analogWrite(m1_f,0);
analogWrite(m1_b,0);
analogWrite(m2_f,0); //Left Motor forword Pin 
analogWrite(m2_b,0);
ch='Z';
i=0;
}