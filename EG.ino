#define MOTOR1 5
#define MOTOR2 6

#define DIST_TRIG 13
#define DIST_ECHO 12

#define TRIGGER_DISTANCE 30

// Duration till cat ears ~= 237

float SPD_O_SOUND = 0.0345;
int counter = 3;

enum DIRECTION {
  FORWARD, BACKWARD
};

void move(enum DIRECTION dir) {
  if(dir == FORWARD) {
    digitalWrite(MOTOR1, HIGH);
    digitalWrite(MOTOR2, LOW);
  }else {
    digitalWrite(MOTOR1, LOW);
    digitalWrite(MOTOR2, HIGH);
  }
}



void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(MOTOR1, OUTPUT);
  pinMode(MOTOR2, OUTPUT);
  pinMode(DIST_TRIG, OUTPUT);
  pinMode(DIST_ECHO, INPUT);

  digitalWrite(DIST_TRIG, LOW);
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
    counter--;
  }

  if(counter == 0) {
    digitalWrite(LED_BUILTIN, HIGH);
    move(BACKWARD);
  }
  delay(60);
}
