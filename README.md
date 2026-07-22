# MCP2515-communication


* THIS IS THE PROBLEM SOLVING FILE
* IT CONTAINS THE BASIC PROBLEMS YOU MIGHT FACE AND HOW I SOLVED THEM
* EACH CODE FOLDER HAS A SEPARATE README.MD FILE FOR EACH MODULE (THE SENDER AND THE RECEIVER)

* If the messages are not being send/ received properly: check the wire connections
* even if the wires worked fine yesterday, it might cause issues while running today

* check for faulty wires using a multimeter (there were a lot of faulty wires)

* Change the code according to your MCP2515: 16MHz to 8MHz (because i was only getting one output but the sender was continuously sending new messages) (issues with receiving messages could be due to inproper initialization)


* Added a delay in both the void setup of the sender and the receiver (The MCP2515 needs time to power up before Arduino talks to it)


* Sometimes the current and voltage value provided may not be enough
* Sometimes its the wires or just change the component (different LED, etc)
* Or i needed to add a resistor/ capacitor


* Whenever you’re stuck in a loop, always go through the first, second, and third iterations of the loop to understand what the code intended
* The longer than 8 characters code is a bit complicated but go through the iterations and it’ll be fine
* It's important to understand that part as that is the main way the MCP2515 is sending and receiving messages
