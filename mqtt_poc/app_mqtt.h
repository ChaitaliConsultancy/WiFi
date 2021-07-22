
#ifndef APP_MQTT_H
#define APP_MQTT_H

#include <PubSubClient.h>
#include <Arduino.h>
#include <WProgram.h>

PubSubClient mqttClient(serverAddr,MQTT_PORT,mqtt_callback,wifiClient);

extern void mqtt_callback(char* topic, byte* payload, unsigned int length);
extern boolean connectToMqtt();
extern void publishData();




#endif //#ifdef APP_MQTT_H
