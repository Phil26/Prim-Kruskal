#include<stdlib.h>
#include<stdio.h>
#include "kruskal.h"
#include "graph.h"


void kruskal(int n,int m, int L[20], struct graph *G)
{

    int i, j, k = 0, coverage_cost = 0;
    int x, y;

    int n = G->num_of_vertices;

    for(i = 0; i < m; i++)
    {
        for(j = i + 1; j < m; j++)
        {
            if(G->eEdge[i].weight > G->eEdge[j].weight)
            {

                struct edge aux;

                aux = G->eEdge[i];
                G->eEdge[i] = G->eEdge[j];
                G->eEdge[j] = aux;

            }
        }
    }

//Kruskal
    for(i = 0 ; i < n ; i++)
    {

        L[i] = i;
    }

    printf("\n MST are urmatoarele muchii: \n");

    while(k < n-1)
    {

        if(L[G->eEdge[i].start_point] != L[G->eEdge[i].end_point])
        {

            k++;

            coverage_cost = coverage_cost + G->eEdge[i].weight;

            printf("[%d <-> %d]\n", G->eEdge[i].start_point, G->eEdge[i].end_point);

            x = L[G->eEdge[i].end_point];					//realizarea legaturilor grafului prin muchia [x,y]
            y = L[G->eEdge[i].start_point];

            for(j = 0; j < n; j++)

                if(L[j] == x)

                    L[j] = y;

        }

        i++;

    }

    printf("\n Costul total al acoperirii minime = %d \n", coverage_cost);

}
