#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

void readArguments(int argc, char **argv, int *row_count, int *column_count, int *iterations, int *percent_fill, char **saveFileName, char **readFileName, enum Directions *direction)
{
    int opt;
    while ((opt = getopt(argc, argv, "m:n:i:f:d:g:r:")) != -1)
    {
        switch (opt)
        {
        case 'f':
            *saveFileName = malloc(sizeof **saveFileName * strlen(optarg));
            strcpy(*saveFileName, optarg);
            break;
        case 'm':
            if (atoi(optarg) <= 0)
            {
                printf("Niepoprawna wartość argumentu %c\n", opt);
                exit(1);
            }
            *row_count = atoi(optarg);
            break;
        case 'n':
            if (atoi(optarg) <= 0)
            {
                printf("Niepoprawna wartość argumentu %c\n", opt);
                exit(1);
            }
            *column_count = atoi(optarg);
            break;
        case 'i':
            if (atoi(optarg) <= 0)
            {
                printf("Niepoprawna wartość argumentu %c\n", opt);
                exit(1);
            }
            *iterations = atoi(optarg);
            break;
        case 'd':
            if (atoi(optarg) == 0 && strcmp(optarg, "0") != 0)
            {
                printf("Niepoprawna wartość argumentu %c\n", opt);
                exit(1);
            }
            if (atoi(optarg) > 3 || atoi(optarg) < 0)
            {
                printf("Niepoprawny kierunek mrówki %c. Podaj wartość z zakresu 0-3\n", opt);
            }
            *direction = atoi(optarg);
            break;
        case 'g':
            if (atoi(optarg) <= 0 || atoi(optarg) > 100)
            {
                printf("Niepoprawna wartość argumentu %c\n", opt);
                exit(1);
            }
            *percent_fill = atoi(optarg);
            break;
        case 'r':
            *readFileName = malloc(sizeof **readFileName * strlen(optarg));
            strcpy(*readFileName, optarg);
            break;
        case ':':
            printf("Opcja %c wymaga wartości\n", opt);
            break;
        case '?':
            printf("Podano niepoprawną opcję wywołania\n");
            break;
        }
    }
}

int getRandomValue(int maxValueExclusive)
{
    int r = rand();
    double d = (double)r / RAND_MAX;
    double val = d * (maxValueExclusive - 1);
    return round(val);
}