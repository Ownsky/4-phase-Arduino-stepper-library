#include "Arduino.h"
#include "stepperMotor.h"

stepperMotor::stepperMotor(uint stepsPerLap, uchar p1, uchar p2, uchar p3, uchar p4) {
  m_stepsPerLap = stepsPerLap;
  pin1 = p1; pinMode(p1, OUTPUT);
  pin2 = p2; pinMode(p2, OUTPUT);
  pin3 = p3; pinMode(p3, OUTPUT);
  pin4 = p4; pinMode(p4, OUTPUT);
  writePin(0x0);
}

void stepperMotor::writePin(uchar a) {
  digitalWrite(pin1, a % 2);
  digitalWrite(pin2, (a /= 2) % 2);
  digitalWrite(pin3, (a /= 2) % 2);
  digitalWrite(pin4, (a /= 2) % 2);
}

void stepperMotor::rotate(uchar rDirection, uint rDelay, uint rShots) {
  const uchar* rd =rDirection ? CWsteps : CCWsteps;
  uchar t = 0;
  while (rShots>0){
    t = (t > 7) ? (t % 8) : t;
    writePin(rd[t]);
    delayMicroseconds(rDelay);
    rShots--;
    t++;
  }
}

void stepperMotor::rotate45deg(uint times, bool rDirection, uint rSpeed) {
  const uchar* rd = rDirection ? CWsteps : CCWsteps;
  uint shotDelay = (double)3e7 / rSpeed / m_stepsPerLap;
  uint loopTime = m_stepsPerLap / 32.0 * times;
  for (uint i = 0; i < loopTime; i++) {
	  for (uchar j = 0; j < 8; j++) {
	    writePin(rd[j]);
	    delayMicroseconds(shotDelay);
	  }
  }
}

void stepperMotor::rotateLap(uint times, bool rDirection, uint rSpeed) {
  const uchar* rd = rDirection ? CWsteps : CCWsteps;
  uint shotDelay = (double)3e7 / rSpeed / m_stepsPerLap;
  uint loopTime = m_stepsPerLap / 4.0 * times;
  for (uint i = 0; i < loopTime; i++) {
    for (uchar j = 0; j < 8; j++) {
      writePin(rd[j]);
      delayMicroseconds(shotDelay);
    }
  }
}

void stepperMotor::rotateDeg(double deg, bool rDirection, uint rSpeed) {
  uint shotDelay = (double)3e7 / rSpeed / m_stepsPerLap;
  uint loopTime = m_stepsPerLap * deg / 180.0;
  rotate(rDirection, shotDelay, loopTime);
}

void stepperMotor::rotateRad(double rad, bool rDirection, uint rSpeed) {
  uint shotDelay = (double)3e7 / rSpeed / m_stepsPerLap;
  uint loopTime = m_stepsPerLap * rad / PI;
  rotate(rDirection, shotDelay, loopTime);
}

void stepperMotor::rotateShot(uint rShot, bool rDirection, uint rSpeed) {
  uint shotDelay = (double)3e7 / rSpeed / m_stepsPerLap;
  rotate(rDirection, shotDelay, rShot);
}

void stepperMotor::sing(uint freq, double duration) {
  uint halfT = (double)5e5 / freq;
  for (uint i = 0; (double)i * halfT * 2 < duration; i++) {
    writePin(0b1100);
    delayMicroseconds(halfT);
    writePin(0b0011);
    delayMicroseconds(halfT);
  }
}

