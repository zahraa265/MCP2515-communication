// CAN Send Code
// Code has been editted

#include <mcp_can.h>
#include <SPI.h>
#include "pin_mapping.h"


void setup() {
  Serial.begin(115200);
  delay(500);
  pinMode(button, INPUT_PULLUP);

  // Initialize MCP2515 running at 8MHz with a baudrate of 500kb/s and the masks and filters disabled.
  CAN0.begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ);

  CAN0.setMode(MCP_NORMAL);  // Change to normal mode to allow messages to be transmitted
}

String message = "button is pressed";


void messages_to_send() {
  Serial.println("Message Sent Successfully!");
  Serial.println("button has been pressed");
}

void error_messages() {
  Serial.println("Error Sending Message...");
  Serial.println("button has not been pressed");
}

void loop() {

  for (int i = 0; i < message.length(); i += 8) {
    byte data[8];

    int size = min(8, message.length() - i);

    for (int j = 0; j < size; j++) {
      data[j] = message[i + j];
    }

  state = digitalRead(button);

  if (state == LOW) {
    CAN0.sendMsgBuf(0x100, 0, size, data);
    messages_to_send();
  } else {
    error_messages();
  }
}
}