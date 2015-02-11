#include <Wire.h>
#include "RTClib.h"

//Ration of Clock wheel to drive wheel
#define WHEEL_RATIO 1


void setup() {
  Wire.begin();
  RTC.begin();
  //Check if RTC running, if not Set time.
  if (! RTC.isrunning()) {
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
