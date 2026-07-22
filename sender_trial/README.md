/* This code is for the sender end of the MCP2515 module

** This code uses the mcp_can library by coryjfowler

* This program uses modular coding to make the code more organised and easier to read
* it has a separate file for pin mapping and the different commands have been put into separate functions
* (make sure the pin numbers match your circuit or the current pins are edited into the code correctly)
* the sendMsgBuf() function is not being checked as I preferred to keep it this way for the code but it can be modified to be checked

* In this code, this sender has been initialized at 500kpbs and 8MHz (please change this value according to the MCP2515 module being used)
* (it should be the same for both MCP2515 modules)


* Its mode has been set to normal mode where is can send and receive messages (this is the most common mode)

* The message being sent right now is: "button is pressed"
* However it can be changed by changing whatever is in "String message"


* Lastly, in the void loop(), the string message is being broken into smaller packets of 8 characters as that is the 
* maximum length of message the MCP2515 can send
* it is being done by the two for loops


* Overall

* This code allows a message to be sent when the button is pressed
* and the receiver end receives and prints the message while turning the LED on


* This code can be customised to have more modules or other functions but this is the basic structure of an MCP2515 code
*/
