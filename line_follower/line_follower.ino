#define irL 1
#define irM 2
#define irR 3

#define LM1 4
#define LM2 5
#define RM1 6
#define RM2 7

#define enR 8
#define enL 9
// PIN NUMBERS ARE TO BE CHANGED !!!!!!

int senseL,senseM,senseR;
int hasObstacle;
void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(irL, INPUT);
  pinMode(irM, INPUT);
  pinMode(irR, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(enR, OUTPUT);
  pinMode(enL, OUTPUT);
}

void loop() {
  senseL = digitalRead(irL);
  senseM = digitalRead(irM);
  senseR = digitalRead(irR);
  int detection = 100*senseL + 10*senseM + senseR;
  Serial.println(detection);

  switch(detection) {
    case 101:
      forward();
      break;
    case 110:
      turnRight();
      break;
    case 11:
      turnLeft();
      break;
    case 100:
      sharpRight();
      break;
    case 1:
      sharpLeft();
      break;
    case 10:
      turnRight();
      break;
    case 0:
      turnRight();
      break;
    case 111:
      stop();
      break;
    default:
      stop();
      break;
  }
}

void forward() {
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
  digitalWrite(LED_BUILTIN, LOW);

  // speedL = map(speedL, 0, 100, 0, 255);
  // speedR = map(speedR, 0, 100, 0, 255);
  analogWrite(enL, 255);
  analogWrite(enR, 255);
}
void stop() {
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);
  digitalWrite(LED_BUILTIN, HIGH);

  analogWrite(enL, 0);
  analogWrite(enR, 0);
}
void turnRight() {
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
  digitalWrite(LED_BUILTIN, LOW);

  analogWrite(enL, 255);
  analogWrite(enR, 128);
}
void turnLeft() {
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
  digitalWrite(LED_BUILTIN, LOW);

  analogWrite(enL, 128);
  analogWrite(enR, 255);
}
void sharpRight() {
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, HIGH); //RIGHT MOTOR POLARITY REVERSED
  digitalWrite(LED_BUILTIN, LOW);

  analogWrite(enL, 255);
  analogWrite(enR, 255);
}
void sharpLeft() {
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, HIGH); //LEFT MOTOR POLARITY REVERSED
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
  digitalWrite(LED_BUILTIN, LOW);

  analogWrite(enL, 255);
  analogWrite(enR, 255);
}
