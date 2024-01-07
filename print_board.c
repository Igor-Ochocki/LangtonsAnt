#include "print_board.h"
#include <stdio.h>

void printBoard( int **board, int row, int col )
{
        
        
        int c=0;
        int r=0;
        for(c=0; c<(2*col)+1; c++)
        {
                if(c==0)
                        printf("%s",LINE_DOWN_RIGHT);
                else  if(c==(2*col))
                        printf("%s",LINE_DOWN_LEFT);
                else if(c%2==1)
                    printf("%s",LINE_HORIZONTAL);
                else
                        printf("%s",LINE_RIGHT_DOWN_LEFT);
        }


printf("\n");


        for(r=1; r<(2*row); r++)
        {

                for(c=0; c<(2*col)+1; c++)
                {
                        if(r%2==1)
                        {
                                if(c%2==1)
                                printf("%s",SQUARE_BLACK); //warunek z boarda jaki kolor ma byc
                                if(c%2==0)
                                printf("%s",LINE_VERTICAL);

                        }
                        else
                        {
                                if(c==0)
                                        printf("%s",LINE_UP_RIGHT_DOWN);
                                else if(c==(2*col))
                                        printf("%s",LINE_UP_DOWN_LEFT);
                                else if(c%2==1)
                                        printf("%s",LINE_HORIZONTAL);
                                else
                                        printf("%s",LINE_UP_RIGHT_DOWN_LEFT);


                        }

                }
 printf("\n");


        }



        for(c=0; c<(2*col)+1; c++)
        {
                if(c==0)
                        printf("%s",LINE_UP_RIGHT);
                else if(c==(2*col))
                        printf("%s",LINE_UP_LEFT);
                else if(c%2==1)
                        printf("%s",LINE_HORIZONTAL);
                else
                        printf("%s",LINE_UP_LEFT_RIGHT);
        }


printf("\n");	

}
