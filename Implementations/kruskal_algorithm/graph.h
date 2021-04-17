#ifndef graph_H                                       //file guards("protejeaza" functia pentru a nu fi inclusa mai mult de o singura data)
#define graph_H

#include <stdio.h>
#include<stdlib.h>


int V, E;

typedef struct edge							           //structura care defineste notiunea de muchie a grafului
{
    int start_point;								   //nodul sursa sau nodul de plecare al unei muchii, originea
    int end_point;									   //nodul destinatar
    int weight;										   //costul muchiei respective
};

typedef struct graph								   //modul de structurare a grafului
{
    int num_of_vertices;							   //numarul de noduri(vertexuri) ale grafului
    int num_of_edges;								   //numarul de muchii sau legaturi prezente in graf
    struct edge *eEdge;								   //pointer la tipul de structura "edge" definit anterior
};


struct graph* create_graph(FILE *f);                    //prototipul functiei "create_graph" dezvoltata in fisierul sursa "graph.c"


#endif                                                  //file guards
