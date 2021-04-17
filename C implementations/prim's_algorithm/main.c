#include <stdio.h>
#include <stdlib.h>
#include "prim.c"
#include "adj_matrix_generator.c"
#include<time.h>
//int a_graph[no_of_nodes][no_of_nodes];           //declarare globala a unei matrice de forma prezentata
#define numar 20


int main()
{
    int i;
    int nr_teste;                                  //numarul de teste care se vor efectua
    int no_of_nodes2;

    printf("Numarul de teste: ");
    scanf("%d", &nr_teste);

    for(i = 1; i <= nr_teste; i++)
    {

        char str1[100],str2[100];
        sprintf(str1,"test%d.in", i);             //teste date de intrare
        sprintf(str2,"test%d.out", i);            //teste date de iesire
        clock_t start, finish;


        f = fopen(str1, "r");
        e = fopen(str2, "w");

        if(!str1 || !str2)
        {
            return -1;
        }

        fscanf(f, "%d", &no_of_nodes2);            //citirea numarului de noduri din fisier

        int a_graph[700][700];

        randomize(a_graph, no_of_nodes2);         //apelarea din main a functiei "randomize" asupra matricei de forma consacrata

        start = clock();                          //itilializare timpului contorizat
        prim(a_graph,no_of_nodes2);               //apelarea functiei "prim" descrisa in fisierul sursa "prim.c" care va opera asupra grafului generat cu ajutorul functiei anterioare
        finish = clock();
        float duration;
        duration = (float)(finish-start) / CLOCKS_PER_SEC;  //calcularea timpului de prelucrare a datelor din fiecare fisier

        puts("");
        fprintf(e, "Timp: %.6f", duration);        //afisarea timpului calculat anterior
        puts("");
        fprintf(e, "\n");

    }

return 0;

}
