void moveMotor (int pinAssignment, int timingWidth, int timingDelay, float rotations)
  {
     for (int i=0; i <=rotations  ; i++){ //rotates bender motor appropriate number of steps
        digitalWrite (pinAssignment, HIGH);
        delayMicroseconds (timingWidth);
        digitalWrite (pinAssignment, LOW);
        delayMicroseconds (timingDelay);
        }
    
  }
