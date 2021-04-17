


def minimum_key(k, min_span_tree, no_of_nodes2):              #functia "minimum_key" are rolul de a gasi nodul cu valoarea minima, dintre cele
    minimum = 999999                                          #neincluse inca in arborele de acoperire minima
    min = 99999
    for i in range(0, no_of_nodes2):
        if min_span_tree[i] == 0 and k[i] < minimum:
             minimum  = k[i]                                              #initializam valoarea minima
             min = i                                                      #daca este gasit un nou minim, are loc switch-ul intre valori

    return min                                                            #se returneaza valoarea minima gasita in urma comparatiilor care au loc


def prim(a_graph,no_of_nodes2,str2):
    e = open(str2,"w")
    ascendent = [0] * 10000
    #int ascendent[no_of_nodes2];             #array-ul "parinte" sau ascendent in care se va stoca minimum spanning tree format
    k = []                                    #folosit pentru a contoriza nodurile incluse cat si pe cele neincluse in arborele de acop.minima
    min_span_tree = []
    for i in range(0, no_of_nodes2):
        k.append(99999)                                       #initializarea tuturor valorilor utilizand header-ul "limits.h"
        min_span_tree.append(0)                               #arborele de acoperire minima este setat pe 0(este gol)

                                                    #se include primul nod in arborele de acoperire minima
    ascendent[0] = -1                               #primul nod va reprezenta radacina arborelui de acoperire minima care se va forma

    for counting in range(0, no_of_nodes2):
        m = 0
        m = minimum_key(k, min_span_tree,no_of_nodes2)                  #se va include nodul cu cea mai mica valoare dintre cele disponibile(neincluse in arbore la momentul respectiv)
        min_span_tree[m] = 1

        for n in range(0, no_of_nodes2):
            if a_graph[m][n] and min_span_tree[n] == 0 and a_graph[m][n] <  k[n]:
                ascendent[n] = m
                k[n] = a_graph[m][n]

    cost_total = 0
    for i in range(1, no_of_nodes2):
        cost_total = cost_total + a_graph[i][ascendent[i]]
        e.write("sursa - destinatie & cost -> ")
        e.write("muchia:  {} - {} & {}\n".format(ascendent[i],i,a_graph[i][ascendent[i]]))        #afisarea muchiilor care formeaza arborele de acoperire minima insotite de nodurile
                                                                                                  # sursa si destinatie, precum si de costul fiecarei muchii in parte
    e.write("Cost total: {}" .format(cost_total))                                                                                     