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
* When Powering up set clock to 12 and it will set itself to the current
* time.
*
* Written by Ian Curtis
* 12 February 2015
*/

#include <Wire.h>
#include "RTClib.h"
//720mins in 12 hours

//Ratio of Drive wheel to Clock wheel x:1
#define WHEEL_RATIO 1

DateTime currentTime;
DateTime *time;

void setup() {
  Wire.begin();
  RTC.begin();
  //Check if RTC running, if not Set time.
  if (! RTC.isrunning()) {
  //Sets RTC to Time Sketch Uploaded
  RTC.adjust(DateTime(__DATE__, __TIME__));
  }
  
  time = &currentTime;
  *time = RTC.now();
  //Sets the Initial time of the clock from 12.
  setTime(*time);
}

void loop() {
  int hour, minute;
  *time = RTC.now();
  hour = currentTime.hour();
  minute = currentTime.minute();

}

void setTime(Datetime *initalTime) {
  int totalMins, counter;
  totalMins = *initialTime.hour()*60 + *initialTime.min();
  counter = 0;
  
  while (counter < totalMins) {
    incrementServo();
    counter++;
  }
 
}
