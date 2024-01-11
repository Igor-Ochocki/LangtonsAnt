#ifndef _ANT_H_
#define _ANT_H_
#define BLACK_COLOR 1
#define WHITE_COLOR 0
#define ANT 2
#define OUTPUTFOLDER_NAME "output"

#define LINE_VERTICAL "┃"
#define LINE_HORIZONTAL "━"
#define LINE_DOWN_RIGHT "┏"
#define LINE_DOWN_LEFT "┓"
#define LINE_UP_RIGHT "┗"
#define LINE_UP_LEFT "┛"
#define SQUARE_WHITE " "
#define SQUARE_BLACK "█"
#define ARROW_NORTH_WHITE "△"
#define ARROW_NORTH_BLACK "▲"
#define ARROW_EAST_WHITE "▷"
#define ARROW_EAST_BLACK "▶"
#define ARROW_SOUTH_WHITE "▽"
#define ARROW_SOUTH_BLACK "▼"
#define ARROW_WEST_WHITE "◁"
#define ARROW_WEST_BLACK "◀"
#define LINE_UP_RIGHT_DOWN "┣"
#define LINE_UP_LEFT_RIGHT "┻"
#define LINE_RIGHT_DOWN_LEFT "┳"
#define LINE_UP_DOWN_LEFT "┫"
#define LINE_UP_RIGHT_DOWN_LEFT "╋"

enum Directions
{
    UP,
    RIGHT,
    DOWN,
    LEFT
};

typedef struct
{
    enum Directions direction;
    int col;
    int row;
    int color;
} ant_t;

/*
 * function_name:   moveAnt
 * input parameters:
 *                  board_structure_pointer - address to a 2D array of integers representing board
 *                  rows_count              - number of rows in Langton's ant board
 *                  columns_count           - number of columns in Langton's ant board
 *                  ant                     - pointer to instance of an ant
 * return value:    void
 * description:     This function makes a move of Langton's ant defined with certain behaviors based off on current ant's field color
 *                  and modifies globally structure of the board and and correspondingly to what single move action does
 *                  if ant is on white field, it rotates 90 degrees clockwise, changes field color to black and then moves forward
 *                  if ant is on black field, it roates 90 degrees counter-clockwise, changes field color to white and then moves forward
 */
void moveAnt(int ***board_structure_pointer, int rows_count, int columns_count, ant_t *ant);

/*
 * function_name:   createAnt
 * input parameters:
 *                  row         - id of a row that we want to create ant on
 *                  col         - id of a column that we want to create ant on
 *                  direction   - either value of enum Directions UP,RIGHT,DOWN or LEFT representing ant's direction
 *                                or value in range 0,3 representing correspondingly 0 - UP, 1 - RIGHT, 2 - DOWN, 3 - LEFT
 *                  board       - structure of Langton's ant board
 * return value:    ant_t*      - pointer to an instance of an ant
 * description:     This function allocates dynamic memory for instance of an ant and assigns all values that the ant structure has such as
 *                  color, row, column and direction and then returns pointer to an instance of an ant
 */
ant_t *createAnt(int row, int col, enum Directions direction, int **board);

#endif
