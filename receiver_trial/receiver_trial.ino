//CAN Receive Code
// code has been edited

#include <mcp_can.h>
#include <mcp_can_dfs.h>
#include "pin_mapping.h"


void setup() {
  Serial.begin(115200);
  delay(500);
  pinMode(led, OUTPUT);

  // Initialize MCP2515 running at 16MHz with a baudrate of 500kb/s and the masks and filters disabled.
  if (CAN0.begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ) == CAN_OK)
    Serial.println("MCP2515 Initialized Successfully!");
  else
    Serial.println("Error Initializing MCP2515...");

  CAN0.setMode(MCP_NORMAL);  // Set operation mode to normal so the MCP2515 sends acks to received data.

  pinMode(CAN0_INT, INPUT);  // Configuring pin for /INT input

  Serial.println("MCP2515 Library Receive Example...");
}



void loop() {
  if (!digitalRead(CAN0_INT)) {

    CAN0.readMsgBuf(&rxId, &len, rxBuf);

    digitalWrite(led, HIGH);

    // Add received bytes to sentence buffer
    for (byte i = 0; i < len; i++) {
      sentence[index++] = (char)rxBuf[i];
    }

    if (len < 8) {

      sentence[index] = '\0';

      Serial.println(sentence);

      index = 0;
    }

  } else {
    digitalWrite(led, LOW);
  }
}
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/