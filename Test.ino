#include<PS2X_lib.h> // Declaring of the PS2 library

#define wv1p 2 //Defining the positive terminal for first motor - Digital Pin
#define wv2p 4 //Defining the positive terminal for second motor - Digital Pin
#define wv3p 7 //Defining the positive terminal for third motor - Digital Pin
#define wv1n 3 //Defining the negative terminal for the first motor - PWM Pin
#define wv2n 5 //Defining the negative terminal for the seond motor - PWM Pin
#define wv3n 6 //Defining the negative terminal for the third motor - PWM Pin

float wvArray[3]; //Declaring an array to store the PWM values in it
float theta1 = 30; //Declaring the angle of the first motor with a set reference
float theta2 = 150; //Declaring the angle of the second motor with a set reference
float theta3 = 270; //Declaring the angle of the third motor with a set reference
float angVel = 0; // Setting the angular velocity to 0
float velocity = 10; // Hard Coding the value of velocity as it doesn't matter because it will be cancelled later on

float getAngle(float x, float y); //Declaration of the function to return the angle based on the reading of the x and y coordinate of the PS2 controller

PS2X ps2x; //Declaring a object of class PS2X
int error = 0; //Initializing the value of error
byte type = 0;
byte vibrate = 0;

float getAngle(float x, float y){
  float angle; //Declaring a variable of type float to store the angle
  /* Because the function atan returns a value between -pi/2 and pi/2 in radians, we first need to 
  check which quadrant it lies in and also multiplying it by the (180/3.14) to convert in degrees*/
  if(x>128 && y > 128){
    angle = (atan((y-128)/(x-128)))*(180/3.14);
  }
  else if(((x<128)&&(x>1)) && (y>128)){
    angle = 180 - atan((y-128)/(128-x))*(180/3.14);
  }
  else if(((x<128)&&(x>1)) && ((y<128) && (y>1))){
    angle = 180 + atan((128 - y)/(128 - x))*(180/3.14);
  }
  else if(((y<128)&&(y>1)) && (x>128)){
    angle = 360 - atan((128 - y)/(x - 128))*(180/3.14);
  }
  return angle;
}

void botMove(float velocity,float angle){
  float v1,v2,v3; //Declaring the float values to calculate the individual wheel velocities
  /* The code of the matrix used based of the research paper */
  /* We have ard coded the value of velocity because the bot travels at its fastest possible velocity, we have set 
  the angVel = 0, so when we calculate the PWM value for the three motors the velocity componenet gets cancelled */
  v1 = ((-1)*sin(theta1)*(velocity)*cos(angle)) + (cos(theta1)*(velocity)*sin(angle)) + angVel;
  v2 = ((-1)*sin(theta2)*(velocity)*cos(angle)) + (cos(theta2)*(velocity)*sin(angle)) + angVel;
  v3 = ((-1)*sin(theta3)*(velocity)*cos(angle)) + (cos(theta3)*(velocity)*sin(angle)) + angVel;
  /*Calculating the PWM values for the three motors and storing them as elements in the array,the array is a 
  globally declared array and hence can be accessed anywhere in the program */
  /*We are dividing the attained velocities by the maximum velocity of the individual wheel to scale it between 0 to 1*/
  wvArray[0] = (v1/(velocity))*255;
  wvArray[1] = (v2/(velocity))*255;
  wvArray[2] = (v3/(velocity))*255;
}

void setup(){
  Serial.begin(9600);
  
  /* Setup Pins and Settings:
  GamePad(clock,command,attention,data,Pressure?,Rumble?) */
  error = ps2x.config_gamepad(13,11,10,12,true,true); //Configuring the Game Pad
  if(error == 0)
   Serial.println("Found Controller, configured successful");
  else if(error == 1)
   Serial.println("No controller found, check wiring");
  else if(error == 2)
   Serial.println("Controller found but not accepting commands");
  else if(error == 3)
   Serial.println("Controller refusing to enter Pressures mode, may not support it. ");
  
   pinMode(wv1p,OUTPUT);
   pinMode(wv2p,OUTPUT);
   pinMode(wv3p,OUTPUT);
   pinMode(wv1n,OUTPUT);
   pinMode(wv2n,OUTPUT);
   pinMode(wv3n,OUTPUT);
}

void loop(){
  float x,y,angle;
  ps2x.read_gamepad(); //reads the controller
  if(ps2x.Button(PSB_L1) || ps2x.Button(PSB_R1))
  {
    x = ps2x.Analog(PSS_RX); //Getting the x coordinate of the PS2 joystick
    y = ps2x.Analog(PSS_RY); //Getting the y coordinate of the PS2 joystick
    angle = getAngle(x,y); // Getting the angle to be passed to BotMove
    botMove(velocity,angle); //Calling the function to set values for individual wvArray elements
    if(wvArray[0] >= 0){
      digitalWrite(wv1p,HIGH);
      analogWrite(wv1n,255 - wvArray[0]);
    }
    else{
      digitalWrite(wv1p,LOW);
      analogWrite(wv1n,-1*wvArray[0]);
    }
    if(wvArray[1] >= 0){
      digitalWrite(wv2p,HIGH);
      analogWrite(wv2n,255 - wvArray[1]);
    }
    else{
      digitalWrite(wv2p,LOW);
      analogWrite(wv2n,-1*wvArray[1]);
    }
    if(wvArray[2] >= 0){
      digitalWrite(wv3p,HIGH);
      analogWrite(wv3n,255 - wvArray[2]);
    }
    else{
      digitalWrite(wv3p,LOW);
      analogWrite(wv3n,-1*wvArray[2]);
    } 
  }
}
    
