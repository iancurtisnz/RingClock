/**
* Program for a RingClock that uses two servos to drive a large ring
* which indicates the hour and approximate minute by its location.
*
* This uses Arduino and the Datalogging shield for its RTC.
* Requires a fork of JeeLab's RTC library. (http://adafru.it/cfG) 
* Then install it in your Arduino directory (http://adafru.it/aYM) 
* in a folder called RTClib. Although this may vary depending on your
* Shield/RTC.
*
* Written by Ian Curtis
* 12 February 2015
*/

#include <Wire.h>
#include "RTClib.h"
//720mins in 12 hours

//Ratio of Drive wheel to Clock wheel x:1
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
