#ifndef _HELPERS_H_
#define _HELPERS_H_
#include "ant.h"

/*
 * function_name:   readArguments
 * input parameters:
 *                  argc            - number of arguments provided to program
 *                  argv            - array of arguments provided to program
 *                  row_count       - number of rows in Langton's ant board
 *                  column_count    - number of columns in Langton's ant board
 *                  percent_fill    - number representing how much of a board should be filled with black cells
 *                  saveFileName    - sequence of characters containing prefix of files 
 *                                    to save next iterations of Langton's ant in
 *                  readFileName    - sequence of characters containing either file name
 *                                    or path to file from which program reads Langton's ant predefined
 *                                    board structure
 *                  direction       - either value of enum Directions UP,RIGHT,DOWN or LEFT representing ant's direction
 *                                    or value in range 0,3 representing correspondingly 0 - UP, 1 - RIGHT, 2 - DOWN, 3 - LEFT
 * return value:    void
 * description:     This function reads argument from program startup from command line using getopt. Possible arguments are 
 *                  -r <file_name or path> 
 *                  -g <number (1-100)> 
 *                  -m <number > 0> 
 *                  -n <number > 0> 
 *                  -d <number (0-3)> 
 *                  -i <number >= 0> 
 *                  -f <file_name or path>
 *                  
 */
void readArguments(int argc, char **argv, int *row_count, int *column_count, int *iterations, int *percent_fill, char **saveFileName, char **readFileName, enum Directions *direction);

/*
 * function_name:   getRandomValue
 * input parameters:
 *                  maxValueExclusive   - number representing upper boundary of values range
 * return value:    int                 - random value from range 0 to maxValueExclusive-1
 * description:     This function returns random value between 0 and maxValueExclusive-1
 */
int getRandomValue(int maxValueExclusive);

#endif