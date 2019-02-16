#include <stdio.h>,
#include <stdlib.h>

const int M = 3;
const int N = 3;


void printGame(char gameBoard[M][N])
{
    int i, j;
    for (i = 0; i < M; i++) {
      for (j = 0; j < N; j++) {
        printf(" %c ", gameBoard[i][j]);
      }
      printf("\n");
    }
}


int winCheck(char gameBoard[M][N], char currentPlayer) {

    int k;

    const int winArray[8][3][2] = {
        {{0, 0}, {0, 1}, {0, 2}},

        {{1, 0}, {1, 1}, {1, 2}},

        {{2, 0}, {2, 1}, {2, 2}},

        {{0, 0}, {1, 0}, {2, 0}},

        {{0, 1}, {1, 1}, {2, 1}},

        {{0, 2}, {1, 2}, {2, 2}},

        {{0, 0}, {1, 1}, {2, 2}},

        {{0, 2}, {1, 1}, {2, 0}}
    };



    for(k = 0; k <= 8; k++) {

        if (gameBoard[winArray[k][0][0]][winArray[k][0][1]] == currentPlayer && gameBoard[winArray[k][1][0]][winArray[k][1][1]] == currentPlayer && gameBoard[winArray[k][2][0]][winArray[k][2][1]] == currentPlayer) {
            return 1;
        }
    }
    return 0;
}

int main()
{
    char gameBoard[][3] = {{'_','_' , '_'}, {'_','_' , '_'}, {'_','_' , '_'}};
    printGame(gameBoard);

    int posx;
    int posy;
    char currentPlayer = 'X';
    int moves = 0;

    printf("Please enter your move Player %c: ", currentPlayer);


    while (moves < 9) {
        scanf("%d%d", &posx, &posy);
        if (posx > 2 || posy > 2 || gameBoard[posx][posy] == 'X' || gameBoard[posx][posy] == 'O') {
            printf("Invalid move, try again: ");
        } else {
            gameBoard[posx][posy] = currentPlayer;
            printGame(gameBoard);
            if (winCheck(gameBoard, currentPlayer) == 1) {
                printf("\nPlayer %c Wins!!!\n\n", currentPlayer);
                break;
            };
            if (currentPlayer == 'X') {
                currentPlayer = 'O';
            } else if (currentPlayer == 'O') {
                currentPlayer = 'X';
            }
            moves++;

            if (moves < 8) {
                printf("Please enter your move Player %c: ", currentPlayer);
            }
        }
    }

    if (moves == 9) {
        printf("Game over, you both suck");
    }

    return 0;
}
