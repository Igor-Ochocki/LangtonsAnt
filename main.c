#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "load_board.h"
#include "print_board.h"
#include "ant.h"

void readArguments(int argc, char **argv, int *row_count, int *column_count, int *iterations, int *percent_fill, char **saveFileName, char **readFileName, enum Directions *direction)
{
    int opt;
    while ((opt = getopt(argc, argv, "m:n:i:f:d:g:r:")) != -1)
    {
        switch (opt)
        {
        case 'f':
            *saveFileName = malloc(sizeof **saveFileName * strlen(optarg));
            strcpy(*saveFileName, optarg);
            break;
        case 'm':
            if (atoi(optarg) == 0)
            {
                printf("Niepoprwana wartość argumentu %c\n", opt);
                exit(1);
            }
            *row_count = atoi(optarg);
            break;
        case 'n':
            if (atoi(optarg) == 0)
            {
                printf("Niepoprwana wartość argumentu %c\n", opt);
                exit(1);
            }
            *column_count = atoi(optarg);
            break;
        case 'i':
            if (atoi(optarg) == 0)
            {
                printf("Niepoprwana wartość argumentu %c\n", opt);
                exit(1);
            }
            *iterations = atoi(optarg);
            break;
        case 'd':
            if (atoi(optarg) == 0 && optarg != "0")
            {
                printf("Niepoprwana wartość argumentu %c\n", opt);
                exit(1);
            }
            if (atoi(optarg) > 3 || atoi(optarg) < 0)
            {
                printf("Niepoprawny kierunek mrówki %c. Podaj wartość z zakresu 0-3\n", opt);
            }
            *direction = atoi(optarg);
            break;
        case 'g':
            if (atoi(optarg) == 0)
            {
                printf("Niepoprwana wartość argumentu %c\n", opt);
                exit(1);
            }
            *iterations = atoi(optarg);
            break;
        case 'r':
            *readFileName = malloc(sizeof **readFileName * strlen(optarg));
            strcpy(*readFileName, optarg);
            break;
        case ':':
            printf("option needs a value\n");
            break;
        case '?':
            printf("Podano niepoprawną opcję wywołania\n");
            break;
        }
    }
}

int main(int argc, char **argv)
{
    int row_count = 0, column_count = 0, iterations, percent_fill;
    enum Directions direction;
    char *saveFileName = NULL;
    char *readFileName = NULL;
    readArguments(argc, argv, &row_count, &column_count, &iterations, &percent_fill, &saveFileName, &readFileName, &direction);
    int **board = loadBoardFromFile(readFileName, &row_count, &column_count);
    ant_t *ant = malloc(sizeof ant);
    ant->row = 1;
    ant->col = 1;
    ant->color = BLACK_COLOR;
    ant->direction = UP;
    board[ant->row][ant->col] = ANT;
    while (iterations--)
    {
        printBoard(board, row_count, column_count, ant);
        moveAnt(&board, row_count, column_count, ant);
    }
    printBoard(board, row_count, column_count, ant);
    return 0;
}
