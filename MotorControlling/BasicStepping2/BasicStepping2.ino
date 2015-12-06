/* This example shows basic use of the AMIS-30543 stepper motor
  driver.
  It shows how to initialize the driver, set the current limit, set
  the micro-stepping mode, and enable the driver.  It shows how to
  send pulses to the NXT/STEP pin to get the driver to take steps
  and how to switch directions using the DIR pin.  The DO pin is
  not used and does not need to be connected.
  Before using this example, be sure to change the
  setCurrentMilliamps line to have an appropriate current limit for
  your system.  Also, see this library's documentation for
  information about how to connect the driver:
    http://pololu.github.io/amis-30543-arduino/
*/

#include <SPI.h>
#include <AMIS30543.h>

const uint8_t amisSlaveSelect = 4;  //CS
const uint8_t amisDirPin1 = 2;      //Dir
const uint8_t amisDirPin2 = 6;      //Dir
const uint8_t amisDirPin3 = 8;      //Dir
const uint8_t amisStepPin1 = 3;     //Step
const uint8_t amisStepPin2 = 5;
const uint8_t amisStepPin3 = 7;


int m1_angle = 270;   //angle (degrees) for motor 1 to rotate
int m2_angle = 180;
int m3_angle = 90;

AMIS30543 stepper;

void setup()
{
  //Serial Print
  Serial.begin(9600);
  Serial.println();
  SPI.begin();
<<<<<<< HEAD
  //stepper.init(amisSlaveSelect);

  char myChar = 'A';
=======
  stepper.init(amisSlaveSelect);
>>>>>>> origin/master

  // Drive the NXT/STEP and DIR pins low initially.
  digitalWrite(amisStepPin1, LOW);
  pinMode(amisStepPin1, OUTPUT);
  digitalWrite(amisStepPin2, LOW);
  pinMode(amisStepPin2, OUTPUT);
  digitalWrite(amisStepPin3, LOW);
  pinMode(amisStepPin3, OUTPUT);
  digitalWrite(amisDirPin1, LOW);
  pinMode(amisDirPin1, OUTPUT);
  digitalWrite(amisDirPin2, LOW);
  pinMode(amisDirPin2, OUTPUT);
  digitalWrite(amisDirPin3, LOW);
  pinMode(amisDirPin3, OUTPUT);
  
  // Give the driver some time to power up.
  delay(1);

  // Reset the driver to its default settings.
  stepper.resetSettings();

  // Set the current limit.  You should change the number here to
  // an appropriate value for your particular system.
  stepper.setCurrentMilliamps(1000);

  // Enable the motor outputs.
  stepper.enableDriver();
}

void loop()
{

  setDirection(0);
  TurnTurnTurn(amisStepPin1, m1_angle);
  TurnTurnTurn(amisStepPin2, m2_angle);
  TurnTurnTurn(amisStepPin3, m3_angle);
/*
  //MOTOR 1
  // Set the number of microsteps that correspond to one full step.
  int StepMode = 4;
  stepper.setStepMode(StepMode);
  
  int m1_microsteps = AngleConversion(m1_angle, StepMode);
  Serial.print(m1_microsteps, DEC);
  Serial.println();

  for (unsigned int x = 0; x < m1_microsteps; x++)
  {
    step(amisStepPin1);
  }

  // Wait for 300 ms.
<<<<<<< HEAD
  //delay(300);
=======
  delay(10000);
*/
>>>>>>> origin/master

}

// Sends a pulse on the NXT/STEP pin to tell the driver to take
// one step, and also delays to control the speed of the motor.
void step(byte amisStepPinX)
{
  // The NXT/STEP minimum high pulse width is 2 microseconds.
<<<<<<< HEAD
  digitalWrite(amisStepPin1, HIGH);
  delayMicroseconds(3);
  digitalWrite(amisStepPin1, LOW);
  delayMicroseconds(3);
  digitalWrite(amisStepPin2, HIGH);
  delayMicroseconds(3);
  digitalWrite(amisStepPin2, LOW);
  delayMicroseconds(3);
=======
  {
    digitalWrite(amisStepPinX, HIGH);
    delayMicroseconds(3);
    digitalWrite(amisStepPinX, LOW);
    delayMicroseconds(3);
  }
>>>>>>> origin/master


  // The delay here controls the stepper motor's speed.  You can
  // increase the delay to make the stepper motor go slower.  If
  // you decrease the delay, the stepper motor will go fast, but
  // there is a limit to how fast it can go before it starts
  // missing steps.
  delayMicroseconds(1000);
}

// Writes a high or low value to the direction pin to specify
// what direction to turn the motor.
void setDirection(bool dir)
{
  // The NXT/STEP pin must not change for at least 0.5
  // microseconds before and after changing the DIR pin.
  delayMicroseconds(1);
  digitalWrite(amisDirPin1, dir);
  digitalWrite(amisDirPin2, dir);
  digitalWrite(amisDirPin3, dir);
  delayMicroseconds(1);
}

float AngleConversion (int angle, int StepMode)
{
  float microsteps;
  microsteps = angle/(0.18/StepMode);
  return microsteps;
}

void TurnTurnTurn(int amisStepPin, int mX_angle)
  {
  // Set the number of microsteps that correspond to one full step.
  int StepMode = 1;
  stepper.setStepMode(StepMode);
  
  int mX_microsteps = AngleConversion(mX_angle, StepMode);
  Serial.print(mX_microsteps, DEC);
  Serial.println();

  for (unsigned int x = 0; x < mX_microsteps; x++)
  {
    step(amisStepPin);
  }

  // Wait for 300 ms.
  //delay(300);
  }
