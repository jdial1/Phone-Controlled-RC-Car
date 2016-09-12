#include <AFMotor.h>

AF_DCMotor backmotor(4);
AF_DCMotor frontmotor(1);

void setup() {
	pinMpode(A0, INPUT);//forward
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
	
	boolean Forward = false;
	boolean Backward = false;
	boolean Left = false;
	boolean Right = false;
	
	if (analogRead(A0)>voltCap){Forward=true;}
	if (analogRead(A1)>voltCap){Backward=true;}
	if (analogRead(A2)>voltCap){Left=true;}
	if (analogRead(A3)>voltCap){Right=true;}
	
	//forward left
	if (Forward&&Left){moveLeftForward();}
	//forward right
	else if (Forward&&Right){moveRightForward();}
	//forward
	else if (Forward){moveForward();}
	//backward left
	else if (Backward&&Left){moveLeftBackward();}
	//backward right
	else if (Backward&&Right){moveRightBackward();}
	//backward
	else if (Backward){moveBackward();}
	//no input release
	else{backmotor.run(RELEASE);frontmotor.run(RELEASE);}
}


//forward methods
void moveForward(){
	backmotor.run(RELEASE);
    	delay(5);
	backmotor.run(FORWARD);
}

//backward methods
void moveBackward(){
	backmotor.run(RELEASE);
	delay(5);
	backmotor.run(BACKWARD);
}

//turn methods
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

//complex moves
void moveLeftForward(){
	turnLeft();
	moveForward();
	frontmotor.run(RELEASE);
}

void moveRightForward(){
	turnRight();
	moveForward();
	frontmotor.run(RELEASE);
}

void moveLeftBackward(){
	turnLeft();
	moveBackward();
	frontmotor.run(RELEASE);
}

void moveRightBackward(){
	turnRight();
	moveBackward();
	frontmotor.run(RELEASE);
}
