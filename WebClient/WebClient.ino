#include <SPI.h>
#include <Ethernet.h>

// Enter a MAC address for your controller below.
// Newer Ethernet shields have a MAC address printed on a sticker on the shield
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x9B };

//접속할 서버의(tomcat) ip
IPAddress server(192, 168, 10, 95);

//접속할 서버의 port
int port = 9090;

//서버요청용 client객체
EthernetClient client;


void setup() {

  Serial.begin(9600);

  //uno보드 dhcp할당
  Ethernet.begin(mac);

  //uno보드 ip 확인
  Serial.print("Arduino is at ");
  Serial.println(Ethernet.localIP());

  delay(1000);
}

void loop() {

//  httpRequestGET();
  httpRequestPOST();
  
  //응답메세지 출력
  while(client.available()){
    char c = client.read();
    Serial.print(c);
  }
  
    
  delay(10000);
}

void httpRequestGET()
{
  int conn = client.connect(server, port);

  if(conn == 1)
  {
    //연결 성공시
    Serial.println();
    Serial.println("connecting....");

    //요청메세지 작성
    client.println("GET /arduino/test?name=%EC%8B%A0%EC%82%AC&num=345 HTTP/1.1");
    client.print("Host: ");
    client.println(server); //192.168.10.6
    client.println("User-Agent: arduino-ethernet");
    client.println("Connection: close");
    client.println(); //메세지 헤더 종료(공백라인)
  }
  else 
  {
    //연결 실패시
    Serial.println("connection failed");
  } 

  //응답메세지 도착을 위한 대기
  delay(1000);
}

void httpRequestPOST()
{
  int conn = client.connect(server, port);

  if(conn == 1)
  {
    //연결 성공시
    Serial.println();
    Serial.println("connecting....");

    String param = "name=%EC%8B%A0%EC%82%AC&num=345";
    
    //요청메세지 작성
    client.println("POST /arduino/test HTTP/1.1");
    client.print("Host: ");
    client.println(server); //192.168.10.6
    client.println("User-Agent: arduino-ethernet");
    client.println("Connection: close");
    //메세지 바디설정
    client.println("Content-Type: application/x-www-form-urlencoded; charset=utf-8");
    client.print("Content-Length: ");
    client.println(param.length());
    client.println(); //메세지 헤더 종료(공백라인)
    client.println(param);
  }
  else 
  {
    //연결 실패시
    Serial.println("connection failed");
  } 

  //응답메세지 도착을 위한 대기
  delay(1000);
}
