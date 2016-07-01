/*
Testing transmit script for generic 433MHz transmitter.
By trishmapow, 1 July 2016
*/

#define rf 12
#define led 13

void setup() {
  pinMode(rf, OUTPUT);
  
  //Live indication of data
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(rf, HIGH);
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(rf, LOW);
  digitalWrite(led, LOW);
  delay(1000);
}
