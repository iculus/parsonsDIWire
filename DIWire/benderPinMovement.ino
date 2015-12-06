void bend (float angle) {     //bender pin movement
    int benderPinAngleA = 6000;
    int benderPinAngleB = 5960;
  
  if (angle!=0){              //sets direction of bend based on + or - angle
    Serial.println("bending");
    Serial.println(angle);
    boolean dir=cw;
    boolean back=ccw;
    if (angle<0){
      dir = ccw;
      back = cw;
    }
    float rotations = 0;
    angle = abs(angle);
    if (angle <= 90){
      angle = -.0012*angle*angle+.5959*angle+.2452; //converts angle into calibrated motor steps 
      angle = benderPinAngleA * (angle/360)+220;  //benderPinAngleA was 6000
    }
    else if (91 <= angle <= 120){
      angle = .0044*angle*angle-.5481*angle+57.981; //converts angle into calibrated motor steps 
      angle = benderPinAngleB * (angle/360)+220;
    }
    else if (121<=angle<=180){
      angle = angle-63.26;  //converts angle into calibrated motor steps 
      angle = benderPinAngleB * (angle/360)+220;
    }   //calibration will differ depending on set up 
    rotations = angle;
    // Serial.println (angle);
    digitalWrite (bendMotorDir, dir);  
    //for (int i=0; i <=rotations  ; i++){ //moves bender bin the desired angle
      
      //digitalWrite(bendMotorPls, HIGH);
      //delayMicroseconds (pulseWidth);
      //digitalWrite(bendMotorPls, LOW);
      //delayMicroseconds (pulseDelay);

    moveMotor(bendMotorPls, pulseWidth, pulseDelay, rotations);
   // }
    delay (100);
    digitalWrite (bendMotorDir, back);   //moves bender pin back to home position ready for next feed
    //for (int i=0; i <=rotations  ; i++){
      //digitalWrite(bendMotorPls, HIGH);
      //delayMicroseconds (pulseWidth);
      //digitalWrite(bendMotorPls, LOW);
      //delayMicroseconds (pulseDelay);

    moveMotor(bendMotorPls, pulseWidth, pulseDelay, rotations);
    //}
  }
}
