#4-Phase 8-Shot Stepper Motor Driver Library for Arduino
An arduino library designed for 4-phase stepper motor. 8-shot control mode, which means 2 shots for 1 step.
Function 'sing' makes motor ring in given frequency.
##Available Motors
4-phase stepper motor such as 28BYJ-48. The example is written for this motor.
##Initialize

**Function**
```C++
stepperMotor::stepperMotor(uint stepsPerLap, uchar p1, uchar p2, uchar p3, uchar p4)
```

**Argument**
> |Argument       |Illustration                 |
> |---------------|-----------------------------|
> |*stepsPerLap* |Steps needed to rotate a lap.|
> |*p1~p4*       |Control pins.                |

##Functions
```C++
void stepperMotor::writePin(uchar a)
```
>- **Usage** 
>  Set control pins directly with a binary. For example, 0b0101(0x5) sets pin1 to pin4 with HIGH, LOW, HIGH, LOW. 
>- **Argument**
> |Argument       |Illustration                 |
> |---------------|-----------------------------|
> |*a*            | Signal to write.            |

```C++
void stepperMotor::rotate45deg(uint times, bool rDirection, uint rSpeed)
void stepperMotor::rotateLap(uint times, bool rDirection, uint rSpeed)
void stepperMotor::rotateDeg(double deg, bool rDirection, uint rSpeed)
void stepperMotor::rotateRad(double rad, bool rDirection, uint rSpeed)
void stepperMotor::rotateShot(uint rShot, bool rDirection, uint rSpeed)
```
>- **Usage**
>  Rotate the motor for given times of 45 degrees, laps, degrees or radians.
>- **Argument**
> |Argument       |Illustration                 |
> |---------------|-----------------------------|
> |*times, deg, rad, rshot* |Times for each rotation unit.|
> |*rDirection* |Direction for the rotation. Defination: CW/CCW. See part Macros&Values.|
> |*rSpeed:* |Speed for the rotation. Unit: rpm.|

```C++
void stepperMotor::sing(uint freq, double duration)
```
>- **Usage**
>  Make the motor ring.
>- **Argument**
> |Argument       |Illustration                 |
> |---------------|-----------------------------|
> |*freq:* |The frequency motor rings in. There are some given frequency in C. See part Macros&Values.|
> |*duration:* |The length motor rings.|

##Macros&Values
###Macros
```C++
#define uchar unsigned char
#define uint unsigned int
#define CW 0    //clockwise
#define CCW 1   //counter-clockwise
```

###Values
```C++
const uchar CCWsteps[8] = {0x1, 0x3, 0x2, 0x6, 0x4, 0xC, 0x8, 0x9}; 
const uchar CWsteps[8] = {0x8, 0xC, 0x4, 0x6, 0x2, 0x3, 0x1, 0x9}; 
enum PITCH {
lDo = 262, lRe = 294, lMi = 330, lFa = 349, lSo = 392, lLa = 440, lSi = 494,
mDo = 523, mRe = 587, mMi = 659, mFa = 698, mSo = 784, mLa = 880, mSi = 988,
hDo = 1047, hRe = 1175, hMi = 1319, hFa = 1397, hSo = 1568, hLa = 1760, hSi = 1967
};  
```
>- **Note**
>  *CCWsteps:* Signal for counter-clockwise rotation.
>  *CWsteps:* Signal for clockwise rotation.
>  *PITCH:* Scale in C. Do, Re .. Si with prefix l, m or h.

##Other Detailed Usage
See example program.

##Must Read
This library is not absolutely accurate and stable. Do not use this in industrial grade program. Detailed information of the installation of the library, please refer to: http://arduino.cc/en/Guide/Libraries

