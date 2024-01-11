#include "print_board.h"
#include <stdio.h>

void printBoard(int **board, int row, int col, ant_t *ant, char *filename)
{
    FILE *in;
    if (filename != NULL)
    {
        in = fopen(filename, "w");
        if (in == NULL)
        {
            printf("Nie moge otworzyc pliku %s\n", filename);
            in = stdout;
        }
    }
    else
        in = stdout;

    int c = 0;
    int r = 0;
    for (c = 0; c < (2 * col) + 1; c++)
    {
        if (c == 0)
            fprintf(in, "%s", LINE_DOWN_RIGHT);
        else if (c == (2 * col))
            fprintf(in, "%s", LINE_DOWN_LEFT);
        else if (c % 2 == 1)
            fprintf(in, "%s", LINE_HORIZONTAL);
        else
            fprintf(in, "%s", LINE_RIGHT_DOWN_LEFT);
    }

    fprintf(in, "\n");

    for (r = 1; r < (2 * row); r++)
    {

        for (c = 0; c < (2 * col) + 1; c++)
        {
            if (r % 2 == 1)
            {
                if (c % 2 == 1)
                    switch (board[r / 2][c / 2])
                    {
                    case BLACK_COLOR:
                        fprintf(in, "%s", SQUARE_BLACK); // warunek z boarda jaki kolor ma byc
                        break;
                    case WHITE_COLOR:
                        fprintf(in, "%s", SQUARE_WHITE); // warunek z boarda jaki kolor ma byc
                        break;
                    case ANT:
                        switch (ant->direction)
                        {
                        case UP:
                            if (ant->color == WHITE_COLOR)
                                fprintf(in, "%s", ARROW_NORTH_WHITE);
                            else
                                fprintf(in, "%s", ARROW_NORTH_BLACK);
                            break;
                        case DOWN:
                            if (ant->color == WHITE_COLOR)
                                fprintf(in, "%s", ARROW_SOUTH_WHITE);
                            else
                                fprintf(in, "%s", ARROW_SOUTH_BLACK);
                            break;
                        case LEFT:
                            if (ant->color == WHITE_COLOR)
                                fprintf(in, "%s", ARROW_WEST_WHITE);
                            else
                                fprintf(in, "%s", ARROW_WEST_BLACK);
                            break;
                        case RIGHT:
                            if (ant->color == WHITE_COLOR)
                                fprintf(in, "%s", ARROW_EAST_WHITE);
                            else
                                fprintf(in, "%s", ARROW_EAST_BLACK);
                            break;
                        }
                    }

                if (c % 2 == 0)
                    fprintf(in, "%s", LINE_VERTICAL);
            }
            else
            {
                if (c == 0)
                    fprintf(in, "%s", LINE_UP_RIGHT_DOWN);
                else if (c == (2 * col))
                    fprintf(in, "%s", LINE_UP_DOWN_LEFT);
                else if (c % 2 == 1)
                    fprintf(in, "%s", LINE_HORIZONTAL);
                else
                    fprintf(in, "%s", LINE_UP_RIGHT_DOWN_LEFT);
            }
        }
        fprintf(in, "\n");
    }

    for (c = 0; c < (2 * col) + 1; c++)
    {
        if (c == 0)
            fprintf(in, "%s", LINE_UP_RIGHT);
        else if (c == (2 * col))
            fprintf(in, "%s", LINE_UP_LEFT);
        else if (c % 2 == 1)
            fprintf(in, "%s", LINE_HORIZONTAL);
        else
            fprintf(in, "%s", LINE_UP_LEFT_RIGHT);
    }

    fprintf(in, "\n");
    if(in != stdout)
        fclose(in);
}
