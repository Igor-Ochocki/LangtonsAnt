#ifndef _ANT_H_
#define _ANT_H_
#define BLACK_COLOR 1
#define WHITE_COLOR 0
#define ANT 2

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

enum Directions {
    UP,
    RIGHT,
    DOWN,
    LEFT
};

typedef struct {
    enum Directions direction;
    int col;
    int row;
    int color;
} ant_t;

void moveAnt( int ***board_structure_pointer, int rows_count, int columns_count, ant_t *ant );

#endif
