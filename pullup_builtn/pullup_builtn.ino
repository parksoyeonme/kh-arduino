/*

pulldown 저항
- 저항을 접지부연결
- 기본값 0 누르면 1
- 믹서기, 전구, 선풍기

pullup저항
- 저항을 전원부연결
- 기본값 1 누르면 0
- 비상정지버튼, 컴퓨터리셋버튼
*/


const int PULLUP_BUILTIN = 6;

void setup()
{
  Serial.begin(9600);
  pinMode(PULLUP_BUILTIN, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
 
  int pubVal = digitalRead(PULLUP_BUILTIN);
  Serial.println(pubVal);
  digitalWrite(LED_BUILTIN, pubVal);
  
  
  delay(100);
}
