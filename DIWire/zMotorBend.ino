void zbend (float angle) { //rotates z motor
  if (angle!=0){
    Serial.println("Z bending");
    Serial.println(angle);
    boolean dir=cw;
    if (angle<0){ //+ angle is clockwise - angle is counter clockwise
      dir = ccw;
    }
    float rotations = 0;
    angle = abs(angle);
    angle = (2000 * angle)/360; //converts angle to motor steps
    rotations = angle;
    digitalWrite (zMotorDir, dir);  //sets motor direction
    //for (int i=0; i <=rotations  ; i++){ //rotates z motor appropriate number of steps
      
      //digitalWrite(zMotorPls, HIGH);
      //delayMicroseconds (pulseWidth);
      //digitalWrite(zMotorPls, LOW);
      //delayMicroseconds (zPulseDelay);

    moveMotor(zMotorPls, pulseWidth, zPulseDelay, rotations);
    //}
  }
}

