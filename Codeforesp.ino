#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_TEMPLATE_ID "TMPL3hssOhSA9"
#define BLYNK_TEMPLATE_NAME "Solar Tracker"
#define BLYNK_AUTH_TOKEN "mMO_zyr7DKuxfEzndOWN727hYoS0dQzM"

#define RX (3)
#define TX (1)

void setup()
{
  Serial.begin(115200);
  Serial.println();

  WiFi.begin("Yash", "123456789");

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
}

void loop ()
{
  Serial.write(1);
  while(!Serial.available());
  int topleft = Serial.read();

  Serial.write(2);
  while(!Serial.available());
  int topright = Serial.read();

  Serial.write(3);
  while(!Serial.available());
  int bottomleft = Serial.read();

  Serial.write(4);
  while(!Serial.available());
  int bottomright = Serial.read();

  Serial.write(5);
  while(!Serial.available());
  int servovangle = Serial.read();

  Serial.write(6);
  while(!Serial.available());
  int Servohangle = Serial.read();
}