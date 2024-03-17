#define irL 2
#define irM 4
#define irR 5

#define LM1 8
#define LM2 9
#define RM1 6
#define RM2 7

#define enR 3
#define enL 11
// PIN NUMBERS ARE TO BE CHANGED !!!!!!

int senseL,senseM,senseR;
int hasObstacle;
void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(irL, INPUT);
  // pinMode(irM, INPUT);
  pinMode(irR, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(enR, OUTPUT);
  pinMode(enL, OUTPUT);
}

void loop() {  
  senseL = digitalRead(irL) ? 0 : 1;
  // senseM = digitalRead(irM) ? 0 : 1;
  senseR = digitalRead(irR) ? 0 : 1;
  int detection = 10*senseL + senseR;
  Serial.println(detection);

  switch(detection) {
    case 11:
      forward();
      break;
    case 10:
      stop();
      turnRight();
      
      break;
    case 1:
      stop();
      turnLeft();
      break;
    default:
      forward();
      break;
  }
  delay(100);
}

void forward() {
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
  digitalWrite(LED_BUILTIN, LOW);

  analogWrite(enL, 100);
  analogWrite(enR, 100);
}
void stop() {
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);
  digitalWrite(LED_BUILTIN, HIGH);

  analogWrite(enL, 0);
  analogWrite(enR, 0);
  delay(100);
}
void turnRight() {
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
  digitalWrite(LED_BUILTIN, LOW);

  analogWrite(enL, 100);
  analogWrite(enR, 50);
}
void turnLeft() {
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
  digitalWrite(LED_BUILTIN, LOW);

  analogWrite(enL, 50);
  analogWrite(enR, 100);
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
