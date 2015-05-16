import pygame

pygame.init()

gameDisplay = pygame.display.set_mode((800,600))
pygame.display.set_caption("Cursor Information")

pygame.display.update()

while 1:
    for event in pygame.event.get():
        mousex,mousey = event.pos
        print mousex,mousey

pygame.quit()
quit()
