#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

#define EMPTY 0
#define CIRCLE 1
#define CROSS 2
int uGameBoard[10][3][3] = {};
int N = 9;
int uIsFull[10];

//Function For Ultimate Game Mode
int checkAlreadyPlaced(int ,int );
int sectionIsFull(int);
void placeMark(int*, int, int);
int uPlayerScore[3] = {};
int endGame;
void printFirstRow(int no) {
    for (int i = 0; i < 3; i++)
    {
        if (uGameBoard[no][2][i] == 0)
        {
            printf("| |");

        }
        else if (uGameBoard[no][2][i] == 1)
        {
            printf("|O|");

        }
        else if (uGameBoard[no][2][i] == 2)
        {
            printf("|X|");

        }
    }
    printf("  ||  ");
}
void printSecondRow(int no) {
    for (int i = 0; i < 3; i++)
    {
        if (uGameBoard[no][1][i] == 0)
        {
            printf("| |");

        }
        else if (uGameBoard[no][1][i] == 1)
        {
            printf("|O|");

        }
        else if (uGameBoard[no][1][i] == 2)
        {
            printf("|X|");

        }
    }
    printf("  ||  ");
}
void printThirdRow(int no) {
    for (int i = 0; i < 3; i++)
    {
        if (uGameBoard[no][0][i] == 0)
        {
            printf("| |");

        }
        else if (uGameBoard[no][0][i] == 1)
        {
            printf("|O|");

        }
        else if (uGameBoard[no][0][i] == 2)
        {
            printf("|X|");

        }
    }
    printf("  ||  ");
}
void printUGameBoard(int uGameBoard[10][3][3]) {
    printf("===============================================\n");
    printf("||             ||             ||             ||  \n||  ");
    for (int i = 1; i < 4; i++)
    {
        printFirstRow(i);
    }
    printf("\n||  ");
    for (int i = 1; i < 4; i++)
    {
        printSecondRow(i);
    }
    printf("\n||  ");
    for (int i = 1; i < 4; i++)
    {
        printThirdRow(i);
    }
    printf("\n||  ");
    printf("           ||             ||             ||  \n");
    printf("===============================================\n");
    printf("||             ||             ||             ||  \n||  ");

    for (int i = 4; i < 7; i++)
    {
        printFirstRow(i);
    }
    printf("\n||  ");
    for (int i = 4; i < 7; i++)
    {
        printSecondRow(i);
    }
    printf("\n||  ");
    for (int i = 4; i < 7; i++)
    {
        printThirdRow(i);
    }
    printf("\n||  ");
    printf("           ||             ||             ||  \n");
    printf("===============================================\n");
    printf("||             ||             ||             ||  \n||  ");

    for (int i = 7; i < 10; i++)
    {
        printFirstRow(i);
    }
    printf("\n||  ");
    for (int i = 7; i < 10; i++)
    {
        printSecondRow(i);
    }
    printf("\n||  ");
    for (int i = 7; i < 10; i++)
    {
        printThirdRow(i);
    }
    printf("\n||  ");
    printf("           ||             ||             ||  \n");
    printf("===============================================\n");
}
void instructionForUltimate(void)
{
    printf("===========\n");
    printf("||1||2||3||\n");
    printf("||4||5||6||\n");
    printf("||7||8||9||\n");
    printf("===========\n");
    printf("The section number and the position number are follwin gthe number stated above\n");
    
}
void seekOneInput(int* section,int uCurrentPlayer){
    int place;
    printf("Player %d, Please place your mark at Section %d : ",uCurrentPlayer,*section);
    scanf("%d", &place);
    if (checkAlreadyPlaced(place, *section) == 0)
    {
        placeMark(section, place,uCurrentPlayer);
    }
    else
    {
        printf("The position that you choose already has a mark. Please choose another position!");
        system("pause");
        seekOneInput(section,uCurrentPlayer);
    }
}
void seekTwoInput(int *section,int uCurrentPlayer){
    int place;
    printf("Player %d, Please select the section you want to place your mark : ", uCurrentPlayer);
    scanf("%d", &*section);
    if(sectionIsFull(*section)==0){
        printf("Please place your mark at Section %d : ", *section);
        scanf("%d", &place);
        if (checkAlreadyPlaced(place, *section) == 0)
        {
            placeMark(section, place, uCurrentPlayer);
        }
        else
        {
            printf("The position that you choose already has a mark. Please choose another position!");
            system("pause");
            seekTwoInput(section,uCurrentPlayer);
        }
    }
    else
    {
        printf("This section is already full. Please select another section!");
        system("pause");
        seekTwoInput(section,uCurrentPlayer);
    }
    
}
int sectionIsFull(int section){
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (uGameBoard[section][i][j] == 0)
            {
                return 0;
            }

        }
    }
    return 1;
}
int checkAlreadyPlaced(int place,int section){
    
        switch (place)
        {
        case 1:
            if (uGameBoard[section][2][0] != 0)
                return 1;
            break;
        case 2:
            if (uGameBoard[section][2][1] != 0)
                return 1;
            break;
        case 3:
            if (uGameBoard[section][2][2] != 0)
                return 1;
            break;
        case 4:
            if (uGameBoard[section][1][0] != 0)
                return 1;
            break;
        case 5:
            if (uGameBoard[section][1][1] != 0)
                return 1;
            break;
        case 6:
            if (uGameBoard[section][1][2] != 0)
                return 1;
            break;
        case 7:
            if (uGameBoard[section][0][0] != 0)
                return 1;
            break;
        case 8:
            if (uGameBoard[section][0][1] != 0)
                return 1;
            break;
        case 9:
            if (uGameBoard[section][0][2] != 0)
                return 1;
            break;
        }
        return 0;
    
}
void placeMark(int* section, int input, int player){
    switch (input)
    {
    case 1:
        uGameBoard[*section][2][0] = player;
        *section = 1;
        break;
    case 2:
        uGameBoard[*section][2][1] = player;
        *section = 2;
        break;
    case 3:
        uGameBoard[*section][2][2] = player;
        *section = 3;
        break;
    case 4:
        uGameBoard[*section][1][0] = player; 
        *section = 4;
        break;
    case 5:
        uGameBoard[*section][1][1] = player; 
        *section = 5;
        break;
    case 6:
        uGameBoard[*section][1][2] = player; 
        *section = 6;
        break;
    case 7:
        uGameBoard[*section][0][0] = player; 
        *section = 7;
        break;
    case 8:
        uGameBoard[*section][0][1] = player; 
        *section = 8;
        break; 
    case 9:
        uGameBoard[*section][0][2] = player; 
        *section = 9;
        break;

    }
}
void endGameTask()
{
    for (int i = 1; i < 10; i++)
    {
        if (uGameBoard[i][0][0] == uGameBoard[i][0][1] && uGameBoard[i][0][1] == uGameBoard[i][0][2] && uGameBoard[i][0][0] != 0)
        {
            uPlayerScore[uGameBoard[i][0][0]]++;
        }
        if (uGameBoard[i][1][0] == uGameBoard[i][1][1] && uGameBoard[i][1][1] == uGameBoard[i][1][2] && uGameBoard[i][1][0] != 0)
        {
            uPlayerScore[uGameBoard[i][1][0]]++;
        }
        if (uGameBoard[i][2][0] == uGameBoard[i][2][1] && uGameBoard[i][2][1] == uGameBoard[i][2][2] && uGameBoard[i][2][0] != 0)
        {
            uPlayerScore[uGameBoard[i][2][0]]++;
        }
        if (uGameBoard[i][1][1] == uGameBoard[i][2][1] && uGameBoard[i][1][1] == uGameBoard[i][0][1] && uGameBoard[i][1][1] != 0)
        {
            uPlayerScore[uGameBoard[i][1][1]]++;
        }
        if (uGameBoard[i][0][2] == uGameBoard[i][1][2] && uGameBoard[i][2][2] == uGameBoard[i][1][2] && uGameBoard[i][0][2] != 0)
        {
            uPlayerScore[uGameBoard[i][0][2]]++;
        }
        if (uGameBoard[i][0][0] == uGameBoard[i][1][0] && uGameBoard[i][1][0] == uGameBoard[i][2][0] && uGameBoard[i][0][0] != 0)
        {
            uPlayerScore[uGameBoard[i][0][0]]++;
        }
        if (uGameBoard[i][0][0] == uGameBoard[i][1][1] && uGameBoard[i][1][1] == uGameBoard[i][2][2] && uGameBoard[i][0][0] != 0)
        {
            uPlayerScore[uGameBoard[i][0][0]]++;
        }
        if (uGameBoard[i][0][2] == uGameBoard[i][1][1] && uGameBoard[i][1][1] == uGameBoard[i][2][0] && uGameBoard[i][0][2] != 0)
        {
            uPlayerScore[uGameBoard[i][0][2]]++;
        }
        
    }
}
void checkUEndGame()
{
    for (int i = 1; i < 10; i++)
    {
        if (sectionIsFull(i) != 1) //!= 1-> empty
        {
            return;
        }
    }
    endGame = 1;
    endGameTask();
    printf("Player 1 has %d groups\n", uPlayerScore[1]);
    printf("Player 2 has %d groups\n", uPlayerScore[2]);
    if (uPlayerScore[1] > uPlayerScore[2])
    {
        printf("Player 1 wins!");
        exit(0);
    }
    else if (uPlayerScore[1] < uPlayerScore[2])
    {
        printf("Player 2 wins!");
        exit(0);
    }
    else
    {
        printf("Draw Game!");
        exit(0);
    }
}
void ultimateGameFlow(void) {
    int round = 0;
    int section;
    int uCurrentPlayer = 1;
    while (endGame != 1)
    {
        checkUEndGame();
        printUGameBoard(uGameBoard);
        if ((round == 0)&&(uCurrentPlayer==1))
        {
            seekTwoInput(&section,uCurrentPlayer);
        }
        else
        {
            if (sectionIsFull(section) == 1)
            {
                printf("The section is full. You may place wherever you want!\n");
                seekTwoInput(&section,uCurrentPlayer);
            }
            else
            {
                seekOneInput(&section, uCurrentPlayer);
            }
            
        }
        if (uCurrentPlayer == 1)
        {
            uCurrentPlayer = 2;
        }
        else if (uCurrentPlayer == 2)
        {
            uCurrentPlayer = 1;
            round++;
        }
    }
    printUGameBoard(uGameBoard);


}


