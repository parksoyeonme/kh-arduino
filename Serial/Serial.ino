/*
  Serial 통신
  아두이노보드간, 아두이노와 IDE사이의 통신을 지원한다.
  최초 동일한 baudrate설정후, 시리얼모니터에 입출력이 가능하다
*/

void setup()
{
  //Serial통신 초기화
  //baurate 통신속도 지정
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop()
{
  //사용자 입력값이 있는 경우만 처리
  if(Serial.available())
  {
    int value = (int)Serial.read();
    Serial.print("inputvalue : ");
    Serial.println(value);
 
    //개행문자는 조기리턴처리
  if(value == 13 || value == 10)
    return;
    
    digitalWrite(LED_BUILTIN, value == 49 ? HIGH : LOW);
  }
  
 
  
  /*
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(13, HIGH);
  Serial.println(HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  // turn the LED off by making the voltage LOW
  digitalWrite(13, LOW);
  Serial.println(LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  */
}
