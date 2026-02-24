// #include<stdlib.h>
// #include<stdio.h>

// int board[3] [3];
// int gameMenu() {
//     int choice,status;

//     system("clear");
//     printf("\n1. Two player game");
//     printf("\n2. Exit...");
//     printf("\n3. Enter your choice");

//     status = scanf("%d",&choice);
//     if(status != 1) {
//         while(getchar() != "\n");
//         return 0;
//     }
//     return choice;
// }

// void resetGame() {
//     int i,j;
//     for(i=0; i<=2; i++) {
//         for(j=0; j<=2; j++) {
//             board[i][j] = 2;
//         }
//     }
// }

// void displayBoard() {
//     int i, j, k=1;
//     for(i=0; i<=2; i++) {
//         for(j=0; j<=2; j++) {
//             if(board[i][j] == 2) 
//                 printf("%3d", k);
//             else if(board[i][j] == 3)
//                 printf("%3c", 'X');
//             else if(board[i][j] == 5)
//                 printf("%3c", '0');

//                 k++;
//         }
         
//         printf("\n\n");
//     }
// }

// int isMoveValid(int move) {
//     switch(move) {
//         case 1:
//             if(board[0][0] == 2)
//                return 1;
//             break;
//         case 2:
//             if(board[0][1] == 2)
//                return 1;
//             break;
//         case 3:
//             if(board[0][2] == 2)
//                return 1;
//             break;
//         case 4:
//             if(board[1][0] == 2)
//                return 1;
//             break;
//         case 5:
//             if(board[1][1] == 2)
//                return 1;
//             break;
//         case 6:
//             if(board[1][2] == 2) 
//                return 1;
//             break;
//         case 7:
//             if(board[2][0] == 2)
//                return 1;
//             break;
//         case 8:
//             if(board[2][1] == 2)
//                return 1;
//             break;
//         case 9:
//             if(board[2][2] == 2)
//                return 1;
//             break;
//     }
//     return 0;
// }

// int inputMove(int player) {
//     int move,status;

//     do {
//         printf("Player %d (Type square number to mark move): ", player);
//         scanf("%d", &move);

//         if(status != 1) {
//             printf("Invalid input! Enter number only.\n");
//             while(getchar() != "\n");  // clear buffer
//             move = 0;
//             continue;
//         }
//     } while( !isMoveValid(move));
//         return move;
// }

// void makeMove(int player, int move) {
//     int mark = (player == 1) ? 3 : 5;
//     switch(move) {
//         case 1: board[0][0]=mark; break;
//         case 2: board[0][1]=mark; break;   
//         case 3: board[0][2]=mark; break;   
//         case 4: board[1][0]=mark; break;
//         case 5: board[1][1]=mark; break;
//         case 6: board[1][2]=mark; break;
//         case 7: board[2][0]=mark; break;
//         case 8: board[2][1]=mark; break;
//         case 9: board[2][2]=mark; break;
//     }
// }

// int checkWin(int player) {
//     int i,j;
//     if(player==1) {
//         for(i=0;i<=2;i++)
//             if(board[i][0]*board[i][1]*board[i][2]==27)
//                 return 1;
//         for(j=0;j<=2;j++)
//             if(board[0][j]*board[1][j]*board[2][j]==27)
//                 return 1;
//         if(board[0][2]*board[1][1]*board[2][0]==27)
//             return 1;
//         if(board[0][0]*board[1][1]*board[2][2]==27)
//             return 1;
//     } else {
//         for(i=0;i<=2;i++)
//             if(board[i][0]*board[i][1]*board[i][2]==125)
//                 return 1;
//         for(j=0;j<=2;j++)
//             if(board[0][j]*board[1][j]*board[2][j]==125)
//                 return 1;
//         if(board[0][2]*board[1][1]*board[2][0]==125)
//             return 1;
//         if(board[0][0]*board[1][1]*board[2][2]==125)
//             return 1;
//     }
//     return 0;
// }


// int main() {
//     int turn,player,move;
//     while(1) {
//         switch(gameMenu()) {
//             case 1:
//                 resetGame();
//                 displayBoard();
//                 for(turn=1,player=1;turn<=9;turn++) {
//                     move=inputMove(player);
//                     makeMove(player,move);
//                     system("clear"); //system("cls"); (for windows)
//                     displayBoard();
//                     if(checkWin(player)) {
//                         printf("\nPlayer %d won the game",player);
//                         break;
//                     }

//                     if(player==1)
//                         player=2;
//                     else
//                         player=1;

//                 }

//                 if(turn==10)
//                     printf("Game is draw");
//                 break;
//             case 2:
//                 exit(0);
//             default:
//                 printf("\nInvalid choice, retry");
//         }
//     }

//     printf("\n");
//     return 0;    
// }








