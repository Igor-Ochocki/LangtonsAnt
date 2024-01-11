#ifndef _LOAD_BOARD_H_
#define _LOAD_BOARD_H_
#include "ant.h"
#define BUFF_SIZE 2048

/*
 * function_name:   loadBoardFromFile
 * input parameters:
 *                  fileName    - sequence of characters containing either file name
 *                                or path to file from which program reads Langton's ant predefined
 *                                board structure
 * return value:    int **      - Langton's ant board created from provided filename
 * description:     This function creates Langton's ant board structure from fileName provided as parameter
 *                  if function can't read from file, it exists the code with code 1
 */
int **loadBoardFromFile(char *fileName, int *rows_count, int *columns_count);

#endif