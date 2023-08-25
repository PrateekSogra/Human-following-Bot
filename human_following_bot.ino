#include <Servo.h>
//Servo Motor connections
#define Servo_PWM 3 
#define   LEFT A0
#define   RIGHT A3

long duration;
int distance;

const int echoPin = A1;
const int trigPin = A2;

long time;
Servo MG995_Servo;

// Motor A connections
int enA = 13;
int in1 = 12;
int in2 = 11;
// Motor B connections
int enB = 13;
int in3 = 9;
int in4 = 8;
// Motor A connections
int enC = 10;
int in5 = 7;
int in6 = 6;
// Motor A connections
int enD = 10;
int in7 = 5;
int in8 = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(enA, OUTPUT);
	pinMode(enB, OUTPUT);
  pinMode(enC, OUTPUT);
	pinMode(enD, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
  pinMode(in5, OUTPUT);
	pinMode(in6, OUTPUT);
	pinMode(in7, OUTPUT);
	pinMode(in8, OUTPUT);

  digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
  digitalWrite(in5, LOW);
	digitalWrite(in6, LOW);
	digitalWrite(in7, LOW);
	digitalWrite(in8, LOW);

  MG995_Servo.attach(Servo_PWM);

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input

  
  pinMode(RIGHT,  INPUT);
  pinMode(LEFT, INPUT);

  Serial.begin(9600);
}

//forward
void forward(){
  analogWrite(enA, 255);
	analogWrite(enB, 255);
  analogWrite(enC, 255);
	analogWrite(enD, 255);
  digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
  digitalWrite(in5, HIGH);
	digitalWrite(in6, LOW);
	digitalWrite(in7, HIGH);
	digitalWrite(in8, LOW);
}

void backward(){
  analogWrite(enA, 255);
	analogWrite(enB, 255);
  analogWrite(enC, 255);
	analogWrite(enD, 255);
  digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);
  digitalWrite(in5, LOW);
	digitalWrite(in6, HIGH);
	digitalWrite(in7, LOW);
	digitalWrite(in8, HIGH);
}

void turnRight(){
  analogWrite(enA, 255);
	analogWrite(enB, 255);
  analogWrite(enC, 255);
	analogWrite(enD, 255);
  digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);

	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);

  digitalWrite(in5, HIGH);
	digitalWrite(in6, LOW);

	digitalWrite(in7, LOW);
	digitalWrite(in8, HIGH);
}

void turnLeft(){
  analogWrite(enA, 255);
	analogWrite(enB, 255);
  analogWrite(enC, 255);
	analogWrite(enD, 255);
  digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);

	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);

  digitalWrite(in5, HIGH);
	digitalWrite(in6, LOW);

	digitalWrite(in7, LOW);
	digitalWrite(in8, HIGH);
}

void stop(){
  digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
  digitalWrite(in5, LOW);
	digitalWrite(in6, LOW);
	digitalWrite(in7, LOW);
	digitalWrite(in8, LOW);
}
	
void servocontrol(){
  MG995_Servo.write(0); //Turn clockwise at high speed
  delay(3000);
  MG995_Servo.detach();
  delay(2000);
  MG995_Servo.attach(Servo_PWM);
  MG995_Servo.write(180);
  delay(3000);
  MG995_Servo.detach();
  delay(2000);
  MG995_Servo.attach(Servo_PWM);
}

// long read_cm(){
//   digitalWrite(trigpin, LOW);
//   delayMicroseconds(2);
//   digitalWrite(trigpin,   HIGH);
//   delayMicroseconds(10);
//   time = pulseIn (echopin, HIGH);
//   return  ( time / 2) / 29.1;
// }

void loop() {
  // put your main code here, to run repeatedly

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2) ;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance= duration*0.034/2;
  Serial.println(distance);
  int  Right_Value = digitalRead(RIGHT);
  int Left_Value  = digitalRead(LEFT);

  
  if((Right_Value==0) && (distance>=10  && distance<=300)&&(Left_Value==0)){forward();}
  else if((Right_Value==0) && (Left_Value==1)){turnRight();}
  else  if((Right_Value==1) && (Left_Value==0)){turnLeft();}
  else if((Right_Value==1)  && (Left_Value==1)){stop();}
  //  else if(distance > 5 && distance < 10){stop();}
  else  if(distance < 5){backward();}

  delay(50);

  // forward();
  // delay(1000);
  // backward();
  // delay(1000);
  // turnRight();
  // delay(1000);
  // turnLeft();

  delay(500);
  // scan from 0 to 180 degrees
  // servocontrol();
}


