
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid ="DEMO"; //enter the name of the SSID for the Access Point here
const char* password ="PASSWORD"; //enter the password of the Access Point here

void setup() {

    Serial.begin(115200);
    
      WiFi.mode(WIFI_STA);
      
      WiFi.disconnect(true);//disconnect from past wifi connections

    WiFi.begin(ssid,password);
    
    while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    delay(15000);
    }
    Serial.println("Connected");

}

void loop() {
    // wait for WiFi connection
    if((WiFi.status() == WL_CONNECTED)) {

        HTTPClient http;
        
        Serial.print("[HTTP] begin...\n"); // requesting required link 
        http.begin("http://192.168.4.1"); //HTTP

        Serial.print("[HTTP] GET...\n"); // start connection and send HTTP header
        int httpCode = http.GET();
  
        if (httpCode > 0){
        String payload=http.getString();  
        Serial.println(payload);  
        }
        
        http.end();

        delay(30000);

        
    }
    }

   
