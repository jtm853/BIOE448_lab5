This lab was completed on February 19, 2025 in the Microcontrollers lab of Dr. James Long.

Here, we show the implementation of the Bluetooth Low Energy protocol in a device that uses an ultrasonic sensor as a rangefinder. We connected an iPhone to the Arduino board running the ArduinoBLE library,
and used the writing of values to the Arduino as a trigger for the ultrasonic sensor. The sensor's raw data was then processed to reach a distance in centimeters to the acoustically reflective object,
and this value was written to the readChar characteristic. The central device (iPhone) could then read this value as a hexadecimal output remotely.
