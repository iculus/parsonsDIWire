// Sends a pulse on the NXT/STEP pin to tell the driver to take
// one step, and also delays to control the speed of the motor.
void step(byte amisStepPinX)
{
  // The NXT/STEP minimum high pulse width is 2 microseconds.
  {
    digitalWrite(amisStepPinX, HIGH);
    delayMicroseconds(3);
    digitalWrite(amisStepPinX, LOW);
    delayMicroseconds(3);
  }


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
