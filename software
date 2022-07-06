// C++ code
//
int temperature = 0;

void setup()
{
  pinMode(A4, INPUT);
  pinMode(12, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  temperature = (-40 + 0.488155 * (analogRead(A4) - 20));
  digitalWrite(12, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(4, HIGH);
  if (temperature > 100) {
    digitalWrite(12, LOW);
  }
  if (temperature > 60) {
    digitalWrite(10, LOW);
  }
  if (temperature > 30) {
    digitalWrite(8, LOW);
  }
  if (temperature > 0) {
    digitalWrite(6, LOW);
  }
  if (temperature > -40) {
    digitalWrite(4, LOW);
  }

  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}
