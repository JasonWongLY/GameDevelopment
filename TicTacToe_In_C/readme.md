This is the TicTacToe written in C and can be complier in the command line.</br>
This include two version of TicTacToe:</br>
One is the normal version, where you may select one or two player to play the game.</br>
</br>
The other version is the 9x9 version where the whole game board is divided into 9 section and each section contain 3x3 game board.</br>
<pre>
 123 |     |      
 456 | (2) | (3)  
 789 |     |      
-----+-----+----- 
     |     |      
 (4) | (5) | (6)  
     |     |      
-----+-----+----- 
     |     |      
 (7) | (8) | (9)  
     |     |      </pre>
The basic game flow is that the first player can choose to place the chess in any position of any section. Once the first player have placed the chess, </br>
the next player should place the specific section which is the position that the previous player placed.</br>
For example:</br>
  if Player 1 start to play the game and he decided to place the chess in section 1 position 9</br>
  then Player 2 should and must place their chess in any position of section 9</br>
  and so on...</br>
Once the specific section is full, then that Player can choose to place the chess in any other empty position in any section.</br>
</br>
Because this game is processed in command line which is not that user-friendly so I will re-produce this game with GUI in GameDevelopment/TicTacToe folder</br>
