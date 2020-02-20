#include <ThreeWire.h>
#include <RtcDS1302.h>
#define pinLed 7

ThreeWire myWire(4,5,2); //IO, CLOCK, CE
RtcDS1302<ThreeWire>Rtc(myWire);

void setup() 
  {
    Rtc.Begin();
    RtcDateTime setting_time(2020,2,2,23,31,10);// year, month, dayOfMonth, hour, minute, second
    Rtc.SetDateTime(setting_time);
    pinMode(pinLed, OUTPUT);
  }


void loop() {
  RtcDateTime now = Rtc.GetDateTime();
  digitalWrite(pinLed,now.TotalSeconds()%2);
  delay(1000);
}
