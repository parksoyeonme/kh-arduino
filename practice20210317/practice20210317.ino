int RED = 13;
int GREEN = 12;
/*
  This program blinks pin 13 of the Arduino (the
  built-in LED)
*/
void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
}
void loop()
{
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(GREEN, HIGH);
  delay(5000); // Wait for 1000 millisecond(s)
   for(int i = 0; i < 3; i++)
   {
    digitalWrite(GREEN, LOW);
    delay(500);
    digitalWrite(GREEN, HIGH);
    delay(500);
   }
  // turn the LED off by making the voltage LOW
  digitalWrite(RED, HIGH);
  
  digitalWrite(GREEN, LOW);
  delay(3000); // Wait for 1000 millisecond(s
  
}
