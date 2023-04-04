#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Apr  1 08:36:00 2022

@author: userir
"""

from graphes import *

# from more_itertools import sliding_window
import collections
from itertools import islice
def sliding_window(iterable, n):
    # sliding_window('ABCDEFG', 4) -> ABCD BCDE CDEF DEFG
    it = iter(iterable)
    window = collections.deque(islice(it, n), maxlen=n)
    if len(window) == n:
        yield tuple(window)
    for x in it:
        window.append(x)
        yield tuple(window)


###############################################################################
########                                                               ########
########        Partie 2                                               ########
########                                                               ########
###############################################################################

#-----------------------------------[Q 2.1]-----------------------------------<
#Paramètres: G -> un graphe orienté (créé avec graphe_orienté())
#            c -> une liste de sommet
#But: la fonction vérifie si le chemin définit par c est valide
#Précision: Les chemins vide, ou à un élément, ne sont pas considéré valides
def verification_chemin(G, c):
    for arc in list(sliding_window(c,2)):
    # Si $arc n'est pas un arc valide
        if not arc[1] in G[arc[0]]:
            return False
    return len(c)>1
## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Tests >
def test_verification_chemin():
    g = {0: [2], 1: [], 2: [3], 3: [4], 4: []}
    c = [0,2,3,4]
    print("Graphe:")
    print(g)
    print("Chemin valide:")
    print(c)
    print("Resultat verification_chemin: ")
    print(verification_chemin(g, c))
    c = [1,2,3]
    print("Chemin non valide:")
    print(c)
    print("Resultat verification_chemin: ")
    print(verification_chemin(g, c))
    c = []
    print("Chemin vide:")
    print(c)
    print("Resultat verification_chemin: ")
    print(verification_chemin(g, c))
#-----------------------------------------------------------------------------#



#-----------------------------------[Q 2.2]-----------------------------------<
#Paramètres: c -> une liste de sommet
#            o -> un sommet
#But: la fonction vérifie que o est le premier élément du chemin c
#Précision: Les chemins vide, ou à un élément, ne sont pas considéré valides
def verification_origine(c, o):
    return len(c)>1 and (o == c[0])
## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Tests >
def test_verification_origine():
    c = [0,2,3,4]
    print("Chemin:")
    print(c)
    print("Cas o valide: o=0")
    print("Resultat verification_origine: ")
    print(verification_origine(c,0))
    print("Cas o non valide: o=1")
    print("Resultat verification_origine: ")
    print(verification_origine(c,1))
    c = []
    print("Chemin vide: []")
    print("Resultat verification_origine: ")
    print(verification_origine(c,0))
#-----------------------------------------------------------------------------#



#-----------------------------------[Q 2.3]-----------------------------------<
#Paramètres: c -> une liste de sommet
#            o -> un sommet
#But: la fonction vérifie que o est le dernier élément du chemin c
#Précision: Les chemins vide, ou à un élément, ne sont pas considéré valides
def verification_destination(c, o):
    return len(c)>1 and (o == c[-1])
## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Tests >
def test_verification_destination():
    c = [0,2,3,4]
    print("Chemin:")
    print(c)
    print("Cas o valide: o=4")
    print("Resultat verification_destination: ")
    print(verification_destination(c,4))
    print("Cas o non valide: o=1")
    print("Resultat verification_destination: ")
    print(verification_destination(c,1))
    c = []
    print("Chemin vide: []")
    print("Resultat verification_destination: ")
    print(verification_destination(c,0))
#-----------------------------------------------------------------------------#

#-----------------------------------[Q 2.4]-----------------------------------<
#Paramètres: l -> une fonction longueur
#              --> protoype int l(int a, int b) [avec a et b des sommets]
#            c -> une liste de sommet
#But: calculer la longueur totale du chemin c par la fonction l
#Précision: Les chemins vide, ou à un élément, ne sont pas considéré valides,
#           on renverra donc 0 dans ces cas là.
def calcul_longueur(l, c):
    if len(c)<2 :
        return 0
# return sum(list(map(lambda x: longueur(x[0],x[1]),sliding_window(c,2))))
# return sum(list(map(lambda x: longueur(*x),sliding_window(c,2))))
    sum = 0
    for arc in list(sliding_window(c,2)):
        sum = sum + l(arc[0],arc[1])
    return sum
## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Tests >
def test_calcul_longueur():
    c = [0,2]
    print("Chemin de longueur 4:")
    print(c)
    print("Longueur chemin: ")
    print(calcul_longueur(longueur, c))
    c = []
    print("Chemin vide:")
    print(c)
    print("Longueur chemin: ")
    print(calcul_longueur(longueur, c))
#-----------------------------------------------------------------------------#



###############################################################################
########                                                               ########
########        Partie 3                                               ########
########                                                               ########
###############################################################################

#-----------------------------------[Q 3.5]-----------------------------------<
#Paramètres: G -> un graphe orienté (créé avec graphe_orienté())
#            l -> une fonction longueur
#            c -> une liste de sommet
#            s,t -> deux sommets quelconque
#            k -> un nombre
#But: La fonction vérifie si le chemin c est valide dans G, va bien de s à t
#     et est de longueur inférrieure ou égale à k.
#Précision: Les chemins vide, ou à un élément, ne sont pas considéré valides
def verification_certificat_oui(G, l, c, s, t, k):
    return verification_chemin(G, c) and verification_origine(c, s) and verification_destination(c, t) and (calcul_longueur(l, c)<=k)
## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Tests >
def test_verification_certificat_oui():
    print("pas fait")
#-----------------------------------------------------------------------------#


#-----------------------------------[Q 3.6]-----------------------------------<
#Paramètres: G -> un graphe orienté (créé avec graphe_orienté())
#            l -> une fonction longueur
#            phi -> une fonction potentiel
#                --> protoype int phi(int a) [avec a un sommet]
#But: La fonction vérifie que phi est bien un potentiel pour le graphe G
#       muni de la fonction longueur l.
#def verification_certificat_non(G, l, phi):
    

#-----------------------------------[Q 3.6]-----------------------------------<
#Paramètres: G -> un graphe orienté (créé avec graphe_orienté())
#            l -> une fonction longueur
#            phi -> une fonction potentiel
#                --> protoype int phi(int a) [avec a un sommet]
#            s,t -> deux sommets quelconque
#            k -> longueur du chemin à vérifier
#But: La fonction vérifie que phi est bien un potentiel pour le graphe G
#       muni de la fonction longueur l.
#     Puis vérifier que k est bien une longueur impossible pour ce chemin
def verification_certificat_non(G, l, phi, s, t, k):
    for x in G.keys():
        for y in G[x]:
            if not ( phi(y) <= phi(x)+l(x,y) ):
                return False
    return k <= phi(s) - phi(t)
## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Tests >
def test_verification_certificat_non():
    g = {0: [2], 1: [], 2: [3], 3: [4], 4: []}
    c = [0,2,3]
    s = c[0]
    t = c[-1]
#   phi = 
    print("Graphe:")
    print(g)
    print("Chemin valide:")
    print(c)
    print("Longueur Chemin:")
    print(calcul_longueur(longueur, c))
    print("Resultat verification_chemin: ")
    print("verification_certificat_non(G, l, phi, s, t, k)")
#-----------------------------------------------------------------------------#


#-----------------------------------[Q 4.7]-----------------------------------<
#Paramètres: G -> un graphe orienté (créé avec graphe_orienté())
#            s -> le sommet de départ
#            l -> une fonction longueur
#Retourne:
#            M -> l'ensemble des sommets accessible
#            d -> fonction qui renvoie la longueur
#                d'un plus court chemin (de s à t)
#            o -> fonction qui renvoie le plus court
#                chemin (de s à t)
#But: La fonction vérifie 
#     
#     
def Dijkstra(G, s, l):
    _M = list(G)
    _M.remove(s)
    M = [s]
    o = {}
    d = {s:0}
    arc = get_arc(M,_M,G)
    while( arc != None ):
        x = arc[0]
        y = arc[1]
        if( x not in d.keys() or calcul_longueur(longueur,arc) < d[x] + longueur(*arc) ):
            M.append(y)
            _M.remove(y)
            o[y] = x
            d[y] = d[x] + longueur(*arc)
        arc = get_arc(M,_M,G)
    return (M,o,d)

## ~~ Fonction auxiliaire
# Retour:
#       Renvoie un arc, ou None
# Parametres:
#       D -> ensemble de Départ
#       A -> ensemble d'Arrivé
#       G -> Graphe orienté
def get_arc(D,A,G):
    for x in D:
        for y in A:
            if (y in G[x]):
                return [x,y]
    return None
    
















#cool ça marche !!!
#c=[0,2,3,4]
#def wrap_len(args): # without star
#    return longueur(*args)
#sum(list(map( wrap_len ,sliding_window(c,2))))


















