#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
#include <BlynkSimpleEsp8266.h>

const char* ssid = "Yash";
const char* password = "123456789";

const char* blynkssid = "Yash";
const char* blynkpassword = "Yash1234";

#define BLYNK_AUTH_TOKEN "mMO_zyr7DKuxfEzndOWN727hYoS0dQzM"

int VIRTUAL_PIN1 = V1;
int VIRTUAL_PIN2 = V2;
int VIRTUAL_PIN3 = V3;
int VIRTUAL_PIN4 = V4;
int VIRTUAL_PIN5 = V5;
int VIRTUAL_PIN6 = V6;
int VIRTUAL_PIN7 = V7;

#define RX_PIN 3
#define TX_PIN 1

SoftwareSerial mySerial(RX_PIN, TX_PIN); // RX, TX

void setup()
{
  Serial.begin(115200);
  mySerial.begin(9600);
  Serial.println();
  pinMode(TX_PIN, OUTPUT);
  pinMode(RX_PIN, INPUT);
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
  
  int z = 1;
  mySerial.write(z);
  while(!mySerial.available());
  int topleft = mySerial.read();
  Blynk.virtualWrite(VIRTUAL_PIN1, topleft);
  Serial.print(topleft);
  z = z+1;

  mySerial.write(z);
  while(!mySerial.available());
  int topright = mySerial.read();
  Blynk.virtualWrite(VIRTUAL_PIN2, topright);
  z = z+1;

  mySerial.write(z);
  while(!mySerial.available());
  int bottomleft = mySerial.read();
  Blynk.virtualWrite(VIRTUAL_PIN3, bottomleft);
  z = z+1;

  mySerial.write(z);
  while(!mySerial.available());
  int bottomright = mySerial.read();
  Blynk.virtualWrite(VIRTUAL_PIN4, bottomright);
  z = z+1;

  mySerial.write(z);
  while(!mySerial.available());
  int servovangle = mySerial.read();
  Blynk.virtualWrite(VIRTUAL_PIN5, servovangle);
  z = z+1;

  mySerial.write(z);
  while(!mySerial.available());
  int servohangle = mySerial.read();
  Blynk.virtualWrite(VIRTUAL_PIN6, servohangle);
  z = z+1;

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
  Blynk.run();

}