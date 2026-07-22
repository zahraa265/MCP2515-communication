/* This code is for the receiver end of the MCP2515 module

* This code uses the mcp_can library by coryjfowler

* This program uses modular coding to make the code more organised and easier to read
* it has a separate file for pin mapping
* make sure the pin numbers match your circuit or the current pins are edited into the code correctly


* In this code, this receiver has been initialized at 500kpbs and 8MHz (please change this value according to the MCP2515 module being used)
* (it should be the same for both MCP2515 modules)

* Its mode has been set to normal mode where is can send and receive messages (this is the most common mode)

* The message being received right now is: "button is pressed"


* In the void loop, if a signal is received from the sender, the reading from the interrupt pin(2) becomes low
* as a result it will store the message being sent into sentence[] and print it out
* (the maximum number of bytes an MCP2515 can receive or send is 8 so it has to break down the message)

* Additionally, it will turn the LED on
* if there is no message being received, the LED will be off

* Overall

* This code allows a message to be sent when the button is pressed
* and the receiver end receives and prints the message while turning the LED on


* This code can be customised to have more modules or other functions but this is the basic structure of an MCP2515 code
*/
