#include <Servo.h>

#define MOTOR1 5
#define MOTOR2 6
#define MOTOR3 7
#define MOTOR4 8

#define SERVO_PIN 9

#define DIST_TRIG 13
#define DIST_ECHO 12

#define TRIGGER_DISTANCE 30

// Duration till cat ears ~= 237


float SPD_O_SOUND = 0.0345;

Servo servo;

enum DIRECTION {
  FORWARD, BACKWARD
};

void move(enum DIRECTION dir) {
  if(dir == FORWARD) {
    digitalWrite(MOTOR1, HIGH);
    digitalWrite(MOTOR2, LOW);
    digitalWrite(MOTOR3, HIGH);
    digitalWrite(MOTOR4, LOW);
  }else {
    digitalWrite(MOTOR1, LOW);
    digitalWrite(MOTOR2, HIGH);
    digitalWrite(MOTOR3, LOW);
    digitalWrite(MOTOR4, HIGH);
  }
}



void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(MOTOR1, OUTPUT);
  pinMode(MOTOR2, OUTPUT);
  pinMode(MOTOR3, OUTPUT);
  pinMode(MOTOR4, OUTPUT);
  pinMode(DIST_TRIG, OUTPUT);
  pinMode(DIST_ECHO, INPUT);

  digitalWrite(DIST_TRIG, LOW);

  servo.attach(SERVO_PIN);
  servo.write(0);

  // After seting up set the motor to drive in the forward direction.
  move(FORWARD);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {

  digitalWrite(DIST_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(DIST_TRIG, LOW);

  unsigned long dur = pulseIn(DIST_ECHO, HIGH);
  // We can also do comparison by duration, just to skip the processing, not sure how much of a difference it makes tho
  float dist = dur * SPD_O_SOUND / 2;

  if(dist < TRIGGER_DISTANCE) {
    digitalWrite(LED_BUILTIN, HIGH);

    servo.write(90);

    // Adding a visible delay of 1 second
    delay(1000);

    move(BACKWARD);
    // while loop stops arduino from processing any further, Hopefully this reduces power draw
    while(1);
  }

  delay(60);
}
