#include <Servo.h>

Servo hook;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  hook.attach(10);
  pinMode(A0, INPUT);
  
}

void loop() {
  Serial.print("  hook: ");
  Serial.println(map(analogRead(A0), 0, 1023, 140, 180));
  hook.write(map(analogRead(A0), 0, 1023, 140, 180));
  delay(30);
}
