#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include <time.h>


void kruskal(int n, int m, int L[200], struct graph *G, FILE *e)
{

    int i, j, k = 0, coverage_cost = 0;                    //variabilele locale i si j au rol de iteratori; variabila k contorizeaza
                                                           //valorile adaugate la pretul de cost; coverage_cost reprezinta pretul acoperirii minime
    int x, y;

    n = G->num_of_vertices;                                //n este initializat cu numarul de noduri ale grafului incarcat
                                                           //variabila m reprezinta numarul de muchii(edges)
    for(i = 0; i < m-1; i++)
    {
        for(j = i + 1; j < m; j++)
        {
            if(G->eEdge[i].weight > G->eEdge[j].weight)    //daca conditia din instructiunea "if" este indeplinita, are loc interschimbarea muchiilor
            {
                struct edge aux;

                aux = G->eEdge[i];
                G->eEdge[i] = G->eEdge[j];                 //operatia de interschimbare a muchiilor astfel incat acestea sa fie ordonate crescator
                G->eEdge[j] = aux;                         //dupa criteriul costului

            }
        }
    }

    for(i = 0 ; i < n ; i++)
    {
        L[i] = i;                                           //"sirul" nodurilor
    }

    fprintf(e, "\n Arborele de acoperire minima are urmatoarele muchii: \n");
    fprintf(e, "\n");

    i = 0;

    while(k < n-1)
    {

        if(L[G->eEdge[i].start_point] != L[G->eEdge[i].end_point])        //daca sursa muchiei difera cu destinatia acesteia(nu exista bucle)
        {                                                                 //aceasta intra in calculul pretului de cost final

            k++;
            coverage_cost = coverage_cost + G->eEdge[i].weight;           //calcularea costului de acoperire minima
            fprintf(e, "muchie: {%d <-> %d} -> cost: %d\n", G->eEdge[i].start_point, G->eEdge[i].end_point, G->eEdge[i].weight);

            x = L[G->eEdge[i].end_point];			//realizarea legaturilor grafului prin muchia [x,y]
            y = L[G->eEdge[i].start_point];         //unde x se va identifica cu sursa muchiei si y cu capatul destinatie al aceleasi muchii

            for(j = 0; j < n; j++)
            {
                if(L[j] == x)
                {
                    L[j] = y;                                              //se verifica existenta buclelor
                }
            }

        }

        i++;
        fprintf(e, "\n Cost acoperire minima = %d \n", coverage_cost);      //ultimul cost afisat reprezinta costul total al acoperirii minime
        //break;
    }

}


void main()
{

    //incarcarea si afisarea grafului din fisiere

    struct graph *G;       //declararea unei structuri de tipul "struct graph" care se va identifica cu graful pe care va opera algoritmul lui Kruskal
    int i, j;
    FILE *f, *e;
    int nr_teste;

    printf("Numarul de teste: ");
    scanf("%d", &nr_teste);

    char str1[100],str2[100];

    for(i = 1; i <= nr_teste; i++)
    {


        sprintf(str1,"input_data%d.in", i);                         //fisiere date de intrare
        sprintf(str2,"out_data%d.out", i);                          //fisiere date de iesire
        clock_t start, finish;

        f = fopen(str1, "r");
        e = fopen(str2, "w");

        if(!str1 || !str2)
        {
            return -1;
        }

    fscanf(f, "%d", &V);                                            //citirea nr.de noduri din fisier
    fscanf(f, "%d", &E);                                            //citirea nr.de muchii din fisier

    G = create_graph(f);                    //se va dezvolta graful prin intermediul functiei "create_graph" implementate in fisierul sursa "graph.c"

    fprintf(e, "\n Muchiile si costurile aferente acestora: \n");
    fprintf(e, "\n");

    for(j = 0; j < G->num_of_edges; j++)
    {
        //se vor afisa punctele sursa cat si cele de destinatie pentru fiecare muchie cat si costurile aferente acestora
        fprintf(e, "muchie: {%d <-> %d} -> cost: %d \n", G->eEdge[j].start_point, G->eEdge[j].end_point, G->eEdge[j].weight);
    }

    int n, m, L[200];

    m = G->num_of_edges;
    start = clock();
    kruskal(n, m, L, G, e);     //apel al functiei "kruskal" definita in fisierul sursa "kruskal.c", menita sa opereze pe graful incarcat anterior
    finish = clock();
    puts("");
    fprintf(e, "\n Timp:%.6f",(float)(finish-start) / CLOCKS_PER_SEC);    //afisarea timpului de executie pentru fiecare set de date
    puts("");
    fprintf(e, "\n");
    fclose(f);
    fclose(e);
    }

    return 0;
}

