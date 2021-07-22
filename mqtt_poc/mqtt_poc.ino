/*
 *  This sketch sends data via HTTP GET requests to data.sparkfun.com service.
 *
 *  You need to get streamId and privateKey at data.sparkfun.com and paste them
 *  below. Or just customize this script to talk to other HTTP servers.
 *
 */

#include "app_mqtt.h"
#include "wifiConfig.h"


void setup()
{
    Serial.begin(115200);
    delay(10);
    
    // We start by connecting to a WiFi network
    wifi_scanNetworks();
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    if(WiFi.status() == WL_CONNECTED)
    {
      Serial.println("");
      Serial.println("WiFi connected");
      Serial.println("IP address: ");
      Serial.println(WiFi.localIP());

       connectToMqtt();
      
    }
}

int value = 0;

void loop()
{
    
    delay(50);
    ++value;
    if( value > 20 )
    {
      publishData();
      value = 0;
    }
    mqttClient.loop();
}
