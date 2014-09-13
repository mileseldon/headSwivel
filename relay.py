import serial
import time
import curses
from sys import stdin
ser = serial.Serial('/dev/tty.usbmodemfa131', 9600)
time.sleep(3)


# Initialize the terminal
win = curses.initscr()
curses.cbreak()
win.nodelay(True)
ser.write(bytes(1))
while True:
    key = win.getch()
    if key != -1:
            if(key == 113): #q
                sys.exit(0)
            if(key == 119): #w
                ser.write(bytes(1))
            if(key == 97): #a
                ser.write(bytes(2))
            if(key == 115): #s
                ser.write(bytes(3))
            if(key == 100):#d
                ser.write(bytes(4))

"""
while True:
    x = stdin.read(1)
    print x
    if(x == 'w'):
        ser.write(bytes(1))
    if(x == 'a'):
        ser.write(bytes(2))
    if(x == 's'):
        ser.write(bytes(3))
    if(x == 'd'):
        ser.write(bytes(4))
"""