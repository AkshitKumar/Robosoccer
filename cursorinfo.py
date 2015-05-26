import pygame
import serial
serPort = '/dev/tty.usbmodem6bbd7002'
baudRate = 9600
ser = serial.Serial(serPort,baudRate)
ser.open()
pygame.init()

gameDisplay = pygame.display.set_mode((800,600))
pygame.display.set_caption("Cursor Information")

pygame.display.update()

while 1:
	try:
    	for event in pygame.event.get():
    	    mousex,mousey = event.pos
    	    mousex = str(chr(mousex))
    	    mousey = str(chr(mousey))
    	    ser.write(mousex)
    	    a = ser.readline()
    	    print a
    	    ser.write(mousey)
    	    b = ser.readline()
    	    print b
    except:
    	ser.close()

pygame.quit()
quit()
