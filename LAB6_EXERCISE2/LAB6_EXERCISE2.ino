#include <ThreeWire.h>
#include <RtcDS1302.h>
#define pinLed 7
int Sec = 0;

ThreeWire myWire(4,5,2); //IO, CLOCK, CE
RtcDS1302<ThreeWire>Rtc(myWire);

void setup() 
  {
    Serial.begin(9600);
    Serial.println("Start");
    Rtc.Begin();
    RtcDateTime setting_time(2020,2,2,23,31,0);// year, month, dayOfMonth, hour, minute, second
    Rtc.SetDateTime(setting_time);
    pinMode(pinLed, OUTPUT);
  }


void loop() 
{
  RtcDateTime now = Rtc.GetDateTime();
  digitalWrite(pinLed,now.TotalSeconds()%2);
  delay(1000);
  if(now.Second()%2==0)
  {
    digitalWrite(pinLed, HIGH);
    delay(500);
    digitalWrite(pinLed, LOW);
    delay(500);
    Serial.println(Sec);
    Sec = Sec+2;
  }
  if(Sec == 120)
  {
    Serial.print("Stop");
  }
}
