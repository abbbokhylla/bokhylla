#include "EspMQTTClient.h"
//Install libraries PubSubClient and EspMQTTClient


void onConnectionEstablished();

EspMQTTClient client(
 "ABB_Indgym_Guest",           // Wifi ssid
  "Welcome2abb",           // Wifi password
  "maqiatto.com",  // MQTT broker ip
  1883,             // MQTT broker port
  "william.johansson@abbindustrigymnasium.se", // MQTT username
  "creativetalk",       // MQTT password
  "william1",          // Client name
  onConnectionEstablished, // Connection established callback
  true,             // Enable web updater
  true              // Enable debug messages
);




#define r_pin 14
#define b_pin 13
#define g_pin 12

void setup() {

Serial.begin(115200);  
pinMode(r_pin, OUTPUT);
pinMode(g_pin, OUTPUT);
pinMode(b_pin, OUTPUT);
}

void R(int val){
  analogWrite(r_pin, val);
}
void G(int val){
  analogWrite(g_pin, val);
}
void B(int val){
  analogWrite(b_pin, val);
}

void rgb(int x, int y, int z){
  analogWrite(r_pin, x);
  analogWrite(g_pin, y);
  analogWrite(b_pin, z);
  }

void drgb(String stat){
  if(stat== "on"){
  digitalWrite(r_pin, HIGH);
  digitalWrite(g_pin, HIGH);
  digitalWrite(b_pin, HIGH);
  }
  if(stat=="off"){
    digitalWrite(r_pin, LOW);
    digitalWrite(g_pin, LOW);
    digitalWrite(b_pin, LOW);    
  }
}

void onConnectionEstablished()
{
  client.subscribe("william.johansson@abbindustrigymnasium.se/r1", [] (const String &payload){
   int Rval = payload.toInt()*4;
   R(Rval);
   });
  client.subscribe("william.johansson@abbindustrigymnasium.se/g1", [] (const String &payload){
  int Gval = payload.toInt()*4;
   G(Gval);
  });
  client.subscribe("william.johansson@abbindustrigymnasium.se/b1", [] (const String &payload){
   int Bval = payload.toInt()*4;
   B(Bval);
  });

  client.subscribe("william.johansson@abbindustrigymnasium.se/status1", [] (const String &payload){
    if(payload=="off"){
    drgb("off");
    }
    if(payload=="on"){
      drgb("on");
    }

   });
}

void loop() {
client.loop();
}
