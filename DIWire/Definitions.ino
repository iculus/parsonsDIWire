//misc program constants
const int pulseWidth = 20;
const int pulseDelay = 700;

// Drive directions in english
boolean ccw = true; // counter-clockwise drive direction
boolean cw = false; // clockwise drive direction
boolean curDir = cw; // resets direction before next angle command 

int lastbend = 0;
int fieldindex=0;
int values[300]; //creates array

