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

RTC_DS1307 RTC;
DateTime currentTime;

void setup() {
  Wire.begin();
  RTC.begin();
  //Check if RTC running, if not Set time.
  if (! RTC.isrunning()) {
  //Sets RTC to Time Sketch Uploaded
  RTC.adjust(DateTime(__DATE__, __TIME__));
  }
  
  currentTime = RTC.now();
  //Sets the Initial time of the clock from 12.
  setTime(currentTime);
}

void loop() {
  int hour, minute;
  currentTime = RTC.now();
  hour = currentTime.hour();
  minute = currentTime.minute();

}

void setTime(DateTime initialTime) {
  int totalMins, counter;
  totalMins = initialTime.hour()*60 + initialTime.minute();
  counter = 0;
  
  while (counter < totalMins) {
    incrementServo();
    counter++;
  }
 
}

void incrementServo() {
}
