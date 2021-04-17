import time
from adj_matrix_gen import randomize
from prim import prim
from numpy import *

nrteste = int(input("Numarul de teste care se vor efectua: "))
for i in range(1,nrteste+1):


    str1 = "test{}i.txt".format(i)
    str2 = "test{}o.txt".format(i)

    f = open(str1, "r")
    e = open(str2, "a")


    no_of_nodes2 = f.readline()
    no_of_nodes2 = int(no_of_nodes2)
    a_graph = arange(no_of_nodes2 * no_of_nodes2).reshape((no_of_nodes2, no_of_nodes2))

    randomize(a_graph, no_of_nodes2)                               #apelarea functiei "randomize" responsabila de generarea matricei aferente grafului
    start = time.time()
    prim(a_graph,no_of_nodes2,str2)                                #apelarea functiei "prim" descrisa in fisierul sursa "prim.py" care va opera asupra grafului generat cu ajutorul functiei anterioare
    finish = time.time()
    duration = (finish-start)                                      #calcularea timpului necesar executiei programului pentru testul respectiv
    print("")

    e.write("\nTimp: {}".format(duration))                         #afisarea timpului de executie pentru fiecare set de date
    print("")


