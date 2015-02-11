#include <Wire.h>
#include "RTClib.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  Wire.begin();
  RTC.begin();
  //Check if RTC running, if not Set time.
  if (! RTC.isrunning()) {
  Serial.println("RTC is NOT running!");
  //Sets RTC to Time Sketch Uploaded
  RTC.adjust(DateTime(__DATE__, __TIME__));
  }

}

void loop() {
  int hour, minute;
  DateTime currentTime = RTC.now();
  hour = currentTime.hour();
  minute = currentTime.minute();

}
