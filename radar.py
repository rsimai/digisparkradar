#!/usr/bin/python
# 
# rsimai 2022
# example to continuously poll the movement status

import serial
import time

ser = serial.Serial('/dev/ttyACM0',timeout=1)
ser.baudrate = 9600

while True:
    ser.write(b'h')
    value = ser.read()
    value = int.from_bytes(value, byteorder='little')
    if value == 49:
        print("move")
    else:
        print("still")
    time.sleep(1);
ser.close()
