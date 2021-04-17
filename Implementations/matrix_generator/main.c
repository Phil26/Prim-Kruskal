#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// --generarea unei matrici reprezentative pentru un graf conex, neorientat, avand costuri aferente muchiilor formate--

int main()
{

    unsigned short i, j, size;                                //var.i si j sunt iteratori iar size reprezinta dimensiunea matricei patratice
    int adj_matrix[size][size];                               //declaratia matricei care descrie graful

    printf("Enter the number of vertices: ");
    scanf("%hu" , &size);

    srand(time(NULL));
    for(i = 0; i < size; i++)
    {
        for(j = i; j < size; j++)
        {
            if(i == j)
            {
                adj_matrix[i][j] = 0;                       //matricea corespunzatoare unui graf neorientat are diagonala principala populata cu "0"
            }
            else
            {
                adj_matrix[i][j] = adj_matrix[j][i] = rand() % 10 + 1;    //matricea unui graf neorientat este simetrica fata de diagonala principala
            }
        }

    }

    // --afisarea matricei generate anterior--

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            printf("%d \t", adj_matrix[i][j]);
        }

        printf("\n");
    }



    return 0;

}
