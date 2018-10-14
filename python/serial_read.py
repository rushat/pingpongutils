#!/usr/bin/python
import serial
import syslog
import time

#The following line is for serial over GPIO
port = '/dev/ttyACM0'

ard = serial.Serial(port,9600,timeout=5)
time.sleep(2) # wait for Arduino

i = 0

while (i < 10):
    # Serial read section
    msg = ard.read(ard.inWaiting()) # read all characters in buffer
    if (len(msg) > 0):    
        print ("Message from arduino: ")
        print (msg)
        i = i + 1
else:
    print "Exiting"
exit()
