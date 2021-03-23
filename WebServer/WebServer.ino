#include <SPI.h>
#include <Ethernet.h>
// Enter a MAC address for your controller below.
// Newer Ethernet shields have a MAC address printed on a sticker on the shield
byte mac[] = {
  0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x9B
};
//할당받은 ip주소입력
IPAddress ip(192,168,10,104);

//포트
#define PORT 11111

//LED
#define LED 8

//request type 상수처리
#define REQ_INDEX 0
#define REQ_LED_ON 1
#define REQ_LED_OFF 2

int requestType = REQ_INDEX;
//서버객체
EthernetServer server(PORT);
//사용자 요청 메세지 처리변수
String buffer;
void setup() {
  Serial.begin(9600);
  Ethernet.begin(mac);
  // start the Ethernet connection:
  Serial.println("Initialize Ethernet with DHCP:");
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    if (Ethernet.hardwareStatus() == EthernetNoHardware) {
      Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
    } else if (Ethernet.linkStatus() == LinkOFF) {
      Serial.println("Ethernet cable is not connected.");
    }
    // no point in carrying on, so do nothing forevermore:
    while (true) {
      delay(1);
    }
  }

  server.begin();

  digitalWrite(LED, HIGH);

  Serial.print("server is at ");
  Serial.print(Ethernet.localIP());
  Serial.print(":");
  Serial.println(PORT);
}
void loop() {
  //클라이언트 요청이 있다면, EternetClient객체 반환
  EthernetClient client = server.available(); 

  if(client){
    Serial.println("new client.......");
    boolean isFirstLine = true;

    //요청메세지 처리
    //client접속중이거나, 요청메세지에 남은 내용이 있는 경우, true반환
    while(client.connected()){
      boolean currentLineIsBlank = readLine(client);
      Serial.println(buffer);

      //첫줄에서 요청 url을 파싱처리
      //GET /HTTP/1.1
      //GET /led/on HTTP/1.1
      //GET /led/off HTTP/1.1
      if(isFirstLine){
        int start = buffer.indexOf(" ") + 1;
        int end = buffer.indexOf(" ", start); // start부터 처음 등장한 공백 인덱스 검사
        String url = buffer.substring(start, end);
        Serial.println(url);

        if(url.indexOf("/led/on") > -1)
          requestType = REQ_LED_ON;
        else if(url.indexOf("/led/off") > -1)
          requestType = REQ_LED_OFF;
        else
          requestType = REQ_INDEX;

          isFirstLine = false;
        
      }

      //응답메세지 작성
      if(currentLineIsBlank) {
        switch(requestType){
          case REQ_LED_ON : digitalWrite(LED, HIGH); responseRedirect(client, HIGH); break;
          case REQ_LED_OFF : digitalWrite(LED, LOW); responseRedirect(client, LOW); break;
          default : responseIndex(client);
          
        }

        break;
      }
    }

    //접속 닫기
    client.stop();
    Serial.println("client disconnected ......");
    Serial.println();
  }
}
/*
* LED 제어후, 사용자피드백 전달
* 이후 index페이지로 리다이렉트처리
*/
void responseRedirect(EthernetClient client, int status){

  //헤더부분
        client.println("HTTP/1.1 200 OK");
        client.println("Content-Type : text/html; charset=utf-8");
        client.println("Connection : close");
        client.println();

        //바디부분
        client.println("<!DOCTYPE html>");
        client.println("<html>");
        client.println("<head>");
        client.println("<meta http-equiv='refresh' content='0; url=/'>");
        client.println("<script>");
        client.print("alert('LED가 ");
        client.print(status ? "켜졌습니다." : "꺼졌습니다.");
        client.println("');");
        client.println("</script>");
        client.println("</head>");
        client.println("</html>");
  
}
/*
index html

*/
void responseIndex(EthernetClient client){

  //헤더부분
        client.println("HTTP/1.1 200 OK");
        client.println("Content-Type : text/html");
        client.println("Connection : close");
        client.println();

        //바디부분
        client.println("<!DOCTYPE html>");
        client.println("<html>");
        client.println("<head>");
        client.println("<title>Welcome to arduino</title>");
        client.println("</head>");
        client.println("<body>");
        client.println("<h1>Welcome to Arduino</h1>");
        client.println("<input type='button' value='ON' onclick = 'ledControl(\"on\")' />");
        client.println("<input type='button' value='OFF' onclick = 'ledControl(\"off\")' />");
        client.println("<script>");
        client.println("function ledControl(status){");
        client.println(" location.href = '/led/' + status;");
        client.println("}");
        client.println("</script>");
        client.println("</body>");
        client.println("</html>");
  
}
boolean readLine(EthernetClient client){
  buffer = ""; //v=buffer변수 초기화
  
  //client.available() : 1byte씩 읽고 남은 요청메세지의 byte수를 리턴
  while(client.available()){
    char c = client.read();
    buffer += c;
    if(c == '\n')
        break;
  }

  return buffer.length() == 0; //마지막줄여부. http메세지는 공백라인으로 끝난다.
}
