import random
import time

def randomize(adj_matrix, no_of_nodes2):                     #functia "randomize" va fi responsabila de generarea matricei grafului
                                                             #i si j au rol de iteratori


    for i in range(0, no_of_nodes2):                          #operatia de iterare prin noduri
        for j in range(i, no_of_nodes2):
            if(i == j):                                       #pentru "i = j"(diagonala principala a matricei),elementele vor avea valoarea "0"
                adj_matrix[i][j] = 0
            else:
                adj_matrix[i][j] = adj_matrix[j][i] = random.randrange(3, 10000)     #altfel, elementele plasate in pozitii simetrice relativ la diagonala principala 
                #                                                                    #vor avea valori egale apartinand intervalului dorit de utilizator

