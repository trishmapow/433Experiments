/*
  RF Blink - Receiver sketch
     Written by ScottC 17 Jun 2014
     Arduino IDE version 1.0.5
     Website: http://arduinobasics.blogspot.com
     Receiver: XY-MK-5V
     Description: A simple sketch used to test RF transmission/receiver.
  ------------------------------------------------------------- */

#define rfReceivePin A0  //RF Receiver pin = Analog pin 0
#define ledPin 13        //Onboard LED = digital pin 13

unsigned int data = 0;   // variable used to store received data
const unsigned int upperThreshold = 70;  //upper threshold value
const unsigned int lowerThreshold = 50;  //lower threshold value

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  data = analogRead(rfReceivePin);  //listen for data on Analog pin 0

  if (data > upperThreshold) {
    digitalWrite(ledPin, LOW);   //If a LOW signal is received, turn LED OFF
    Serial.println(data);
  }

  if (data < lowerThreshold) {
    digitalWrite(ledPin, HIGH);   //If a HIGH signal is received, turn LED ON
    Serial.println(data);
  }
}
