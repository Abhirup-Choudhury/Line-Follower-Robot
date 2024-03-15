#define LM1 10
#define LM2 10
#define RM1 10
#define RM2 10

#define enR 11
#define enL 11
//Adjust pin numbers

int motorSpeedR = 0;
int motorSpeedL = 0;
// in percentage from 0 to 100
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(enR, OUTPUT);
  pinMode(enL, OUTPUT);
}

void loop() {
  // Providing motor speeds as percentages.
  forward();
  // delay(1000);
  // sharpRight();
  // delay(100);
  // stop();
  // delay(500);
  // backward();
  // delay(2000);
  // sharpLeft();
  // delay(100);
  // stop();
  // delay(500);
  // turnRight();
  // delay(1000);
  // turnLeft();
  // delay(1000);
  // stop();
  // delay(500);
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
void backward() {
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, HIGH);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, HIGH);
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
void SharpRight() {
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, HIGH); //RIGHT MOTOR POLARITY REVERSED
  digitalWrite(LED_BUILTIN, LOW);

  analogWrite(enL, 255);
  analogWrite(enR, 255);
}
void SharpLeft() {
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, HIGH); //LEFT MOTOR POLARITY REVERSED
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
  digitalWrite(LED_BUILTIN, LOW);

  analogWrite(enL, 255);
  analogWrite(enR, 255);
}