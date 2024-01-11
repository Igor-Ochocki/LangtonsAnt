#ifndef _PRINT_BOARD_H_
#define _PRINT_BOARD_H_
#include "ant.h"

/*
 * function_name:   printBoard
 * input parameters:
 *                  board       - structure of Langton's ant board
 *                  row         - id of a row that we want to create ant on 
 *                  col         - id of a column that we want to create ant on
 *                  ant         - pointer to instance of an ant
 *                  filename    - sequence of characters containing prefix of files 
 *                                to save next iterations of Langton's ant in or NULL
 * description:     This function prints board structure to either stdin (if filename is NULL) or to filename
 */
void printBoard(int **board, int row, int col, ant_t *ant, char *filename);

#endif
