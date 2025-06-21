#include <SoftwareSerial.h>
SoftwareSerial BTSerial (2,3);
char m=0;
void setup() 
{
pinMode(A0, OUTPUT);  
pinMode(A2, OUTPUT);
pinMode(A4, OUTPUT);
pinMode(A5, OUTPUT);
pinMode(12, OUTPUT);
pinMode(11, OUTPUT);

BTSerial.begin (9600); 
Serial.begin(9600);
}
void loop() 
{
 if (BTSerial.available ()) {
   m= BTSerial.read (); 
  // Save command received in Bluetooth to command
  Serial.println(m);
 if (m=='F')
{
  digitalWrite(A0, HIGH);
  digitalWrite(A2, LOW);
  digitalWrite(A4, HIGH);
  digitalWrite(A5, LOW);
  }

  else if (m=='B')
{
  
  digitalWrite(A0, LOW);
  digitalWrite(A2, HIGH);
  digitalWrite(A4, LOW);
  digitalWrite(A5, HIGH);
  }

else if (m=='L')
{
  digitalWrite(A0, HIGH);
  digitalWrite(A2, LOW);
  digitalWrite(A4, LOW);
  digitalWrite(A5, HIGH);
  
  }

 else if (m=='R')
{
  digitalWrite(A0, LOW);
  digitalWrite(A2, HIGH);
  digitalWrite(A4, HIGH);
  digitalWrite(A5, LOW);
  
  }

else if (m=='S')
{
  digitalWrite(A0, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(A4, LOW);
  digitalWrite(A5, LOW);
  } 
  else if (m=='W')
{
  digitalWrite(12, HIGH);
  } 
  else if (m=='w')
{
  digitalWrite(12, LOW);
  
  } 
   else if (m=='U')
{
  digitalWrite(11, HIGH);
  } 
  else if (m=='u')
{
  digitalWrite(11, LOW);
  
  } 
 }
}
