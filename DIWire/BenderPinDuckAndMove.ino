void rotatePin (boolean dir, float angle) { //moves bender pin during duck. direction specified from duck subroutine
  int bendRotationAngle = 6000;
  
  float rotations = 0;
  angle = bendRotationAngle * (angle/360); //converts angle to steps //BendRotationAngle used to be 6000
  rotations = angle;
  Serial.println (dir);
  digitalWrite (bendMotorDir, dir);  
  
  
  
  //for (int i=0; i <=rotations  ; i++){ //rotates bender motor appropriate number of steps
    //digitalWrite(bendMotorPls, HIGH);
    //delayMicroseconds (pulseWidth);
    //digitalWrite(bendMotorPls, LOW);
    //delayMicroseconds (pulseDelay);

  moveMotor(bendMotorPls, pulseWidth, pulseDelay, rotations);
  //}
}

void duck (){  //ducks bender pin under wire
  digitalWrite (benderPin, HIGH); 
  delay (100);
  rotatePin (curDir, 45);
  digitalWrite (benderPin, LOW);  //pin down move under wire
  curDir = !curDir;    //direction reversed for next duck
}

