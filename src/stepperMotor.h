//4-phase 8-shot stepper motor driver by Ownsky 4*64*8
#ifndef stepperMotor_h
#define stepperMotor_h

#include "Arduino.h"
#define uchar unsigned char
#define uint unsigned int
#define CW 0
#define CCW 1
class stepperMotor {
  private:
    uchar pin1, pin2, pin3, pin4;
    uint m_stepsPerLap;
    void rotate(uchar rDirection, uint rDelay, uint rShots); //旋转一定拍数的实现

  public:
    const uchar CCWsteps[8] = {0x1, 0x3, 0x2, 0x6, 0x4, 0xC, 0x8, 0x9}; //逆时针旋转引脚值
    const uchar CWsteps[8] = {0x8, 0xC, 0x4, 0x6, 0x2, 0x3, 0x1, 0x9}; //顺时针旋转引脚值
    enum PITCH {
      lDo = 262, lRe = 294, lMi = 330, lFa = 349, lSo = 392, lLa = 440, lSi = 494,
      mDo = 523, mRe = 587, mMi = 659, mFa = 698, mSo = 784, mLa = 880, mSi = 988,
      hDo = 1047, hRe = 1175, hMi = 1319, hFa = 1397, hSo = 1568, hLa = 1760, hSi = 1967
    }; //C调音阶

    //构造函数,设定每圈步数及控制引脚(此驱动每两拍为一步)
    //Constructor, set the steps per lap and control pins. (two shots for one step)
    stepperMotor(uint stepsPerLap, uchar p1, uchar p2, uchar p3, uchar p4); 

    void writePin(uchar a); //写引脚值

    //转45deg(PI/4rad). times:旋转次数; rDirection:旋转方向(CW/CCW); rSpeed:转速(rpm)
    //Rotate 45deg(PI/4rad) for given times.
    void rotate45deg(uint times, bool rDirection, uint rSpeed); 

    //转一圈. times:旋转次数; rDirection:旋转方向(CW/CCW); rSpeed:转速(rpm)
    //Rotate given laps.
    void rotateLap(uint times, bool rDirection, uint rSpeed); 

    //转给定角度. deg:旋转角度; rDirection:旋转方向(CW/CCW); rSpeed:转速(rpm)
    //Rotate given degrees.
    void rotateDeg(double deg, bool rDirection, uint rSpeed);

    //转给定弧度. rad:旋转弧度; rDirection:旋转方向(CW/CCW); rSpeed:转速(rpm)
    //Rotate given radians.
    void rotateRad(double rad, bool rDirection, uint rSpeed);

    //转给定拍数. rShot:旋转拍数; rDirection:旋转方向(CW/CCW); rSpeed:转速(rpm)
    //两拍为一步！
    //Rotate given shots. (two shots for one step)
    void rotateShot(uint rShot, bool rDirection, uint rSpeed);

    //arguments: freq(Hz); duration(us)
    void sing(uint freq, double duration);
    // void sing(uint freqStart, uint freqEnd, uint duration);
};

#endif