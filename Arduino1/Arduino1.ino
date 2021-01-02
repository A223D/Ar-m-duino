#include <Servo.h>

Servo myservo;
Servo rotate;

int forwardVal = 179;
int rotateVal = 210;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(9);
  rotate.attach(10);

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);

}

void loop() {

  //sensitivty
  // put your main code here, to run repeatedly:

  if (analogRead(A0) > 550) {
    forwardVal += 2;
  } else if (analogRead(A0) < 430) {
    forwardVal -= 2;
  }

  if (analogRead(A1) < 480) {
    rotateVal -= 2;
  } else if (analogRead(A1) > 530) {
    rotateVal += 2;
  }

  if (forwardVal > 180) {
    forwardVal = 179;
  }

  if (forwardVal < 90) {
    forwardVal = 90;
  }

  if (rotateVal > 150) {
    rotateVal = 150;
  }

  if (rotateVal < 90) {
    rotateVal = 90;
  }

  Serial.print("Forward: ");
  Serial.print(forwardVal);


  Serial.print("  Rotate: ");
  Serial.println(rotateVal);




  myservo.write(forwardVal);
  rotate.write(rotateVal);
  delay(30);

}
