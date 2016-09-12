#include <AFMotor.h>

AF_DCMotor backmotor(4);
AF_DCMotor frontmotor(1);

void setup() {
  pinMode(A0, INPUT);//forward
  pinMode(A1, INPUT);//backward
  pinMode(A2, INPUT);//left
  pinMode(A4, INPUT);//right

  int voltCap=0;
  int voltSum=0;
  
  //get analogReads of each 4 10x
   for (int i=0; i <= 10; i++){
	voltSum = voltSum +analogRead(A0)+analogRead(A1)+analogRead(A2)+analogRead(A4);
	delay(500);
   } 
   
   //divide total by 40 to get average and add 50
   voltCap=(voltAverage/40)+50;
   
   //set speeds of motors
   backmotor.setSpeed(255);
   frontmotor.setSpeed(150);

  
   //turn left twice to show setup is complete
   frontmotor.run(BACKWARD);
   delay(250);
   backmotor.run(RELEASE);
   delay(250);
   backmotor.run(BACKWARD);
   delay(250);
   backmotor.run(RELEASE);
   frontmotor.run(RELEASE);
}

void loop() {
	for (int i=0; i < 5; i++){
		if (analogRead("A"+i)>voltCap){
			switch(i){
				case 0:moveForward();break;
				case 1:moveBackward();break;
				case 2:turnLeft();break;
				case 3:break;//left empty too much interference
				case 4:turnRight();break;
				default:backmotor.run(RELEASE);frontmotor.run(RELEASE);break;	
			}
		}
   } 
}



void moveForward(){
	backmotor.run(RELEASE);
	 delay(5);
	 backmotor.run(FORWARD);
}

void moveBackward(){
	backmotor.run(RELEASE);
	delay(5);
	backmotor.run(BACKWARD);
}

void turnLeft(){
	frontmotor.run(RELEASE);
	 delay(5);
	frontmotor.run(BACKWARD);
}

void turnRight(){
	frontmotor.run(RELEASE);
	delay(5);
	frontmotor.run(FORWARD);
}
