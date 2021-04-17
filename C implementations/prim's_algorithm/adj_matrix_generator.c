#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "adj_matrix_generator.h"



void randomize(int adj_matrix[][700],int no_of_nodes2)        //functia "randomize" va fi responsabila de generarea matricei grafului
{
    unsigned short i, j;                                      //i si j au rol de iteratori

    srand(time(NULL));
    for(i = 0; i < no_of_nodes2; i++)                         //operatia de iteratie prin noduri
    {
        for(j = i; j < no_of_nodes2; j++)
        {
            if(i == j)                                         //pentru i = j(diagonala principala a matricei),elementele vor avea valoarea "0"
            {
                adj_matrix[i][j] = 0;
            }
            else
            {
                adj_matrix[i][j] = adj_matrix[j][i] = rand() % 10000 + 1;     //altfel, elementele plasate in pozitii simetrice relativ la diagonala principala
                                                                              //vor avea valori egale(cuprinse intre 0 si 10000 in acest caz)

            }
        }

    }
}

