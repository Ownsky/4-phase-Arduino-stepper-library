//4-phase 8-shot stepper motor driver by Ownsky.
//This all-in-one example program is for 28BYJ-48.
//

#include <stepperMotor.h>

//Initialize for 28BYJ-48. Change this for your stepper.
stepperMotor motor1(4 * 64 * 8, 4, 5, 6, 7);

void setup() {
  
}

void loop() {
  motor1.sing(motor1.mDo, 2e5);
  motor1.sing(motor1.mRe, 2e5);
  motor1.sing(motor1.mMi, 2e5);
  motor1.writePin(0);
  delay(1000);
  motor1.rotateLap(1, CCW, 15);
  motor1.rotate45deg(3, CW, 15);
  motor1.rotateDeg(30, CCW, 15);
  motor1.rotateRad(PI / 6, CW, 15);
  motor1.rotateShot(8 * 64, CCW, 15);
  motor1.writePin(0);
  delay(1000);
}



