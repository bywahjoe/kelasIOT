#include <BlynkSimpleEsp32.h>
#include "key.h"
#define BLYNK_PRINT Serial

//Config----------------------
const char* ssid = your_ssid;
const char* pass = your_pass;
const char* token = your_token;
//----------------------------

BlynkTimer sendSensor;
void pushSensor() {
  //Push Sensor Virtual Pin 33, Random Value 20 - 39
  int sensor=random(20, 40);
  Blynk.virtualWrite(33, sensor);
}
void setup() {
  Serial.begin(115200);
  randomSeed(analogRead(0));

  //Blynk Config
  Blynk.begin(token, ssid, pass);
  sendSensor.setInterval(3000L, pushSensor);
}

void loop() {
  //Run Blynk
  Blynk.run();
  sendSensor.run();
}
