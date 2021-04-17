#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include <time.h>


struct graph* create_graph(FILE *f)                                       //functie menita sa creeze graful pe baza citirii din fisierul de date
{

    int i;

    struct graph* G = (struct graph*)malloc(sizeof(struct graph));		  // alocare dinamica de menorie pentru graf
    G->num_of_vertices = V;											      // setarea numarului de noduri(int V)
    G->num_of_edges = E;												  // setarea numarului de muchii(int E)

    G->eEdge = (struct edge*)malloc(sizeof(struct edge)*G->num_of_edges);  // alocare de memorie pentru muchii
    for (i = 0; i < E; i++)										           // stabilirea muchiilor
    {
        fscanf(f, "%d", &G->eEdge[i].start_point);                         //citirea nodurilor sursa
        fscanf(f, "%d", &G->eEdge[i].end_point);                           //citirea nodurilor destinatare
        fscanf(f, "%d", &G->eEdge[i].weight);                              //citirea costului fiecarei muchii
    }

    fclose(f);
                                                                            //inchiderea fisierului din care s-au extras date
    return G;                                                               // returnarea grafului format
}


