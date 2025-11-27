
// Arduino Collision Detection Using CAN & GSM
#include <mcp_can.h>
#include <SPI.h>
#include <SoftwareSerial.h>

SoftwareSerial gsm(7, 8);
MCP_CAN CAN0(10);

void setup() {
  Serial.begin(9600);
  gsm.begin(9600);

  if (CAN0.begin(MCP_ANY, CAN_500KBPS, MCP_16MHZ) == CAN_OK)
    Serial.println("CAN Initialized");
  else
    Serial.println("CAN Init Failed");

  CAN0.setMode(MCP_NORMAL);

  gsm.println("AT");
  delay(1000);
}

void loop() {
  long unsigned int rxId;
  unsigned char len = 0;
  unsigned char buf[8];

  if (CAN0.checkReceive() == CAN_MSGAVAIL) {
    CAN0.readMsgBuf(&rxId, &len, buf);

    int impactValue = buf[1];

    if (impactValue > 180) {
      sendSMS();
    }
  }
}

void sendSMS() {
  gsm.println("AT+CMGF=1");
  delay(500);
  gsm.println("AT+CMGS=\"+919353648815\"");
  delay(500);
  gsm.println("Alert! Collision Detected. Immediate Help Needed.");
  delay(500);
  gsm.write(26);
  delay(1000);
}
