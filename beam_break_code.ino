/* 
  IR Breakbeam sensor
*/
#define LEDPIN 13
#define SENSORPIN 4
  // Pin 13: Arduino has an LED connected on pin 13. For Visual confirmation.
  //Led on means beam broken. Led off means beam unbroken.
  // Pin 12: {in that sends out signal. 1 or HIGH means beam is broken.0 or LOW means beam unbroken.
  // Pin 4: Read Digital signal from the ir breakbeam sensor.

// variables will change:
int sensorState = 0,lastState=0;         // variable for reading the pushbutton status

void setup() {
  // sets the digital pin 12 as output, this is the output frpm the sensor state.
  pinMode(12, OUTPUT);   
  // initialize the LED pin as an output(LED 13 in the board I was using)
  pinMode(LEDPIN, OUTPUT);      
  // initialize the sensor pin as an input(PIN 4):
  pinMode(SENSORPIN, INPUT);     
  // turn on the pullup. Required for the sensors.
  digitalWrite(SENSORPIN, HIGH);
  
  Serial.begin(9600);
}

void loop(){
  // read the state of the pushbutton value:
  sensorState = digitalRead(SENSORPIN);

  // check if the sensor beam is broken
  // if it is, the sensorState is LOW:
  if (sensorState == LOW) {     
    // turn LED on:
    digitalWrite(LEDPIN, HIGH);  
    // sets the digital pin 12 on:
    digitalWrite(12, HIGH); 
  } 
  else {
    // turn LED off:
    digitalWrite(LEDPIN, LOW); 
    // sets the digital pin 12 off:
    digitalWrite(12, LOW); 
  }
}
