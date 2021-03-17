//전역변수 선언
const int OTHER = 12;
/*
  This program blinks pin 13 of the Arduino (the
  built-in LED)
  초기화 함수. 프로그램시 시작시 최초1회만 호출.
*/
void setup()
{

  //Serial통신 초기화
  //baurate 통신속도 지정
  Serial.begin(9600);
  
  // 해당 핀의 입출력여부
  // 13핀 : 전압(전원역할)
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(OTHER, OUTPUT);
}
/*
 반복실행 함수
*/
void loop()
{
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(OTHER, LOW);
  Serial.print("13 : ");
  Serial.print(HIGH);
  Serial.print(", 12 : ");
  Serial.println(LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  // turn the LED off by making the voltage LOW
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(OTHER, HIGH);
 Serial.print("13 : ");
  Serial.print(LOW);
  Serial.print(", 12 : ");
  Serial.println(HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
}