#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// cls clears screen immediately, win message may not be visible, so using macro 
#ifdef _WIN32                
#define CLEAR_SCREEN system("cls")
#endif
int board[3][3];

int getNumber() {
    char line[100];
    int num;
    char extra;

    while(1) {
        if(!fgets(line,sizeof(line),stdin))   // using fgtes in place of scanf to avoid infinite loop and wrong input
            continue;
        if(sscanf(line,"%d %c",&num,&extra)==1)  // check input number only 
            return num;
        printf("Invalid input! Enter numbers only: ");
    }
}

void waitInput() {
    char line[100];
    int count = 0;

    while(count < 3) {
        printf("Press Enter to continue...");
        if(!fgets(line,sizeof(line),stdin))
         continue;

         if(line[0] == '\n') // Only enter
           return;

           printf("only Enter allowed\n");
           count++;
    }
     printf("Too many wrong inputs, Game ended.\n");
     exit(0);
}

int gameMenu() {
    CLEAR_SCREEN;
    printf("\n1. Two player game");
    printf("\n2. Exit...");
    printf("\nEnter your choice: ");
    return getNumber();
}

void resetGame() {
    int i,j;
    for(i=0; i<=2; i++)
        for(j=0; j<=2; j++)
            board[i][j]=2;
}

void displayBoard() {
    int i,j,k=1;

    for(i=0; i<=2; i++) {
        for(j=0;j <=2 ;j++) {
            if(board[i][j]==2)
                printf("%3d",k);
            else if(board[i][j]==3)
                printf("%3c",'X');  // spacing for each symbol
            else
                printf("%3c",'O');  
            k++;
        }
        printf("\n\n");
    }
}

int isMoveValid(int move) {
    if(move<1 || move>9)
        return 0;

    switch(move) {
        case 1:
            if(board[0][0]==2)
                return 1;
            break;
        case 2:
            if(board[0][1]==2)
                return 1;
            break;
        case 3:
            if(board[0][2]==2)
                return 1;
            break;
        case 4:
            if(board[1][0]==2)
                return 1;
            break;
        case 5:
            if(board[1][1]==2)
                return 1;
            break;
        case 6:
            if(board[1][2]==2)
                return 1;
            break;
        case 7:
            if(board[2][0]==2)
                return 1;
            break;
        case 8:
            if(board[2][1]==2)
                return 1;
            break;
        case 9:
            if(board[2][2]==2)
                return 1;
            break;
    }

    return 0;
}

int inputMove(int player) {
    int move;

    do {
        printf("Player %d (Enter 1-9): ",player);
        move = getNumber();

        if(!isMoveValid(move))
            printf("Invalid move. Try again.\n");

    } while(!isMoveValid(move));

    return move;
}


void makeMove(int player,int move) {
    int mark = (player==1) ? 3 : 5;

    switch(move) {
        case 1: board[0][0]=mark; break;
        case 2: board[0][1]=mark; break;
        case 3: board[0][2]=mark; break;
        case 4: board[1][0]=mark; break;
        case 5: board[1][1]=mark; break;
        case 6: board[1][2]=mark; break;
        case 7: board[2][0]=mark; break;
        case 8: board[2][1]=mark; break;
        case 9: board[2][2]=mark; break;
    }
}


int checkWin(int player) {
    int i,j;

    if(player==1) {
        for(i=0; i<=2; i++)       // check rows
            if(board[i][0]*board[i][1]*board[i][2]==27)
                return 1;

        for(j=0; j<=2; j++)              // check columns
            if(board[0][j]*board[1][j]*board[2][j]==27)
                return 1;

        if(board[0][2]*board[1][1]*board[2][0]==27)  // check corner to corner line
            return 1;

        if(board[0][0]*board[1][1]*board[2][2]==27)
            return 1;
    } else {
        for(i=0; i<=2; i++)    // check rows
            if(board[i][0]*board[i][1]*board[i][2]==125)
                return 1;

        for(j=0; j<=2; j++)   // check columns
            if(board[0][j]*board[1][j]*board[2][j]==125)
                return 1;

        if(board[0][2]*board[1][1]*board[2][0]==125)   // check corner to corner line
            return 1;

        if(board[0][0]*board[1][1]*board[2][2]==125)
            return 1;
    }
    return 0;
}


int main() {
    int turn,player,move;
    while(1) {
        switch(gameMenu()) {
            case 1:
                resetGame();
                displayBoard();

                for(turn=1,player=1; turn<=9; turn++) {
                    move = inputMove(player);
                    makeMove(player,move);
                    CLEAR_SCREEN;
                    displayBoard();

                    if(checkWin(player)) {
                        printf("\nPlayer %d won the game\n",player);
                        waitInput();
                        break;
                    }

                    player=(player==1)? 2 : 1;
                }

                if(turn==10) {
                    printf("Game is draw\n");
                    waitInput();
                }
                break;
            case 2:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}