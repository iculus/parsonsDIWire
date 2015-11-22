void moveMotor (int pinAssignment, int timingWidth, int timingDelay)
  {
    digitalWrite (pinAssignment, HIGH);
    delayMicroseconds (timingWidth);
    digitalWrite (pinAssignment, LOW);
    delayMicroseconds (timingDelay);
    
  }
