# digisparkradar
5V radar sensor to detect movement, connected to digispark (attiny85)

* GND - GND
* Vin - P0
* OUT - P2

The digispark will flash the onboard LED when motion is detected, it should send an increasing number through /dev/ttyACM0 (or wherever it appears). 
