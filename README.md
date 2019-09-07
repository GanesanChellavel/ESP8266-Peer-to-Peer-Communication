# ESP8266-Peer-to-Peer-Communication
Configure 2 ESP8266 WiFi modules in a Client-Server model to enable HTTP communication between the MCUs without the need of connecting to a router
I personally made use of 2 NODEMCU microcontroller boards and configured one of them as the Client and one of them as the Server.

Steps needed to flash this onto your own boards:

1) Select your ESP8266 Board of choice from the Arduino IDE Board manager
2) Set the baud rate to 115200
3) Use one computer with the NODEMCU (#1) connected and program it with the Server file
4) Use a second computer with the NODEMCU (#2) connected and program it with the Client file
5) Open up the serial monitor on both computers and set it to 115200 baud and start sending a messages!
