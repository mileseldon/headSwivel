#include <Servo.h>
int servoPinX = 7;
int servoPinY = 8;
Servo servoX;
Servo servoY;
int angle = 0;
int serialData = 0;
int x = 0;
int y = 0;

void setup(){
  servoX.attach(servoPinX);
  servoY.attach(servoPinY);
  servoX.write(0);
  servoY.write(0);
  //delay(500);
  Serial.begin(9600);
}
void loop(){
  //w = 119
  //a = 97
  //s = 115
  //d = 100
  if (Serial.available() > 0){
    serialData = Serial.read();
    Serial.println(serialData);
    if(serialData == 49) y += 2;
    else if(serialData == 50) x -= 2;
    else if(serialData == 51) y-=2;
    else if(serialData == 52) x += 2;
    if(x > 45) x = 45;
    else if(x<-45) x = -45;
    if(y > 45) y = 45;
    else if(y < -45) y = -45;
    servoX.write(x);
    servoY.write(y);
  }
  
  /*
  //scan from 0 to 180
  if(angle == 0){
    for(angle = 0; angle < 90; angle++){
      servoX.write(angle);
      servoY.write(angle);
      delay(30);
    }
    for(angle = 90; angle > 0; angle++){
     
    }
  }*/
  
  /*
  for(angle = 90; angle > 0; angle--){
    servoX.write(angle);
    servoY.write(angle);
    delay(30);
  }*/
  /*
  for(angle = 0; angle < 90; angle++){
    servoX.write(angle);
    delay(30);
  }
  for(angle = 0; angle < 90; angle++){
    servoY.write(angle);
    delay(30);
  }
  for(angle = 90; angle > 0; angle--){
    servoX.write(angle);
    delay(30);
  }
  for(angle = 90; angle > 0; angle--){
    servoY.write(angle);
    delay(30);
  }*/
}
