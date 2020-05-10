#define IDLE 0
#define CHARGING 1
#define ACTIVE 2

int state = IDLE;
int prevState = IDLE;
int switchState = 0;

void on (int pin) {
  digitalWrite(pin, HIGH);
}

void off (int pin) {
  digitalWrite(pin, LOW);
}

void idle () {
    on(3);
    off(4);
    off(5);
}

void charging () {
  off(3);
  on(4);
  off(5);

  delay(800);

  on(5);

  delay(800);
}

void active () {
  off(3);
  off(4);
  on(5);

  delay(100);

  // Swap
  on(4);
  off(5);

  delay(100);
}

void setup () {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
}

void loop () {
  prevState = state;

  switchState = digitalRead(2);

  if (switchState == LOW) {
    state = IDLE;
    idle();
  } else if (switchState == HIGH && prevState == IDLE) {
    state = CHARGING;
    charging();
  } else if (switchState == HIGH && prevState == CHARGING) {
    state = ACTIVE;
    active();
  } else if (switchState == HIGH && prevState == ACTIVE) {
    state = ACTIVE;
    active();
  }
}
