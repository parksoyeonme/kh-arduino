#include <SPI.h>
#include <Ethernet.h>
#include "DHT.h"

// Enter a MAC address for your controller below.
// Newer Ethernet shields have a MAC address printed on a sticker on the shield
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x9B };

//접속할 서버의(tomcat) ip
//IPAddress server(192, 168, 10, 95);
char server[] = "khmclass.iptime.org";

//접속할 서버의 port
int port = 9090;

//서버요청용 client객체
EthernetClient client;

//DHT관련
#define DHTPIN 8
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {

  Serial.begin(9600);

  //uno보드 dhcp할당
  Ethernet.begin(mac);

  //uno보드 ip 확인
  Serial.print("Arduino is at ");
  Serial.println(Ethernet.localIP());

  //dht 시작
  dht.begin();


  delay(1000);
}

void loop() {

  httpRequestPOST();
  
  //응답메세지 출력
  while(client.available()){
    char c = client.read();
    Serial.print(c);
  }
  
    
  delay(10000);
}


void httpRequestPOST()
{
  int conn = client.connect(server, port);

  if(conn == 1)
  {
    //연결 성공시
    Serial.println();
    Serial.println("connecting....");
  
      delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  
  float hi = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(F("° Heat index: "));
  Serial.print(hi);
  Serial.println(F("°C "));

    String param = "place=%EA%B9%80%EC%A7%84%ED%95%98%20%EB%82%A8%EC%B9%9C%EA%B5%AC%ED%96%88%EB%8B%A4%EB%8B%88%EA%B9%8C%3F&h=";
    param += h;
    param += "&c=";
    param += t;
    param += "&hi=";
    param += hi;

    Serial.println(param);

    //요청메세지 작성
    client.println("POST /arduino/dht/createDht HTTP/1.1");
    client.print("Host: ");
    client.println(server); //192.168.10.110
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
