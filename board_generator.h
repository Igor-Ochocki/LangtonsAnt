#ifndef _BOARD_GENERATOR_H_
#define _BOARD_GENERATOR_H_
#include "ant.h"

/*
 * function_name:   generateBoard
 * input parameters:
 *                  row             - number of rows in Langton's ant board
 *                  col             - number of columns in Langton's ant board
 *                  fill_percentage - value of how much of total board size (row * col) should be filled 
 *                                    with black cells
 * return value:    int **          - structure of Langton's ant board
 * description:     This function generates board and fills it out randomly with black cells in such a way
 *                  that total black cells count / total board cells is equal to fill_percentage
 */
int **generateBoard(int row, int col, int fill_percentage);

#endif
