import graph
import time
def kruskal( n, m, L, G):
    k = 0
    coverage_cost = 0
    n = G.num_of_vertices                                         #n este initializat cu numarul de noduri ale grafului incarcat
    i = 0
    while i < m:
        j = i + 1
        while j < m:
            if G.eEdge[i].weight > G.eEdge[j].weight:             #sortarea muchiilor(aranjarea) in functie de valoare prin interschimbare
                aux = G.eEdge[i]
                G.eEdge[i] = G.eEdge[j]
                G.eEdge[j] = aux
            j = j + 1
     i = i + 1
    i = 0
    while i < n:
        L[i] = i
        i = i + 1
    print("\n Arborele de acoperire minima are urmatoarele muchii: \n")
    while(k < n-1):
        if L[G.eEdge[i].start_point] != L[G.eEdge[i].end_point]:                 #daca sursa muchiei difera cu destinatia acesteia(nu exista bucle)
              k = k + 1                                                          #aceasta intra in calculul pretului de cost final
            coverage_cost = coverage_cost + G.eEdge[i].weight                    #calcularea costului de acoperire minima
            print("muchie: {%d <-> %d} -> cost: %d\n", G.eEdge[i].start_point, G.eEdge[i].end_point, G.eEdge[i].weight)
            x = L[G.eEdge[i].end_point]					                         #realizarea legaturilor grafului prin muchia [x,y]
            y = L[G.eEdge[i].start_point]                                        #unde x se va identifica cu sursa muchiei si y cu capatul destinatie al aceleasi muchii
            j = 0
            while j < n:
                if L[j] == x:
                    L[j] = y
                j = j + 1
        i = i + 1
        print("\n Cost acoperire minima = %d \n", coverage_cost)                 #ultimul cost afisat reprezinta costul total al acoperirii minime
        k = n


 graph *G                                 #declararea unei structuri de tipul "struct graph" care se va identifica cu graful pe care va opera algoritmul lui Kruskal                             //declararea unui pointer catre un fisier din care se vor extrage ulterior datele de lucru
f = open("input_data.txt", "r")
G = create_graph()                        #se va dezvolta graful prin intermediul functiei "create_graph" implementate in fisierul sursa "graph.c"

print("Muchiile si costurile aferente acestora:")
i = 0
while i < i < G.num_of_edges:
    print("muchie: {%d <-> %d} -> cost: %d \n", G.eEdge[i].start_point, G.eEdge[i].end_point, G.eEdge[i].weight)
    i = i + 1
    L=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
    start = time.time()
    kruskal(n, 50, L, G)                       #apel al functiei "kruskal" definita in fisierul sursa "kruskal.c", menita sa opereze pe graful incarcat anterior
    finish = time.time
    print(finish-start)                        #afisarea timpului de executie pentru fiecare set de date


