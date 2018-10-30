#include <Servo.h>
Servo servo1;
Servo servo2;
#define m1 2
#define m2 3
#define m3 4
#define m4 5

void setup()
{
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  servo1.attach(6);
  servo2.attach(7);
  Serial.begin(9600);
}
void loop()
{
  if(Serial.available()>0)
  {
    char val = Serial.read();
    Serial.println(val);
    if(val == 'F')
    {
      Serial.println("Forward");
      digitalWrite(m1, HIGH);
      digitalWrite(m2, LOW);
      digitalWrite(m3, HIGH);
      digitalWrite(m4, LOW);
    }
    else if(val == 'B')
    {
      Serial.println("Backward");
      digitalWrite(m1, LOW);
      digitalWrite(m2, HIGH);
      digitalWrite(m3, LOW);
      digitalWrite(m4, HIGH);
    }
    else if(val == 'L')
    {
      Serial.println("Left");
      digitalWrite(m1, HIGH);
      digitalWrite(m2, LOW);
      digitalWrite(m3, LOW);
      digitalWrite(m4, LOW);
    }
    else if(val == 'R')
    {
      Serial.println("Right");
      digitalWrite(m1, LOW);
      digitalWrite(m2, LOW);
      digitalWrite(m3, HIGH);
      digitalWrite(m4, LOW);
    }
    else if(val == 'S')
    {
      Serial.println("Stop");
      digitalWrite(m1, LOW);
      digitalWrite(m2, LOW);
      digitalWrite(m3, LOW);
      digitalWrite(m4, LOW);
    }
    else if(val == 'f')
    {
      servo1.write(180);
      servo2.write(180);
    }
    else if(val == 'b')
    {
      servo1.write(0);
      servo2.write(0);
    }
  }
}
