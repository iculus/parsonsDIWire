


/* DIWire Bender
 * 3D Wire Bender by Pensa - www.PensaNYC.com
 * Written by Marco Perry. Email DIWire@PensaNYC.com for questions.
 * Drives on 3 Stepper Motors to bender wire in 3D space
 *
 * This file is part of the DIWire project. This is the Arduion firmware for 2D or 3D bends
 *
 *  DIWire is a free software & hardware device: you can redistribute it and/or modify
 *  it's software under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 3 of the License.
 *   
 *  The hardware portion is licenced under the Creative Commons-Attributions-Share Alike License 3.0
 *  The CC BY SA licence can be seen here: http://creativecommons.org/licenses/by-sa/3.0/us/
    

 *  DIWIre is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License and CC-BY-SA for more details.

 *  You should have received a copy of the GNU General Public License
 *  along with DIWire.  If not, see <http://www.gnu.org/licenses/>. 
 *  and http://creativecommons.org/licenses/by-sa/3.0/us/legalcode
 *  
 *  No portion of this header can be removed from the code. 
 *  Now enjoy and start making something!
 */

/*This program is to be uploaded onto the DIWire  arduino. 
 Bend angles and feed lengths are imported from processing running on a computer plugged into the arduino. 
 This program takes these lengths and angles and moves the motors and solenoid accordingly.
 */

/*
 * Feed Motor 1 - drives wire
 * z Bend Motor - performs 3D bends by rotating entire assembly
 * bend Motor - performs 2D bends by bending wire over
 * benderPin - solenoid
 */


#include <SPI.h>
#include <AMIS30543.h>

const uint8_t amisDirPin1 = 2;      //Dir
const uint8_t amisDirPin2 = 6;      //Dir
const uint8_t amisDirPin3 = 8;      //Dir
const uint8_t amisStepPin1 = 3;     //Step
const uint8_t amisStepPin2 = 5;
const uint8_t amisStepPin3 = 7;

// pin assignments
// Motor pulse and solenoid pins
const int bendMotorPls = 7;
const int zMotorPls = 5;
const int feedMotorPls = 3;
const int benderPin = 12;  //update later

// AWO pins to allow motor shaft to free spin TIM DONT KNOW maybe resolution wires?
const int bendMotorAWO = 3;
const int zMotorAWO = 4;
const int feedMotorAWO = 5;

// Direction pins to select drive direction
const int bendMotorDir = 8;
const int zMotorDir = 6;
const int feedMotorDir = 2;

const uint8_t amisSlaveSelect = 4;  //CS added by tim

//misc program constants
const int pulseWidth = 20;
const int pulseDelay = 700;
const int zPulseDelay = 200;

// Drive directions in english
boolean ccw = true; // counter-clockwise drive direction
boolean cw = false; // clockwise drive direction
boolean curDir = cw; // resets direction before next angle command 

int lastbend = 0;
int fieldindex=0;
int values[300]; //creates array

//used in motorrun() function as a marker
int feedMotorMarker =126; 
int bendMotorMarker =125; 
int zMotorMarker =124;
 
void setup() {
  Serial.begin (9600); //com port communication
  pinMode (bendMotorPls, OUTPUT); //Declaring motor pins as out
  pinMode (zMotorPls, OUTPUT); 
  pinMode (feedMotorPls, OUTPUT); 
  pinMode (bendMotorAWO, OUTPUT); 
  pinMode (zMotorAWO, OUTPUT); 
  pinMode (feedMotorAWO, OUTPUT); 
  pinMode (bendMotorDir, OUTPUT);
  pinMode (zMotorDir, OUTPUT); 
  pinMode (feedMotorDir, OUTPUT); 
  pinMode (benderPin, OUTPUT); 
  digitalWrite (bendMotorPls, LOW); //starts with everything off
  digitalWrite (zMotorPls, LOW); 
  digitalWrite (feedMotorPls, LOW); 
  digitalWrite (benderPin, LOW);
  digitalWrite (zMotorAWO, HIGH);
  digitalWrite (feedMotorAWO, HIGH);
  digitalWrite (bendMotorAWO, HIGH);

 //Stepper Motor Initialization
  AMIS30543 stepper;
  stepper.init(amisSlaveSelect);      //SPI communication for stepper driver boards
  delay(1);                           // Give the driver some time to power up.
  stepper.resetSettings();            // Reset the driver to its default settings.
  // Set the current limit.  You should change the number here to
  // an appropriate value for your particular system.
  stepper.setCurrentMilliamps(1000);
  // Enable the motor outputs.
  stepper.enableDriver();
  
}

void loop() {
  int copies = 0;
  while (Serial.available ()){ //starts once serial entry made
    digitalWrite (bendMotorAWO, LOW);
    digitalWrite (zMotorAWO, LOW);
    digitalWrite (feedMotorAWO, LOW);

    int in = Serial.read();
    byte incoming = in+128; //converts bytes from processing
    if (incoming != 255){   //255 signifies end of incoming array
      Serial.println (Serial.read());
      values[fieldindex] = values[fieldindex]*10+incoming; //fills array fieldindex from incoming processing
      fieldindex++;
    }
    else{
      Serial.println("END");     //if array end marker inputs from processing end
      for (int i=0; i<=fieldindex;i++){
        Serial.println(values[i]-128);
      }
      copies=copies+1;
    }
  }
  if (copies==1){ //once bend is complete eject shape
    delay (1000);
    motorrun();
    feed(50); //eject 
    copies=copies+1;
  }
}

void motorrun(){
  int lastbend=0;
  for (int i=0; i<= fieldindex;i++){
    delay (100);
    if ((values[i]-128)==feedMotorMarker){ //convert bytes from processing and look for feed motor marker
      feed (values[i+1]-128);  //if feed motor marker detected next value in array is a feed length
    }
    else if ((values[i]-128)==bendMotorMarker){ //convert bytes from processing and look for bend motor marker
      int bendAng = (values[i+1]-128);  //if bend motor marker detected next value in array is a bend angle
      if ((bendAng<0&&curDir==cw) || (bendAng>0 && curDir ==ccw)){ //if incoming bend angle is opposite direction from previous angle duck pin
        duck ();
        delay (100);
      }
      bend (bendAng);
      lastbend = bendAng;
    }
    else if ((values[i]-128)==zMotorMarker){ //convert bytes from processing and look for z motor marker
      zbend (values[i+1]-128);  //if z motor marker detected next value in array is z bend angle
    }
  }
}





