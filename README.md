# RingClock
Code and Models (to Come later) for Ring Clock 
Written in Arduino.
A clock that uses servos to turn a ring. The position of the lone hand indicates the hour and approximate minute (by how far between the hours it is).

Requires an Arduino and the Datalogging shield for its RTC, plus two servos.
The Shield needs the following library:
A fork of JeeLab's RTC library. (http://adafru.it/cfG)which is then installed
in your Arduino directory (http://adafru.it/aYM) in a folder called RTClib. 
Although this may vary depending on your Shield/RTC.

To setup Clock set Ring with Hand to 12 and reset Arduino.
