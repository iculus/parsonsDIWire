void feed (float dist) { //feeds wire
  int wireFeedDist = 2000;
 
  if (dist != 0){
    Serial.println("feeding");
    Serial.println(dist);
    float rotations = 0;
    float feedCalib = 25.4*PI; //feed mm per revolution of motor
    dist = wireFeedDist * dist/feedCalib;  //dist converted from mm to steps //wireFeedDist was 2000
    rotations = dist;
    digitalWrite (feedMotorDir, 1);  //feed motor only moves forward
    //for (int i=0; i <=rotations  ; i++){ //rotate feed motor appropriate number of steps 
    
     // digitalWrite(feedMotorPls, HIGH);
     // delayMicroseconds (pulseWidth);
     // digitalWrite(feedMotorPls, LOW);
     // delayMicroseconds (pulseDelay);

    
   moveMotor(feedMotorPls, pulseWidth, pulseDelay, rotations);
    //}
  }
}


