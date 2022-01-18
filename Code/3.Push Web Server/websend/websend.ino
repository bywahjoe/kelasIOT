#include <WiFi.h>
#include "key.h"
#include <HTTPClient.h>
#define URLWEB "https://iot.bywahjoe.com/post.php"

//Config----------------------
const char* ssid = your_ssid;
const char* pass = your_pass;
String token = your_token;
//----------------------------

void setup() {
  Serial.begin(115200);
  randomSeed(analogRead(0));

  //Wifi Connect
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  //Cek Status
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:
  pushWeb();
  delay(10000);
}
void pushWeb() {
  //Randomize Value Sensor
  int suhu = random(20, 40);
  int humid = random(50, 90);
  int lux = random(200, 4000);
  int gas = random(1, 15);
  int air = random(1, 15);

  //Casting
  String d1 = String(suhu);
  String d2 = String(humid);
  String d3 = String(lux);
  String d4 = String(gas);
  String d5 = String(air);;

  //Process HTTP
  HTTPClient postWeb;

  postWeb.begin(URLWEB);
  postWeb.addHeader("Content-Type", "application/x-www-form-urlencoded");

  String dataku = "apiKEY=" + token + "&d1=" + d1 + "&d2=" + d2 + "&d3=" + d3 + "&d4=" + d4 + "&d5=" + d5;
  Serial.println(dataku);

  int httpResponseCode = postWeb.POST(dataku);

  //  UNCOMENT TO CEK ERROR
  //     if (httpResponseCode>0) {
  //        Serial.print("HTTP Response code: ");
  //        Serial.println(httpResponseCode);
  //      }
  //      else {
  //        Serial.print("Error code: ");
  //        Serial.println(httpResponseCode);
  //      }
  postWeb.end();
}
