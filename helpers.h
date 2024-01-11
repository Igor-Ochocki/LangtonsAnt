#ifndef _HELPERS_H_
#define _HELPERS_H_
#include "ant.h"

void readArguments(int argc, char **argv, int *row_count, int *column_count, int *iterations, int *percent_fill, char **saveFileName, char **readFileName, enum Directions *direction);
int getRandomValue(int maxValueExclusive);

#endif