import sys
import pygame
import time
from pygame.locals import *
from math import ceil
import numpy as np

#global var
xo='x'
winner=None
draw=None
width=800
height=800
white=(255,255,255)
black=(0,0,0)
gray=(211,211,211)
board=np.full((9,3,3),None)

#pygame window
pygame.init()
fps=30
CLOCK=pygame.time.Clock()
screen = pygame.display.set_mode((width,height+100),0,32)
pygame.display.set_caption("TicTacToe")
screen.fill(white)

#load image
init_window=pygame.image.load("cover.png")
x_img=pygame.image.load("x.png")
o_img=pygame.image.load("o.png")

#resize image
init_window=pygame.transform.scale(init_window,(width,height+100))
x_img=pygame.transform.scale(x_img,(80,80))
o_img=pygame.transform.scale(o_img,(80,80))

def game_init_window():
    #screen.blit(init_window,(0,0))
    pygame.display.update()
    #time.sleep(1)
    screen.fill(white)
    # draw sub-line
    for i in range(1,10):
        pygame.draw.line(screen,gray,(width/9*i,0),(width/9*i,height),3)
        pygame.draw.line(screen,gray,(0,height/9*i),(width,height/9*i),3)
    # draw main-line
    pygame.draw.line(screen,black,(width/3,0),(width/3,height),7)
    pygame.draw.line(screen,black,(width/3*2,0),(width/3*2,height),7)
    pygame.draw.line(screen,black,(0,height/3),(width,height/3),7)
    pygame.draw.line(screen,black,(0,height/3*2),(width,height/3*2),7)
    draw_status()

def draw_status():
    global draw
    if winner is None:
        message=xo.upper()+"'s Turn"
    else:
        message=winner.upper()+" won!"

    if draw:
        message="Game Draw!"
    # output turn
    font = pygame.font.Font(None,30)
    text=font.render(message,1,(255,255,255))
    screen.fill((0,0,0),(0,800,800,100))
    text_rect=text.get_rect(center=(width/2,900-50))
    screen.blit(text,text_rect)
    pygame.display.update()

def drawXO(sec,row,col,a,b):
    global board,xo
    if b==1:
        posx=4
    if b==2:
        posx=width/9+4
    if b==3:
        posx=width/9*2+4
    if b==4:
        posx=width/9*3+4
    if b==5:
        posx=width/9*4+4
    if b==6:
        posx=width/9*5+4
    if b==7:
        posx=width/9*6+4
    if b==8:
        posx=width/9*7+4
    if b==9:
        posx=width/9*8+4
    
    # column image position
    
    if a==1:
        posy=4
    if a==2:
        posy=height/9+4
    if a==3:
        posy=height/9*2+4
    if a==4:
        posy=height/9*3+4
    if a==5:
        posy=height/9*4+4
    if a==6:
        posy=height/9*5+4
    if a==7:
        posy=height/9*6+4
    if a==8:
        posy=height/9*7+4
    if a==9:
        posy=height/9*8+4

    board[sec-1][row-1][col-1]=xo
    if(xo=='x'):
        screen.blit(x_img,(posy,posx))
        xo='o'
    else:
        screen.blit(o_img,(posy,posx))
        xo='x'
    pygame.display.update()

def user_Click():
    x,y = pygame.mouse.get_pos()
    margin=width/9
    a=x//margin+1
    b=y//margin+1
    sec=ceil(a/3)+(ceil(b/3)-1)*3
    col=(int)((a-1)%3+1)
    row=(int)((b-1)%3+1)
    if(row and col and board[sec-1][row-1][col-1] is None):
        global xo 
        drawXO(sec,row,col,a,b)
        #check_win()

def reset_game():
    global board, winner, xo, draw
    time.sleep(3)
    xo='x'
    draw=False
    game_init_window()
    winner=None
    board=np.empty((9,3,3))

game_init_window()




while True:
    for event in pygame.event.get():
        if event.type==pygame.QUIT:
            pygame.quit()
            sys.exit()
        elif event.type == pygame.MOUSEBUTTONDOWN:
            user_Click()
            if(winner or draw):
                reset_game()
    pygame.display.update()
    CLOCK.tick(fps)