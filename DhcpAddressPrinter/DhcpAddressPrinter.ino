#include <SPI.h>
#include <Ethernet.h>

// Enter a MAC address for your controller below.
// Newer Ethernet shields have a MAC address printed on a sticker on the shield
byte mac[] = {
  0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x9B
};

void setup() {
  Serial.begin(9600);
  Ethernet.begin(mac);

  Serial.print("My Ip Address : ");
  Serial.println(Ethernet.localIP());
  

}

void loop() {
  // put your main code here, to run repeatedly:

}
