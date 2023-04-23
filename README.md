# Alarm System - Using an infrared motion sensor to detect intruders
## Complexity
This DIY alarm system can detect intruders using an infrared motion sensor. The best-practise is to face the sides of the dome (of the motion sensor) towards your doors or windows. If a intruder approaches the sensor perpendicular, the sensor will be less sensitive. To improve the design, multiple sensors should be used and a WiFi Shield in order to sent direct http requsts to the PushBullet API.

Some challenges were:
* Removing noise from the Buzzer, solved by adding a rectifier diode.
* Receiving Serial data using Python.
* Setting up the PushBullet API. 

This is a course related project and part of the problemset in Harvards CS50x week 4.

## Files
**alarm_system.ino** &rarr; 
contains the code that is running on the Arduino Uno microcontroller. The passive Buzzer receives a sin wave sound frequency using Pulse Width Modulation.

**push_notification.py** &rarr;
contains the python code to receive the Serial data from the control board and sent request to PushBullet API. After 5 notifications the program will stop.

## How to run
![alt text](https://github.com/DenisPals/Filter/blob/main/setupImg.jpeg?raw=true)
Build the circuit according to the schematics and connect the control board to the computer via USB. The motion sensor will take one minute to be set up, then run
> python push_notification.py

After moving, you should receive push notifications, warning you that the motion sensor has been triggered.
The device Port (COM4) may need to be changed according to the information displayed in your device drivers control panel.

## Output

![alt text](https://github.com/DenisPals/Filter/blob/main/notificationImg.jpeg?raw=true)