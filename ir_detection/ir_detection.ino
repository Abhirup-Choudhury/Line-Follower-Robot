#define IRpin 12
int hasObstacle;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(IRpin, INPUT);
}

void loop() {
  hasObstacle = digitalRead(IRpin);
  
  if (hasObstacle == 0)  {
    Serial.println( "OBSTACLE DETECTED!!");
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else
  {
    Serial.println("NO OBSTACLE.");
    digitalWrite(LED_BUILTIN, LOW);
  }
  delay(200);
}
