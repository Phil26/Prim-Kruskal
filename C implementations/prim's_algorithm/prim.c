#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "prim.h"


FILE *f,*e;


int minimum_key(int k[], int min_span_tree[],int no_of_nodes2)          //functia "minimum_key" are rolul de a gasi nodul cu valoarea minima, dintre cele
{                                                                       //neincluse inca in arborele de acoperire minima

    int i, minimum = 1000000, min;
    for (i = 0; i < no_of_nodes2; i++)
    {
        if (min_span_tree[i] == 0 && k[i] < minimum)
        {
             minimum  = k[i];                                            //initializam valoarea minima
             min = i;                                                    //daca este gasit un nou minim, are loc switch-ul intre valori
        }
    }

    return min;                                                          //se returneaza valoarea minima gasita in urma comparatiilor care au loc
}

void prim(int a_graph[][700],int no_of_nodes2)
{
    int cost_total_acoperire = 0;
    int ascendent[700];
    //int ascendent[no_of_nodes2];                           //array-ul "parinte" sau ascendent in care se va stoca minimum spanning tree format
    int k[no_of_nodes2];
    int min_span_tree[no_of_nodes2];                         //folosit pentru a contoriza nodurile incluse cat si pe cele neincluse in arborele de acop.minima
    int i, counting, m, n;
    for (i = 0; i < no_of_nodes2; i++)
    {
        k[i] = INT_MAX;                                       //initializarea tuturor valorilor utilizand header-ul "limits.h"
        min_span_tree[i] = 0;                                 //arborele de acoperire minima este setat pe 0(este gol)
    }

    k[0] = 0;                                                 //se include primul nod in arborele de acoperire minima
    ascendent[0] = -1;                                        //primul nod va reprezenta radacina arborelui de acoperire minima care se va forma

    for (counting = 0; counting < no_of_nodes2 - 1; counting++)
    {
        m = minimum_key(k, min_span_tree,no_of_nodes2);        //se va include nodul cu cea mai mica valoare dintre cele disponibile(neincluse in arbore la momentul respectiv)
        min_span_tree[m] = 1;

        for (n = 0; n < no_of_nodes2; n++)
        {
            if (a_graph[m][n] && min_span_tree[n] == 0 && a_graph[m][n] <  k[n])
            {
                ascendent[n]=m;
                k[n]=a_graph[m][n];
            }
        }
    }

    for (i = 1; i < no_of_nodes2; i++)
    {

        cost_total_acoperire += a_graph[i][ascendent[i]];
        fprintf(e, "nod sursa: %d <-> nod destinatie: %d  => cost: %d \n", ascendent[i], i, a_graph[i][ascendent[i]]);    //afisarea din fisier a arborelui de acoperire minima obtinut
                                                                                                                          //mai exact, a muchiilor insotite de surse si destinatii, respectiv cost

    }

    fprintf(e, "Cost total: %d", cost_total_acoperire);     //afisarea costului total al acoperirii minime
    fprintf(e, "\n");

}

