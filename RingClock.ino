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
#include <Servo.h>
//720mins in 12 hours

//Ratio of Drive wheel to Clock wheel x:1
#define WHEEL_RATIO 1
//Initial values for the servo
#define INITIAL_RESETSERVO 0
#define INITIAL_CLOCKSERVO 0
#define CLOCKSERVO_RESET 60
#define RESETSERVO_ANGLE 30


RTC_DS1307 RTC;
DateTime currentTime;
const DateTime *time = &currentTime;

int minCounter = 0;

Servo resetServo;
Servo clockServo;

void setup() {
    Wire.begin();
    //Sets RTC to Time Sketch Uploaded
    RTC.adjust(DateTime(__DATE__, __TIME__));
    currentTime = RTC.now();

    resetServo.attach(9);
    clockServo.attach(10);
    //Sets the servos to their initial starting point. 
    resetServo.write(INITIAL_RESETSERVO);
    clockServo.write(INITIAL_CLOCKSERVO);

    //Serial Printouts to check Function 
    //(remove comment block to use)
    /*
    Serial.begin(57600);
    Serial.print("hour: ");
    Serial.println(time->hour());
    Serial.print("minute: ");
    Serial.println(time->minute());
    Serial.print("day: ");
    Serial.println(time->day());
    */

    //Sets the Initial time of the clock from 12.
    setTime(&currentTime);
}

void loop() {
    int hour, minute;
    currentTime = RTC.now();
    hour = currentTime.hour();
    minute = currentTime.minute();
}

/** Sets the time on the clock relatively to 12 (start clock in this
    position.
    DateTime *initialTime Pointer to the current time on the RTC
*/
void setTime(DateTime *initialTime) {
    int totalMins, counter;
    totalMins = initialTime->hour()*60 + initialTime->minute();
    counter = 0;
    //Serial Printouts to check Function (remove comment to use)
    //Serial.print("Total Minutes passed in day: ");
    //Serial.println(totalMins);
    
    while (counter < totalMins) {
        incrementServo();
        counter++;
    }
 
}

/** Increments the Clock servo by one minute and calls the reset
*   if it is at the reset limit specified.
*/
void incrementServo() {
    if(clockServo.read() >= (CLOCKSERVO_RESET + INITIAL_CLOCKSERVO)) {
        resetClockServo();
    }
    //Increment by one minute
    clockServo.write(clockServo.read() + (WHEEL_RATIO*(1/720));
}

/** Resets the clock servo back to its initial value
*/
void resetClockServo() {
  //Disengage Clock Servo
  resetServo.write(RESETSERVO_ANGLE);
  delay(500);
  //Reset Clock Servo back to initial Value
  clockServo.write(INITIAL_CLOCKSERVO);
  delay(500);
  //Re-engage Clock Servo
  resetServo.write(INITIAL_RESETSERVO);
  delay(500);
}
