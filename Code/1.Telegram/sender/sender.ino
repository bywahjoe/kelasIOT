#include "CTBot.h"
#include "key.h"
CTBot myBot;

//Config----------------------
#define chatID your_chatID
String msg = your_msg;
String ssid = your_ssid;
String pass = your_pass;
String token = your_token;
//----------------------------

void setup() {
  Serial.begin(115200);

  myBot.wifiConnect(ssid, pass); //WIFI CONECT
  myBot.setTelegramToken(token); //TOKEN SETT
  delay(100);

  if (myBot.testConnection()) {
    Serial.println("\nSIGNAL OK");
  }
  else {
    Serial.println("\nSIGNAL ERR");
  }
}
void loop() {
  //Sending BYWAHJOE 10 sec
  myBot.sendMessage(chatID, msg);
  delay(10000);
}
