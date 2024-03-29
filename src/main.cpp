#include <Arduino.h>

// defines:
// Motor Connections (ENA & ENB must use PWM pins)
#define IN1 9
#define IN2 8
#define IN3 7
#define IN4 6
#define ENA 10
#define ENB 5

//function declarations:
void motorAccel(void);
void motorDecel(void);

// setup code, runs once:
void setup() {
  // Set motor connections as outputs
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Start with motors off
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

// main code here,runs repeatedly:
void loop() {

  // Set motors forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  // Accelerate & decelerate both motors forward
  motorAccel();
  motorDecel();

  delay(500);

  // Set motors reverse
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  // Accelerate & decelerate both motors backward
  motorAccel();
  motorDecel();

  delay(500);

  // Set motors in opposite directions (full speed)
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENA, 255);
  analogWrite(ENB, 255);

  delay(500);

  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  delay(500);
}

//function definitions:
void motorAccel(void) {
  for (int i = 0; i < 256; i++) {
    analogWrite(ENA, i);
    analogWrite(ENB, i);
    delay(20);
  }
}

void motorDecel(void) {
  for (int i = 255; i >= 0; --i) {
    analogWrite(ENA, i);
    analogWrite(ENB, i);
    delay(20);
  }
}