//Function for Normal Game Mode
void initGameBoard(int gameBoard[3][3]) {

    // TODO: Complete this part
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            gameBoard[i][j] = 0;
        }
    }
}
void printGameBoard(int gameBoard[3][3]) {
    int number = 7;


    printf("=========\n");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (gameBoard[i][j] == 0)
            {
                printf("|%d|", number + j);

            }
            else if (gameBoard[i][j] == 1)
            {
                printf("|O|");

            }
            else if (gameBoard[i][j] == 2)
            {
                printf("|X|");

            }

        }
        number -= 3;
        printf("\n");
    }

    printf("=========\n");
}
void placeMarkByHumanPlayer(int gameBoard[3][3], int mark) {

    // TODO: Complete this part
    //gameBoard=mark;
    if (mark > 20)
    {
        switch (mark)
        {
        case 21:
            gameBoard[2][0] = CROSS;
            break;
        case 22:
            gameBoard[2][1] = CROSS;
            break;
        case 23:
            gameBoard[2][2] = CROSS;
            break;
        case 24:
            gameBoard[1][0] = CROSS;
            break;
        case 25:
            gameBoard[1][1] = CROSS;
            break;
        case 26:
            gameBoard[1][2] = CROSS;
            break;
        case 27:
            gameBoard[0][0] = CROSS;
            break;
        case 28:
            gameBoard[0][1] = CROSS;
            break;
        case 29:
            gameBoard[0][2] = CROSS;
            break;
        }
    }
    else
    {
        switch (mark)
        {
        case 11:
            gameBoard[2][0] = CIRCLE;
            break;
        case 12:
            gameBoard[2][1] = CIRCLE;
            break;
        case 13:
            gameBoard[2][2] = CIRCLE;
            break;
        case 14:
            gameBoard[1][0] = CIRCLE;
            break;
        case 15:
            gameBoard[1][1] = CIRCLE;
            break;
        case 16:
            gameBoard[1][2] = CIRCLE;
            break;
        case 17:
            gameBoard[0][0] = CIRCLE;
            break;
        case 18:
            gameBoard[0][1] = CIRCLE;
            break;
        case 19:
            gameBoard[0][2] = CIRCLE;
            break;
        }
    }


}
int hasWinner(int gameBoard[3][3]) {

    // TODO: Complete this part
    if (gameBoard[0][0] == gameBoard[0][1] && gameBoard[0][1] == gameBoard[0][2] && gameBoard[0][0] != 0)
    {
        return 1;
    }
    else if (gameBoard[1][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[1][2] && gameBoard[1][0] != 0)
    {
        return 1;
    }
    else if (gameBoard[2][0] == gameBoard[2][1] && gameBoard[2][1] == gameBoard[2][2] && gameBoard[2][0] != 0)
    {
        return 1;
    }
    else if (gameBoard[1][1] == gameBoard[2][1] && gameBoard[1][1] == gameBoard[0][1] && gameBoard[1][1] != 0)
    {
        return 1;
    }
    else if (gameBoard[0][2] == gameBoard[1][2] && gameBoard[2][2] == gameBoard[1][2] && gameBoard[0][2] != 0)
    {
        return 1;
    }
    else if (gameBoard[0][0] == gameBoard[1][0] && gameBoard[1][0] == gameBoard[2][0] && gameBoard[0][0] != 0)
    {
        return 1;
    }
    else if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2] && gameBoard[0][0] != 0)
    {
        return 1;
    }
    else if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0] && gameBoard[0][2] != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(int gameBoard[3][3]) {
    int i = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (gameBoard[i][j] == 0)
            {
                return 0;
            }

        }
    }

    return 1;
}
void placeMarkByComputerPlayer(int gameBoard[3][3], int record[][9],int round) {
    for (int i = 2; i >= 0; i--)
    {
        for (int j = 0; j < 3; j++)
        {
            if (gameBoard[i][j] == 0)
            {
                gameBoard[i][j] = 2;
                switch (i)
                {
                case 0:
                    switch (j)
                    {
                    case 0:
                        record[2][round] = 27;
                        break;
                    case 1:
                        record[2][round] = 28;
                        break;
                    case 2:
                        record[2][round] = 29;
                        break;
                    }
                    break;
                case 1:
                    switch (j)
                    {
                    case 0:
                        record[2][round] = 24;
                        break;
                    case 1:
                        record[2][round] = 25;
                        break;
                    case 2:
                        record[2][round] = 26;
                        break;
                    }
                    break;
                case 2:
                    switch (j)
                    {
                    case 0:
                        record[2][round] = 21;
                        break;
                    case 1:
                        record[2][round] = 22;
                        break;
                    case 2:
                        record[2][round] = 23;
                        break;
                    }
                    break;
                }
                return;
            }
        }
    }
}
void undo(int gameBoard[3][3],int record1[][9],int record2[][9], int alreadyUndo[3], int currentPlayer, int* round) {
    
    
        if (currentPlayer == 1)
        {
            
                    switch (record1[1][*round-1])
                    {
                    case 11:
                        gameBoard[2][0] = 0;
                        record1[1][*round - 1] = 0;
                        break;
                    case 12:
                        gameBoard[2][1] = 0;
                        record1[1][*round - 1] = 0;
                        break;
                    case 13:
                        gameBoard[2][2] = 0;
                        record1[1][*round - 1] = 0;
                        break;
                    case 14:
                        gameBoard[1][0] = 0;
                        record1[1][*round - 1] = 0;
                        break;
                    case 15:
                        gameBoard[1][1] = 0;
                        record1[1][*round - 1] = 0;
                        break;
                    case 16:
                        gameBoard[1][2] = 0;
                        record1[1][*round - 1] = 0;
                        break;
                    case 17:
                        gameBoard[0][0] = 0;
                        record1[1][*round - 1] = 0;
                        break;
                    case 18:
                        gameBoard[0][1] = 0;
                        record1[1][*round - 1] = 0;
                        break;
                    case 19:
                        gameBoard[0][2] = 0;
                        record1[1][*round - 1] = 0;
                        break;
                    }
                    switch (record2[2][*round-1])
                    {
                    case 21:
                        gameBoard[2][0] = 0;
                        record2[2][*round - 1] = 0;
                        break;
                    case 22:
                        gameBoard[2][1] = 0;
                        record2[2][*round - 1] = 0;
                        break;
                    case 23:
                        gameBoard[2][2] = 0;
                        record2[2][*round - 1] = 0;
                        break;
                    case 24:
                        gameBoard[1][0] = 0;
                        record2[2][*round - 1] = 0;
                        break;
                    case 25:
                        gameBoard[1][1] = 0;
                        record2[2][*round - 1] = 0;
                        break;
                    case 26:
                        gameBoard[1][2] = 0;
                        record2[2][*round - 1] = 0;
                        break;
                    case 27:
                        gameBoard[0][0] = 0;
                        record2[2][*round - 1] = 0;
                        break;
                    case 28:
                        gameBoard[0][1] = 0;
                        record2[2][*round - 1] = 0;
                        break;
                    case 29:
                        gameBoard[0][2] = 0;
                        record2[2][*round - 1] = 0;
                        break;
                    }
            
        }
        else if (currentPlayer == 2)
        {

            switch (record1[2][*round - 1])
            {
            case 21:
                gameBoard[2][0] = 0;
                record1[2][*round - 1] = 0;
                break;
            case 22:
                gameBoard[2][1] = 0; 
                record1[2][*round - 1] = 0;
                break;
            case 23:
                gameBoard[2][2] = 0;
                record1[2][*round - 1] = 0;
                break;
            case 24:
                gameBoard[1][0] = 0;
                record1[2][*round - 1] = 0;
                break;
            case 25:
                gameBoard[1][1] = 0;
                record1[2][*round - 1] = 0;
                break;
            case 26:
                gameBoard[1][2] = 0;
                record1[2][*round - 1] = 0;
                break;
            case 27:
                gameBoard[0][0] = 0;
                record1[2][*round - 1] = 0;
                break;
            case 28:
                gameBoard[0][1] = 0;
                record1[2][*round - 1] = 0;
                break;
            case 29:
                gameBoard[0][2] = 0;
                record1[2][*round - 1] = 0;
                break;
            }
            switch (record1[1][*round])
            {
            case 11:
                gameBoard[2][0] = 0;
                record1[1][*round] = 0;
                break;
            case 12:
                gameBoard[2][1] = 0;
                record1[1][*round] = 0;
                break;
            case 13:
                gameBoard[2][2] = 0;
                record1[1][*round] = 0;
                break;
            case 14:
                gameBoard[1][0] = 0;
                record1[1][*round] = 0;
                break;
            case 15:
                gameBoard[1][1] = 0;
                record1[1][*round] = 0;
                break;
            case 16:
                gameBoard[1][2] = 0;
                record1[1][*round] = 0;
                break;
            case 17:
                gameBoard[0][0] = 0;
                record1[1][*round] = 0;
                break;
            case 18:
                gameBoard[0][1] = 0;
                record1[1][*round] = 0;
                break;
            case 19:
                gameBoard[0][2] = 0;
                record1[1][*round] = 0;
                break;
            }
            
            
        }
        alreadyUndo[currentPlayer] = 1;
        printGameBoard(gameBoard);
        *round-=1;
    

    
}
void askUndo(int gameBoard[3][3], int record1[][9], int record2[][9], int alreadyUndo[3], int currentPlayer, int* round)
{
    int doUndo;
    printf("Player %d, Do you want to undo your pervious move? [Yes: 1/ No: 0]\n", currentPlayer);
    fflush(stdin);
    scanf("%d", &doUndo);
    if (doUndo == 1)
    {
        if (currentPlayer == 1) {
            undo(gameBoard, record1, record2, alreadyUndo, currentPlayer, round);
        }
        else
        {
            undo(gameBoard, record2, record1, alreadyUndo, currentPlayer, round);
        }
    }
    else if (doUndo == 0)
    {

    }
    else {
        printf("Please input 1 for Yes OR 0 for No!!!\n");
        askUndo(gameBoard,record1,record2,alreadyUndo,currentPlayer,round);
    }
}
//Game Flow
void normalGameFlow(void) {
    int gameBoard[3][3];
    int currentPlayer;
    int gameEnds;
    int numOfHumanPlayers;
    int round = 0;
    
    int record[3][9] = {};
    int alreadyUndo[3] = {};
    initGameBoard(gameBoard);
    currentPlayer = 1;
    gameEnds = 0;
    printf("How many human players [1-2]?\n");
    scanf("%d", &numOfHumanPlayers);
    printGameBoard(gameBoard);
    int pos;
    if (numOfHumanPlayers == 2)
    {
        while (gameEnds != 1)
        {
            if (record[currentPlayer][0] != 0)
            {
                if (alreadyUndo[currentPlayer] != 1)
                {
                    askUndo(gameBoard, record, record, alreadyUndo, currentPlayer, &round);
                }
            }


           printf("Player %d, please place your mark [1-9]:\n", currentPlayer);
            scanf("%d", &pos);
            placeMarkByHumanPlayer(gameBoard, (currentPlayer * 10 + pos));
            record[currentPlayer][round] = currentPlayer * 10 + pos;
            printGameBoard(gameBoard);
            if (hasWinner(gameBoard) == 1)
            {
                printf("Player %d wins! Congratulations!", currentPlayer);
                exit(0);
            }
            if (isFull(gameBoard) == 1)
            {
                printf("Draw game!");
                exit(0);
            }
            if (currentPlayer == 1)
            {
                currentPlayer = 2;

            }
            else
            {
                currentPlayer = 1;
                round++;
            }

        }

    }
    else if (numOfHumanPlayers == 1)
    {
        while (gameEnds != 1)
        {
            if (record[1][0]!=0)
            {
                if (alreadyUndo[1] != 1)
                {
                    askUndo(gameBoard,record,record,alreadyUndo,currentPlayer,&round);
                }
            }

            printf("Player %d, please place your mark [1-9]:\n", currentPlayer);
            scanf("%d", &pos);
            placeMarkByHumanPlayer(gameBoard, (currentPlayer * 10 + pos));
            record[1][round] = currentPlayer * 10 + pos;
            printGameBoard(gameBoard);
            if (hasWinner(gameBoard) == 1)
            {
                printf("Player 1 wins! Congratulations!");
                exit(1);
            }
            if (isFull(gameBoard) == 1)
            {
                printf("Draw game!");
                exit(1);
            }
            printf("Computer places the mark:\n");
            placeMarkByComputerPlayer(gameBoard, record,round);

            printGameBoard(gameBoard);
            if (hasWinner(gameBoard) == 1)
            {
                printf("Computer Wins!");
                break;
            }
            if (isFull(gameBoard) == 1)
            {
                printf("Draw game!");
                break;
            }
            round++;
        }

    }
}



void instruction(void) {

}
void gameMenu(void) {
    system("clear");
    int choice;
    printf("Welcome to the game!!!\n");
    printf("Game Memu\n");
    printf("----------------------\n");
    printf("[1] Normal Game\n");
    printf("[2] Ultimate Game\n");
    printf("[3] Instruction\n");
    printf("[4] Exit\n");
    printf("----------------------\n");
    printf("Please enter (1-4) to continue: \n");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
        normalGameFlow();
        break;
    case 2:
        instructionForUltimate();
        ultimateGameFlow();
        break;
    case 3:
        instruction();
        break;
    case 4:
        exit(1);
        break;
    default:
        printf("Please input an integer 1-4!!!\n");
        system("pause");
        gameMenu();
        break;
    }
}

int main(void)
{
    //printUGameBoard(uGameBoard);
    gameMenu();
    return 0;
}