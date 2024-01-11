#include "ant.h"
#include <stdlib.h>

void moveAnt(int ***board_structure_pointer, int rows_count, int columns_count, ant_t *ant)
{
    int **board_structure = *board_structure_pointer;
    // Change ant's direction
    switch (ant->color)
    {
    case WHITE_COLOR:
        switch (ant->direction)
        {
        case UP:
            ant->direction = RIGHT;
            break;
        case RIGHT:
            ant->direction = DOWN;
            break;
        case DOWN:
            ant->direction = LEFT;
            break;
        case LEFT:
            ant->direction = UP;
            break;
        }
        break;
    case BLACK_COLOR:
        switch (ant->direction)
        {
        case UP:
            ant->direction = LEFT;
            break;
        case RIGHT:
            ant->direction = UP;
            break;
        case DOWN:
            ant->direction = RIGHT;
            break;
        case LEFT:
            ant->direction = DOWN;
            break;
        }
        break;
    }

    // Change color in board
    switch (ant->color)
    {
    case WHITE_COLOR:
        board_structure[ant->row][ant->col] = BLACK_COLOR;
        break;
    case BLACK_COLOR:
        board_structure[ant->row][ant->col] = WHITE_COLOR;
        break;
    }

    // Move and and set it's color
    switch (ant->direction)
    {
    case UP:
        if (ant->row == 0)
            ant->row = rows_count - 1;
        else
            ant->row = ant->row - 1;
        break;
    case RIGHT:
        if (ant->col == columns_count - 1)
            ant->col = 0;
        else
            ant->col = ant->col + 1;
        break;
    case LEFT:
        if (ant->col == 0)
            ant->col = columns_count - 1;
        else
            ant->col = ant->col - 1;
        break;
    case DOWN:
        if (ant->row == rows_count - 1)
            ant->row = 0;
        else
            ant->row = ant->row + 1;
        break;
    }
    ant->color = board_structure[ant->row][ant->col];
    board_structure[ant->row][ant->col] = ANT;
}

ant_t *createAnt(int row, int col, enum Directions direction, int **board)
{
    ant_t *ant = malloc(sizeof ant);
    ant->row = row;
    ant->col = col;
    ant->color = board[ant->row][ant->col];
    ant->direction = direction;
    return ant;
}