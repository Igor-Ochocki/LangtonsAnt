#include <stdio.h>
#include <stdlib.h>
#include "load_board.h"
#include "print_board.h"
#include "ant.h"
#include "board_generator.h"
#include "helpers.h"
#include <time.h>
#include <string.h>

int main(int argc, char **argv)
{
    srand(time(NULL));
    int row_count = 5, column_count = 5, iterations = 10, percent_fill = 0, i;
    enum Directions direction = -1;
    char *saveFileName = NULL;
    char *readFileName = NULL;
    readArguments(argc, argv, &row_count, &column_count, &iterations, &percent_fill, &saveFileName, &readFileName, &direction);
    if (row_count < 1 || column_count < 1)
    {
        fprintf(stderr, "Podano niepoprawne wymiary planszy mrówki\n");
        return 1;
    }
    int **board = readFileName == NULL ? generateBoard(row_count, column_count, percent_fill) : loadBoardFromFile(readFileName, &row_count, &column_count);
    if(direction == -1)
        direction = getRandomValue(4);
    ant_t *ant = createAnt(getRandomValue(row_count), getRandomValue(column_count), direction, board);
    board[ant->row][ant->col] = ANT;
    char *tempSaveFileName = saveFileName != NULL ? malloc(sizeof *tempSaveFileName * (strlen(saveFileName) + 9 + strlen(OUTPUTFOLDER_NAME))) : NULL;
    for (i = 0; i <= iterations; i++)
    {
        if (saveFileName != NULL)
            sprintf(tempSaveFileName, "%s/%s_%d", OUTPUTFOLDER_NAME, saveFileName, i);
        saveFileName != NULL ? printBoard(board, row_count, column_count, ant, tempSaveFileName) : printBoard(board, row_count, column_count, ant, saveFileName);
        moveAnt(&board, row_count, column_count, ant);
    }
    free(saveFileName);
    free(tempSaveFileName);
    free(readFileName);
    free(board);
    free(ant);
    return 0;
}
