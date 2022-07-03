from turtle import window_width
import pygame
import random
import numpy as np
import sys

window_height=700
window_width=800
board_height=600
board_width=300
block_size=30

O=[     [0,0,0,0],
        [0,1,1,0],
        [0,1,1,0],
        [0,0,0,0]  ]

I=[     [0,1,0,0],
        [0,1,0,0],
        [0,1,0,0],
        [0,1,0,0]  ]

S=[     [0,0,0,0],
        [0,1,1,0],
        [1,1,0,0],
        [0,0,0,0]  ]

Z=[     [0,0,0,0],
        [1,1,0,0],
        [0,1,1,0],
        [0,0,0,0]  ]

L=[     [0,1,0,0],
        [0,1,0,0],
        [0,1,1,0],
        [0,0,0,0]  ]

J=[     [0,0,1,0],
        [0,0,1,0],
        [0,1,1,0],
        [0,0,0,0]  ]

T=[     [0,0,0,0],
        [1,1,1,0],
        [0,1,0,0],
        [0,0,0,0]  ]

shapes=[O,I,S,Z,L,J,T]
shapes_color=[(127,255,212),(152,245,255),(255,193,37),(255,105,180),(255,246,143),(132,112,255),(160,82,45)]

class piece:
    def __init__(self,x,y):
        self.x=x
        self.y=y
        self.shape=random.choice(shapes)
    
    def rotate(self):
        self.shape=list(map(list, zip(self.shape)))
        for i in self.shape:
            i.reverse()


pygame.init()
screen=pygame.display.set_mode((window_width,window_height),0,32)
pygame.display.set_caption("Tetris")
screen.fill((255,255,255))
CLOCK=pygame.time.Clock()
board=np.full((20,10),0)


def print_shape():
    return


def move_right():
    return 

def move_left():
    return

def move_down():
    return


    
def print_board():
    # Main board 
    board_rect=pygame.Rect(100,50,300,600)
    pygame.draw.rect(screen,(205,240,255),board_rect)
    pygame.draw.rect(screen,(0,0,0),pygame.Rect(100,50,300,600),2)
    for i in range(1,20):
        pygame.draw.line(screen,(0,0,0),(100,board_height/20*i+50),(400-1,board_height/20*i+50),1)
    for i in range(1,10):
        pygame.draw.line(screen,(0,0,0),(board_width/10*i+100,50),(board_width/10*i+100,649),1)

    # Next shape board
    pygame.draw.rect(screen,(205,240,255),pygame.Rect(500,50,200,200))
    pygame.draw.rect(screen,(0,0,0),pygame.Rect(500,50,200,200),2)
    

def game_flow():
    current_shape=piece(5,0)
    pygame.display.update()
    screen.fill((255,255,255))

game_flow()
while True:
    for event in pygame.event.get():
        if event.type==pygame.QUIT:
            pygame.quit()
            sys.exit()
        
    pygame.display.update()
    print_board()
    CLOCK.tick(30)