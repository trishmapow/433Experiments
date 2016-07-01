/*
  RF Remote Capture sketch
     Written by ScottC 24 Jun 2014
     Arduino IDE version 1.0.5
     Website: http://arduinobasics.blogspot.com
     Receiver: XY-MK-5V
     Description: Use Arduino to Receive RF Remote signal
  ------------------------------------------------------------- */

const int dataSize = 500;  //Arduino memory is limited (max=1700)
byte storedData[dataSize];  //Create an array to store the data
#define ledPin 13           //Onboard LED = digital pin 13
#define rfReceivePin A0     //RF Receiver data pin = Analog pin 0
const unsigned int upperThreshold = 100;  //upper threshold value
const unsigned int lowerThreshold = 80;  //lower threshold value
int maxSignalLength = 255;   //Set the maximum length of the signal
int dataCounter = 0;    //Variable to measure the length of the signal
unsigned long startTime = 0; //Variable to record the start time
unsigned long endTime = 0;  //Variable to record the end time
unsigned long signalDuration = 0; //Variable to record signal reading time


void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

  /* The following code will only run ONCE --------------
    ---Press the reset button on the Arduino to run again-- */

  while (analogRead(rfReceivePin) < 1) {
    //Wait here until a LOW signal is received
    startTime = micros(); //Update start time with every cycle.
  }
  digitalWrite(ledPin, HIGH);  //Turn LED ON


  //Read and store the rest of the signal into the storedData array
  for (int i = 0; i < dataSize; i = i + 2) {

    //Identify the length of the LOW signal---------------LOW
    dataCounter = 0; //reset the counter
    while (analogRead(rfReceivePin) > upperThreshold && dataCounter < maxSignalLength) {
      dataCounter++;
    }
    storedData[i] = dataCounter;

    //Identify the length of the HIGH signal---------------HIGH
    dataCounter = 0; //reset the counter
    while (analogRead(rfReceivePin) < lowerThreshold && dataCounter < maxSignalLength) {
      dataCounter++;
    }
    storedData[i + 1] = dataCounter;

    //Any readings between the two threshold values will be ignored.
    //The LOW or HIGH signal length must be less than the variable "maxSignalLength"
    //otherwise it will be truncated. All of the HIGH signals and LOW signals combined
    //must not exceed the variable "dataSize", otherwise it will be truncated.
    //The maximum number of signals is 1700 - if you try to extend this variable to a higher
    //number than 1700 - then the Arduino will freeze up and sketch will not work.
    //-------------------------------------------------------------
  }

  endTime = micros(); //Record the end time of the read period.
  signalDuration = endTime - startTime;

  digitalWrite(ledPin, LOW);//Turn LED OFF

  //Send report to the Serial Monitor
  Serial.println("=====================");
  Serial.print("Read duration: ");
  Serial.print(signalDuration);
  Serial.println(" microseconds");
  Serial.println("=====================");
  Serial.println("LOW,HIGH");
  delay(20);
  for (int i = 0; i < dataSize; i = i + 2) {
    Serial.print(storedData[i]);
    Serial.print(",");
    Serial.println(storedData[i + 1]);
    delay(20);
  }
}

void loop() {
  //Do nothing here
}


