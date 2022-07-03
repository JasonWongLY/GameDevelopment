import sys
import pygame
import time
from pygame.locals import *
from pyparsing import line_end

#global var

winner=None
draw=None
width=400
height=400
white=(255,255,255)
line_color=(0,0,0)
board=[[None]*3,[None]*3,[None]*3]

#pygame window
pygame.init()
fps=30
CLOCK=pygame.time.Clock()
screen = pygame.display.set_mode((width,height+200),0,32)
pygame.display.set_caption("TicTacToe")
screen.fill(white)

#load image
x_img=pygame.image.load("x.png")
o_img=pygame.image.load("o.png")

#resize image
x_img=pygame.transform.scale(x_img,(80,80))
o_img=pygame.transform.scale(o_img,(80,80))

def game_init_window():
    pygame.display.update()
    screen.fill(white)
    pygame.draw.rect(screen,(203, 195, 227),pygame.Rect(0,height,width,100))
    pygame.draw.line(screen,line_color,(width/3,0),(width/3,height),7)
    pygame.draw.line(screen,line_color,(width/3*2,0),(width/3*2,height),7)
    pygame.draw.line(screen,line_color,(0,width/3),(width,height/3),7)
    pygame.draw.line(screen,line_color,(0,width/3*2),(width,height/3*2),7)
    draw_status()
    print_player_size_no()

class player:
    def __init__(self,name):
        self.name=name
        self.small=2
        self.middle=2
        self.big=2


x=player('X')
o=player('O')
xo=x 
    
def print_player_size_no():
    font=pygame.font.Font(None,30)
    for i in range(3):
        pygame.draw.rect(screen,line_color,pygame.Rect(10+width/3*i,height+10,80,80),2)
        pygame.draw.rect(screen,line_color,pygame.Rect(100+width/3*i,height+35,20,20),2)
        

    

def draw_status():
    global draw
    if winner is None:
        message=xo.name+"'s Turn"
    else:
        message=winner+" won!"

    if draw:
        message="Game Draw!"
    font = pygame.font.Font(None,30)
    text=font.render(message,1,(255,255,255))
    screen.fill((0,0,0),(0,500,500,100))
    text_rect=text.get_rect(center=((width)/2,600-50))
    screen.blit(text,text_rect)
    pygame.display.update()

def check_win():
    global board, winner, draw
    # checking for winning rows
    for row in range(0, 3):
        if((board[row][0] == board[row][1] == board[row][2]) and (board [row][0] is not None)):
            winner = board[row][0]
            pygame.draw.line(screen, (250, 0, 0),
                         (0, (row + 1)*height / 3 -height / 6),
                         (width, (row + 1)*height / 3 - height / 6 ),
                         4)
            break
   
    # checking for winning columns
    for col in range(0, 3):
        if((board[0][col] == board[1][col] == board[2][col]) and (board[0][col] is not None)):
            winner = board[0][col]
            pygame.draw.line (screen, (250, 0, 0), ((col + 1)* width / 3 - width / 6, 0), \
                          ((col + 1)* width / 3 - width / 6, height), 4)
            break
   
    # check for diagonal winners
    if (board[0][0] == board[1][1] == board[2][2]) and (board[0][0] is not None):
          
        # game won diagonally left to right
        winner = board[0][0]
        pygame.draw.line (screen, (250, 70, 70), (50, 50), (350, 350), 4)
          
    if (board[0][2] == board[1][1] == board[2][0]) and (board[0][2] is not None):
          
        # game won diagonally right to left
        winner = board[0][2]
        pygame.draw.line (screen, (250, 70, 70), (350, 50), (50, 350), 4)
   
    if(all([all(row) for row in board]) and winner is None ):
        draw = True
  
    draw_status()

def drawXO(row,col):
    global board, xo
    
    if row == 1:
        posx = 30
     
    if row == 2:
        posx = width / 3 + 30
          
    if row == 3:
        posx = width / 3 * 2 + 30
   
    if col == 1:
        posy = 30
          
    if col == 2:
        posy = height / 3 + 30
      
    if col == 3:
        posy = height / 3 * 2 + 30

    board[row-1][col-1] = xo
      
    if(xo == 'x'):
        screen.blit(x_img, (posy, posx))
        xo = 'o'
      
    else:
        screen.blit(o_img, (posy, posx))
        xo = 'x'
    pygame.display.update()

def user_click():
    
    x,y=pygame.mouse.get_pos()
    # get x position
    if(x<width/3):
        col=1
    elif (x<width/3*2):
        col=2
    elif(x<width):
        col=3
    else:
        col=None
    # get y position
    if(y<height/3):
        row=1
    elif (y<height/3*2):
        row=2
    elif(y<height):
        row=3
    else:
        row=None
    
    if (row and col and board[row-1][col-1]is None):
        global xo
        drawXO(row,col)
        check_win()

def reset_game():
    global board, winner, xo, draw
    time.sleep(3)
    xo='x'
    draw=False
    game_init_window()
    winner=None
    board=[[None]*3,[None]*3,[None]*3]

game_init_window()

while True:
    for event in pygame.event.get():
        if event.type==pygame.QUIT:
            pygame.quit()
            sys.exit()
        elif event.type == pygame.MOUSEBUTTONDOWN:
            user_click()
            if (winner or draw):
                reset_game()
    
    pygame.display.update()
    CLOCK.tick(fps)