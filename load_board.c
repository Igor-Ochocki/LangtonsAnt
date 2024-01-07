#include "load_board.h"
#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int **loadBoardFromFile(char *fileName, int *rows_count, int *columns_count)
{
    setlocale(LC_ALL, "C.UTF-8");
    if (fileName == NULL)
    {
        printf("Nie podano nazwy pliku do wczytania.\n");
        exit(1);
    }
    FILE *in = fopen(fileName, "r");
    if (in == NULL)
    {
        printf("%s: nie mogę czytać %s", __FILE__, fileName);
        exit(1);
    }
    wchar_t symbol;
    while ((symbol = fgetwc(in)) != WEOF)
    {
        if (symbol == '\n')
        {
            (*rows_count)++;
            continue;
        }
        (*columns_count)++;
    }
    fclose(in);
    (*rows_count)++;
    (*columns_count) = (*columns_count) / (*rows_count);

    (*columns_count) /= 2;
    (*rows_count) /= 2;
    int **board_structure = malloc(sizeof *board_structure * (*rows_count));
    for (int i = 0; i < *rows_count; i++)
    {
        board_structure[i] = malloc(sizeof *board_structure[i] * (*columns_count));
    }
    in = fopen(fileName, "r");
    wchar_t black_wall = L'█';
    wchar_t white_wall = L' ';
    int row = 0, col = 0;
    while ((symbol = fgetwc(in)) != WEOF)
    {
        if (symbol == '\n')
        {
            row++;
            col = 0;
            continue;
        }
        if (row % 2 == 1)
        {
            if(symbol == black_wall)
                board_structure[row/2][col/2] = BLACK_COLOR;
            else if(symbol == white_wall)
                board_structure[row/2][col/2] = WHITE_COLOR;
        }
        col++;
    }
    fclose(in);
    return board_structure;
}