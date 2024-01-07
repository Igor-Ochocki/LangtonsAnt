#include "board_generator.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>



int **generateBoard( int row,int col, int fill_percentage )
{
	srand(time(NULL));
	int size=row*col;
	int black_cells=(int)((float) (size*fill_percentage)/100);
	int **board = malloc(sizeof *board * row);
	int i=0;
    	for (i = 0; i < row; i++)
       		board[i] = calloc(col,sizeof *board[i]);
	
	int *tab = malloc(sizeof *tab * size);
	for(i=0; i<size; i++)
		tab[i]=i;

	for(i=0; i<size-1; i++)
	{
		int j=i+rand() / (RAND_MAX / (size-i)+1);
		int t =tab[j];
		tab[j]=tab[i];
		tab[i]=t;
	}


	for(i=0; i<black_cells; i++)
		board[tab[i]/col][tab[i]%col]=BLACK_COLOR;
	
	printf("%d\n",black_cells);
	        printf("%d\n",fill_percentage);
		        printf("%d\n",size);


	return board;

}
