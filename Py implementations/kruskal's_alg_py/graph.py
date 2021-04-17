import pprint
from collections import defaultdict

class Graph(object)
graph_dict={}

#Graph data structure, undirected by default

    def __init__(self):
        self.vert_dict = {}
        self.num_vertices = 0


class edge(object)
    def __init__(self, start_point, end_point, weight):
            self.start_point = []
            self.end_point = []
            self.weight = []


def create_graph()                                                       #functie menita sa creeze graful pe baza citirii din fisierul de date

    f = open("input_data.txt", "r")                                      #deschiderea fisierului in scopul citirii din acesta
    V = int(f.read())
    E = int(f.read())

    graph* G = (graph*)malloc(sizeof(graph))		                      #alocare dinamica de memorie pentru graf
    G.num_of_vertices = V											      #setarea numarului de noduri
    G.num_of_edges = E												      #setarea numarului de muchii

    G.eEdge = (edge*)malloc(sizeof(edge) * G.num_of_edges)                #alocare de memorie pentru muchii
    i = 0
    while i < E:
       G.eEdge[i].start_point = int(f.read())                             #citirea nodurilor sursa
       G.eEdge[i].end_point = int(f.read())                               #citirea nodurilor destinatare
       G.eEdge[i].weight = int(f.read)                                    #citirea costului fiecarei muchii
       i = i + 1

    return G                                                              #returnarea grafului creat

