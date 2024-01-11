#ifndef _LOAD_BOARD_H_
#define _LOAD_BOARD_H_
#include "ant.h"
#define BUFF_SIZE 2048

int **loadBoardFromFile(char *fileName, int *rows_count, int *columns_count);

#endif