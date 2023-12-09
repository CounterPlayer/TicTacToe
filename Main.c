#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void drawBoard(const char* board)
{
    printf("\n");
    printf(" %c | %c | %c\n", board[0], board[1], board[2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[3], board[4], board[5]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[6], board[7], board[8]);
    printf("\n");
}

void playerMove(char* board, const char player)
{
    int number;

    do
    {
        printf("Enter a number (1-9): ");
        scanf_s("%1d", &number);
        number--;

        if (board[number] == ' ')
        {
            board[number] = player;
            break;
        }
    } while (!number > 0 || !number < 8);
}

void computerMove(char* board, const char computer)
{
    srand(time(NULL));

    int number;

    while (1)
    {
        number = rand() % 9;
        if (board[number] == ' ')
        {
            board[number] = computer;
            break;
        }
    }
}

int checkWinner(char* board, const char player, const char computer)
{
    int i;
    int start[] = { 0, 3, 6, 0, 1, 2, 0, 2 };
    int step[] = { 1, 1, 1, 3, 3, 3, 4, 2 };
    int size = sizeof(start) / sizeof(int);

    for (i = 0; i < size; i++)
    {
        if (board[start[i]] != ' ' && board[start[i]] == board[start[i] + step[i]] && board[start[i] + step[i]] == board[start[i] + step[i] * 2])
        {
            printf("%s won!\n", board[start[i]] == player ? "You" : "Computer");

            return 1;
        }
    }

    return 0;
}

int checkTie(char* board)
{
    int i;

    for (i = 0; i < 9; i++)
    {
        if (board[i] == ' ')
        {
            return 0;
        }
    }

    printf("Tie!\n");

    return 1;
}

int main()
{
    char board[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
    const char player = 'X';
    const char computer = 'O';

    printf("Tic-tac-toe\n");

    drawBoard(board);

    while (1)
    {
        playerMove(board, player);
        drawBoard(board);

        if (checkWinner(board, player, computer) || checkTie(board))
        {
            break;
        }

        computerMove(board, computer);
        drawBoard(board);

        if (checkWinner(board, player, computer) || checkTie(board))
        {
            break;
        }
    }
}