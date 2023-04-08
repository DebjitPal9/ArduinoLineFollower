int m1_b=5;
int m1_f=10; 
int m2_b=6;  
int m2_f=11;
char ch='L';
int i=0;
#define R_S A0
#define L_S A1 

void setup(){ // put your setup code here, to run once
  pinMode(R_S, INPUT); 
  pinMode(L_S, INPUT); 
  pinMode(m1_f, OUTPUT); 
  pinMode(m2_f, OUTPUT); 
  pinMode(m2_b, OUTPUT); 
  pinMode(m1_b, OUTPUT);  
  Serial.begin(9600);
}
void loop(){    
if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 0)){
  Serial.println("case 1");
  forward();
  }   
if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 0)){
  Serial.println("case 2");
  turnRight();
  } 
if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 1)){
  Serial.println("case 3");
  turnLeft();
  }  
if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 1)){
  Serial.println("case 4");
  Stop();
  }
}

void forward(){ 
  analogWrite(m1_f,150);
  analogWrite(m1_b,0);
  analogWrite(m2_f,150); 
  analogWrite(m2_b,0); 
}

void turnRight(){ //turnRight
  ch='R';
  analogWrite(m1_f,0);
  analogWrite(m1_b,0);
  analogWrite(m2_f,0); 
  analogWrite(m2_b,0);
  for(int j=0;j<100;j++){
    analogWrite(m2_b,j);
    delay(2);
  }
  analogWrite(m2_b,0);
  delay(10);
  for(int j=0;j<130;j++){
    analogWrite(m1_f,j);
    delay(2);
  }
  analogWrite(m1_f,0);
  delay(10);
}

void turnLeft(){ //turnLeft
  ch='L';
  analogWrite(m1_f,0);
  analogWrite(m1_b,0);
  analogWrite(m2_f,0);
  analogWrite(m2_b,0);
  for(int j=0;j<100;j++){//--->300/150
    analogWrite(m1_b,j);
    delay(2);
  }
  analogWrite(m1_b,0);
  delay(10);
  for(int j=0;j<130;j++){//--->300/150
    analogWrite(m2_f,j);
    delay(2);
  }
  analogWrite(m2_f,0);
  delay(10);
}

void Stop(){ //stop
  for(i=0;i<1;i++){
    if(ch=='L')
    turnLeft();
    if(ch=='R')
    turnRight();
  }
  analogWrite(m1_f,0);
  analogWrite(m1_b,0);
  analogWrite(m2_f,0); 
  analogWrite(m2_b,0);
  ch='Z';
  i=0;
}
