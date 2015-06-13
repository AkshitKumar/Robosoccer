import serial
import sys
import pygame
from time import sleep
ser = serial.Serial()
ser.setPort("/dev/tty.SLAB_USBtoUART")
ser.baudrate = 9600
ser.open()
sleep(2)
pygame.init()

gameDisplay = pygame.display.set_mode((300,300))
pygame.display.set_caption("Key Information")

pygame.display.update()

if(ser.isOpen()):
	while 1:
		try:
			ser.flush()
			for event in pygame.event.get():
				if event.type == pygame.KEYDOWN:
					if event.key == pygame.K_LEFT:
						print "Left"
						ser.write('l')
					elif event.key == pygame.K_RIGHT:
						print "Right"
						ser.write('r')
					elif event.key == pygame.K_DOWN:
						print "Down"
						ser.write('d')
					elif event.key == pygame.K_UP:
						print "Up"
						ser.write('u')
				elif event.type == pygame.QUIT:
					pygame.quit()
					sys.exit()
			sleep(0.5)
		except:
			ser.close()
