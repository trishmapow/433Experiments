#define rf 12
#define led 13

void setup() {
  pinMode(rf, OUTPUT);
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
