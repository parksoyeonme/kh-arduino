const int PUSH_BUTTON = 10;

void setup()
{
  Serial.begin(9600);
  pinMode(PUSH_BUTTON, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
   int value = digitalRead(PUSH_BUTTON);
     Serial.println(value);
     digitalWrite(LED_BUILTIN, value);
   delay(100);
}
