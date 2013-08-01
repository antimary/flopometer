/*
  Analog input, analog output, serial output
 
 Reads an analog input pin, maps the result to a range from 0 to 255
 and uses the result to set the pulsewidth modulation (PWM) of an output pin.
 Also prints the results to the serial monitor.
 
 The circuit:
 * potentiometer connected to analog pin 0.
   Center pin of the potentiometer goes to the analog pin.
   side pins of the potentiometer go to +5V and ground
 * LED connected from digital pin 9 to ground
 
 created 29 Dec. 2008
 modified 9 Apr 2012
 by Tom Igoe
 
 This example code is in the public domain.
 
 */

// These constants won't change.  They're used to give names
// to the pins used:
const int Xpin = A0;  // Analog input pin that the potentiometer is attached to
const int Ypin = A1;
const int Zpin = A2;
const int analogOutPin = 9; // Analog output pin that the LED is attached to

int minXValue = -1;        // value read from the pot
int minYValue = -1;
int minZValue = -1;

int maxXValue = -1;
int maxYValue = -1;
int maxZValue = -1;

int xValue = 0;
int yValue = 0;
int zValue = 0;

int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
}

void loop() {
  // read the analog in value:
  xValue = analogRead(Xpin);
  yValue = analogRead(Ypin);
  zValue = analogRead(Zpin);
  
  if (minXValue == -1 || xValue < minXValue) {
    minXValue = xValue;
    printMin();
  }
    if (minYValue == -1 || yValue < minYValue) {
    minYValue = yValue;
    printMin();
  }
    if (minZValue == -1 || zValue < minZValue) {
    minZValue = zValue;
    printMin();
  }
  
  if (maxXValue == -1 || xValue > maxXValue) {
    maxXValue = xValue;
    printMax();
  }
  if (maxYValue == -1 || yValue > maxYValue) {
    maxYValue = yValue;
    printMax();
  }
  if (maxZValue == -1 || zValue > maxZValue) {
    maxZValue = zValue;
    printMax();
  }
  // map it to the range of the analog out:
  //outputValue = map(sensorValue, 0, 1023, 0, 255);  
  // change the analog out value:
  //analogWrite(analogOutPin, outputValue);            

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(2);                     
}

void printMax() {
  Serial.println("MAX FLOP");
  Serial.print("X = ");                       
  Serial.print(maxXValue);      

  Serial.print(", Y = ");                       
  Serial.print(maxYValue);   

  Serial.print(", Z = ");                       
  Serial.println(maxZValue);  
}

void printMin() {
  Serial.println("MIN FLOP");
    Serial.print("X = ");                       
  Serial.print(minXValue);      

  Serial.print(", Y = ");                       
  Serial.print(minYValue);   

  Serial.print(", Z = ");                       
  Serial.println(minZValue); 
}
