#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
#include <BlynkSimpleEsp8266.h>

const char* ssid = "Yash";
const char* password = "123456789";

const char* blynkssid = "Yash";
const char* blynkpassword = "Yash1234";

#define BLYNK_AUTH_TOKEN "mMO_zyr7DKuxfEzndOWN727hYoS0dQzM"

#define RX_PIN 3
#define TX_PIN 1

void setup()
{
  Serial.begin(115200);
  Serial.println();
  pinMode(TX_PIN,OUTPUT);
  pinMode(RX_PIN,INPUT);
  WiFi.begin(ssid, password);

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected");

  Blynk.begin(BLYNK_AUTH_TOKEN, blynkssid, blynkpassword);
  Serial.println("Connected to Blynk");
}

void loop ()
{
  Blynk.run();
  Serial.write(0);

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
  int servohangle = Serial.read();

  Serial.print(topleft);
  Serial.print(" ");
  Serial.print(topright);
  Serial.print(" ");
  Serial.print(bottomleft);
  Serial.print(" ");
  Serial.print(bottomright);
  Serial.print(" ");
  Serial.print(servovangle);
  Serial.print(" ");
  Serial.print(servohangle);
  Serial.print(" ");

}