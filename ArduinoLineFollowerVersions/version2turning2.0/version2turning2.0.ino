
int m1_b=5;//Motor1  L298 Pin in1
int m1_f=10; 
int m2_b=6; //Motor1  L298 Pin in1 
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
//Serial.begin(9600);
}
void loop(){  
  
if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 0)){
  //Serial.println("case 1");
  forward();}   //if Right Sensor and Left Sensor are at White color then it will call forword function

else if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 0)){
  //Serial.println("case 2");
  delay(70);
  turnRight();} //if Right Sensor is Black and Left Sensor is White then it will call turn Right function  
 
else if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 1)){
  //Serial.println("case 3");
  delay(70);
  turnLeft();
  }  //if Right Sensor is White and Left Sensor is Black then it will call turn Left function

else if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 1)){
  
  Stop();
}
}

void forward(){ 

ch='Z';
analogWrite(m1_f,80);
analogWrite(m1_b,0);
analogWrite(m2_f,80); //Left Motor forword Pin 
analogWrite(m2_b,0); //Left Motor forword Pin 
}

void turnRight(){ //turnRight

ch='R';

analogWrite(m1_f,0);
analogWrite(m1_b,0);
analogWrite(m2_f,0); //Left Motor forword Pin 
analogWrite(m2_b,0);
delay(100);

while(digitalRead(L_S)!=1){
  
analogWrite(m1_f,120);
}
analogWrite(m1_f,0);

}

void turnLeft(){ //turnLeft

ch='L';

analogWrite(m1_f,0);
analogWrite(m1_b,0);
analogWrite(m2_f,0); //Left Motor forword Pin 
analogWrite(m2_b,0);
delay(100);
while(digitalRead(R_S)!=1){

analogWrite(m2_f,120);

}
analogWrite(m2_f,0);

}

void Stop(){ //stop
if(ch=='L'){
analogWrite(m1_f,0);
analogWrite(m1_b,0);
analogWrite(m2_f,0); //Left Motor forword Pin 
analogWrite(m2_b,0);
delay(100);
 analogWrite(m2_b,80);
 analogWrite(m1_f,100);
 delay(300);
 analogWrite(m2_b,0);
 analogWrite(m1_f,0);

}

if(ch=='R'){
analogWrite(m2_f,0);
analogWrite(m2_b,0);
analogWrite(m1_f,0); //Left Motor forword Pin 
analogWrite(m1_b,0);
delay(100);
analogWrite(m1_b,80);
analogWrite(m2_f,100);
delay(250);

analogWrite(m1_b,0);
analogWrite(m2_f,0);



}

}