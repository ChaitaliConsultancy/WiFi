
#include "app_mqtt.h"

void mqtt_callback(char* topic, byte* payload, unsigned int length);
boolean connectToMqtt();
void publishData();

boolean connectToMqtt()
{
  if(WiFi.status() == WL_CONNECTED)
  {
    Serial.println("Connecting to MQTT broker");
    if(true == mqttClient.connect("mqtt-explorer-1aeb7701"))//,mqttUserName,mqttPassword))
    {
      Serial.print("MQTT Broker : Connection success : ");
      Serial.println(mqttClient.state());
      return true;
    }
    else
    {
      Serial.print("MQTT Broker : Connection fail : ");
      Serial.println(mqttClient.state());
      return false;
    }
  }
  return false;
}


void publishData()
{
   static int count = 0;
   char pubData[100];
   itoa(count++, pubData,10);
   if(true == mqttClient.publish(mqttTopic_1,pubData))
   {
    Serial.print( " Data Sent : ");
    Serial.println(pubData);
   }
}


void mqtt_callback(char* topic, byte* payload, unsigned int length)
{
  
}
