#include <Servo.h>
#include <SoftwareSerial.h>

Servo hori;
Servo verti;
int servoh = 90;
int servohhigh = 165;
int servohlow = 15;

int servov = 90;
int servovhigh = 120;
int servovlow = 60;

int ldrtopleft = 0;
int ldrtopright = 1;
int ldrbottomleft = 2;
int ldrbottomright = 3;

void setup()
{
  Serial.begin(9600);

  hori.attach(9);
  verti.attach(10);
  hori.write(servoh);
  verti.write(servov);
  delay(1000);
  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH);
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);
  pinMode(3, OUTPUT);
  digitalWrite(3, HIGH);
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
}

void loop()
{
  int topleft = analogRead(ldrtopleft);
  int topright = analogRead(ldrtopright);
  int bottomleft = analogRead(ldrbottomleft);
  int bottomright = analogRead(ldrbottomright);

  int averagetop = (topleft + topright)/2;
  int averagebottom = (bottomleft + bottomright)/2;
  int averageleft = (topleft + bottomleft)/2;
  int averageright = (topright + bottomright)/2;

  int tolerance = 50;
  // For top movement
  int verticaldifference = averagetop - averagebottom;

  if(verticaldifference > tolerance || verticaldifference < -1*tolerance)
  {
    if(averagetop > averagebottom)
    {
      servov = servov - 1;
      if (servov < servovlow)
      {
        servov = servovlow;
      }
    }
    else if (averagetop < averagebottom)
    {
      servov = servov + 1;
      if(servov > servovhigh)
      {
        servov = servovhigh;
      }
    }
    verti.write(servov);
  }

  int horizontaldifference = averageleft - averageright;

  if(horizontaldifference > tolerance || horizontaldifference < -1* tolerance)
  {
    if(averageleft > averageright)
    {
      servoh = servoh + 1;
      if(servoh > servohhigh)
      {
        servoh = servohhigh;
      }
    }
    else if(averageleft < averageright)
    {
      servoh = servoh - 1;
      if(servoh < servohlow)
      {
        servoh = servohlow;
      }
    }
    hori.write(servoh);
  }

  if(topleft <300)
  {
    digitalWrite(7, LOW);
  }
  else
  {
    digitalWrite(7, HIGH);
  }
  if(topright <300)
  {
    digitalWrite(4, LOW);
  }
  else
  {
    digitalWrite(4, HIGH);
  }
  if(bottomleft <300)
  {

    digitalWrite(3, LOW);
  }
  else
  {
    digitalWrite(3, HIGH);
  }
  if(bottomright < 300)
  {
    digitalWrite(2, LOW);
  }
  else
  {
    digitalWrite(2, HIGH);
  }

  Serial.print(topleft);
  Serial.print(" ");
  Serial.print(topright);
  Serial.print(" ");
  Serial.print(bottomleft);
  Serial.print(" ");
  Serial.print(bottomright);
  Serial.print('\n');

  
  int datareq = Serial.read();
  if(datareq == 1)
  {
    Serial.write(topleft);
  }
  else if (datareq == 2)
  {
    Serial.write(topright);
  }
  else if (datareq == 3)
  {
    Serial.write(bottomleft);
  }
  else if (datareq == 4)
  {
    Serial.write(bottomright);
  }
  else if (datareq == 5)
  {
    Serial.write(servov);
  }
  else if (datareq == 6)
  {
    Serial.write(servoh);
  }
}




































