
#ifndef WIFCONFIG_H
#define WIFCONFIG_H


#include <WiFi.h>
#include <WiFiClient.h>
#include "WiFiClientSecure.h"

#include <Arduino.h>
#include <WProgram.h>


WiFiClient wifiClient;

//WiFi credentials
const char* ssid     = "Chauk";
const char* password = "dinesh@1965";

#define MQTT_PORT 1883
//const char * serverAddr = "fa2e395c10604e9a8d97e83b8ebd6181.s1.eu.hivemq.cloud";

//server url
const char * serverAddr = "broker.hivemq.com";
//mqtt credentials
const char * mqttUserName = "testmqtt";
const char * mqttPassword = "Mqtt@1234";

//mqtt topic
const char * mqttTopic_1 = "test";



extern void wifi_scanNetworks();

#endif //#ifdef WIFCONFIG_H
