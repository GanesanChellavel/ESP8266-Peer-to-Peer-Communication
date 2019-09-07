#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>//Server Library

const char* ssid ="DEMO"; //enter the name of the SSID for the Access Point here
const char* password ="PASSWORD"; //enter the password of the Access Point here

ESP8266WebServer server(80);

void handleRoot() {
  if (Serial.available()>0){
      String body=Serial.readString();
      Serial.println(body);
      server.send(200, "text/html", "<h1>"+body+"</h1>");}
  else{
  server.send(200, "text/html", "<h1>No message read</h1>");}
}

void setup() {
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  
  Serial.print("Configuring access point...");
  /* You can remove the password parameter if you want the AP to be open. */
  WiFi.softAP(ssid, password);
  
  IPAddress myIP = WiFi.softAPIP();
  
  Serial.println("AP IP address: ");
  Serial.println(myIP);
  
  server.on("/", handleRoot);
  
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
