# -*- coding: utf-8 -*-
"""
Created on Sat Apr 23 11:43:57 2022

@author: rougej
"""

from graphes import *
from td_acc import ensemble_sommet
from td_acc import nb_succ
from td_acc import mirroir
#from td_acc import
#from td_acc import
#from td_acc import
from td_acc import Appel_accessibles3 as accessibles
from td_acc import Accessible as chemin


###############################################################################
########                                                               ########
########        Partie 2                                               ########
########                                                               ########
###############################################################################

#-----------------------------------[Q 2.1]-----------------------------------<
## Q: combien de composantes connexes a un graphe sur n sommets sans arrêtes ?
# D'après la définition, ce graphes aurait _n_ composantes connexes.
#
#-----------------------------------------------------------------------------#


#-----------------------------------[Q 2.2]-----------------------------------<
#   Soit G un graphe non-orienté, G' le graphe orienté correspondant.
# On veut montrer que, pour tout s appartenant à G', les sommets accessibles
# depuis s dans G' forment une composante connexe de G.
# L'ensemble des sommets accessibles depuis s est l'ensemble des sommets x pour
# lequels il existe un chemin (s,x). Or d'après la définition du paragraphe 2
# (énoncé), cet ensemble des sommets x est une partie connexe.
# On veut maintenant vérifier que cette partie connexe est bien la plus grande
# au sens de l'inclusion des parties.
# Propriété des graphes non-orienté:
#   Soit S l'ensemble des sommets accessibles depuis s, alors pour tout 
#   sommet x appartenant à S, l'ensemble des sommets accessibles depuis x
#   est toujours S.
# Preuve de cette propriété par l'absurde:
#   Prenons un sommet y qui serait accessible depuis x mais pas depuis s.
#   Comme y est accessible depuis x, il existe un chemin (x,y).
#   Or x est aussi accessible depuis s, donc il existe un chemin (s,x).
#   Donc il existe un chemin (s,y).
#   Donc y est accessible depuis s. Ce qui contredit notre hypothèse de départ.
# On peut donc affirmer que la partie connexe trouvée précédement
# est bien une composante connexe de G contenant s.
#
#-----------------------------------------------------------------------------#

#-----------------------------------[Q 2.3]-----------------------------------<
# Algorithme permettant de calculer la partie connexe contenant s
#  d'un graphe orienté G.
#
#Composante_Connexe(s):
#   S ← [s]                         # S: liste contenant le sommet de départ
#   Pour chaque sommet x dans G:    #
#        A ← accessibles(x)         # A: sommets accessibles depuis x
#        Si A contient s:           # Si on trouve une nouvelle branche connexe
#            S ← S ∪ A              # On ajoute les nouveaux sommets
#        Fin Si                     #
#    Fin Pour                       #
#   Retourner S                     # On renvoie la composante connexe



#-----------------------------------[Q 2.4]-----------------------------------<
#Paramètres: G -> un graphe non-orienté (créé avec graphe_non_oriente())
#But: La fonction partitionne le graphe G en ses différentes
#       composantes connexe.
#     Le résultat est de la forme d'une liste de liste de sommets
# 
def partition(G):
    S = set(ensemble_sommet(G)) # Création d'un set à partir de la liste
    L = []
    while(len(S)>0):
        s = S.pop()             # On retire un élément du set
        A = accessibles(G,s)[0] # On calcule les sommet accessibles de cet elem
        L.append(A)             # On reajoute la composante connexe
        list(map(S.discard,A))
# On utilise set.discard() plutot que list.remove() car elle ne renvoie pas
# d'erreur si l'élément à retirer n'est pas présent.
    return L                    #  
## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Tests >
def test_partition():
    g = {0: [2], 1: [], 2: [3], 3: [4], 4: []}
    print("Graphe:")
    print(g)
    print("Ce graphe a 2 composantes connexes")
    print("Resultat partition(g): ")
    print(partition(g))
#-----------------------------------------------------------------------------#


#-----------------------------------[Q 2.5]-----------------------------------<
#Paramètres: G -> un graphe non-orienté (créé avec graphe_non_oriente())
#But: La fonction vérifie si le graphe ne contient qu'une composante connexe
# 
def connexe(G):
    return len(partition(G)) == 1
## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Tests >
def test_connexe():
    g = {0: [2], 1: [], 2: [3], 3: [4], 4: []}
    print("------------------- Test 1 -------------")
    print("Graphe:")
    print(g)
    print("Ce graphe a 2 composantes connexes")
    print("On s'attend à un résultat faux")
    print("Resultat partition(g): ")
    print(connexe(g))
    g.pop(1)
    print("------------------- Test 2 -------------")
    print("Graphe:")
    print(g)
    print("Ce graphe a 1 composante connexe")
    print("On s'attend à un résultat vrai")
    print("Resultat partition(g): ")
    print(connexe(g))
    print("------------------- Test 3 -------------")
    print("Graphe:")
    print({})
    print("Ce graphe a 0 composante connexe")
    print("On s'attend à un résultat faux")
    print("Resultat partition(g): ")
    print(connexe({}))
    print("----------------------------------------")
#-----------------------------------------------------------------------------#



###############################################################################
########                                                               ########
########                Partie 3.1 Routines utilitaires                ########
########                                                               ########
###############################################################################

#-----------------------------------[Q x.x]-----------------------------------< Voir avec le prof par rapport à la question (type du graphe non précisé)
#Paramètres: G -> un graphe orienté (créé avec graphe_oriente())
#            s -> un sommet
#But: La fonction calcule le degree total du sommet s dans le graphe G
# 
#def degre(G,s):
# Idée originale:
#   Ne fonctionne pas si s s'autoréférence
#   return nb_succ(s,G) + nb_succ(s,mirroir(G))
#
# Version corrigée
#    res = nb_succ(s,G) + nb_succ(s,mirroir(G))
#    if(s in G[s]):
#        res = res-2
#    return res
#
# One-liner :)
#    return nb_succ(s,G) + nb_succ(s,mirroir(G)) - 2*(s in G[s])

#-----------------------------------[Q 3.6]-----------------------------------<
#Paramètres: G -> un graphe non-orienté (créé avec graphe_non_oriente())
#            s -> un sommet
#But: La fonction calcule le degree total du sommet s dans le graphe G
# 
def degre(G,s):
    return nb_succ(s,G)

## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Tests >
def test_degre():
    g = {0: [2], 1: [], 2: [3], 3: [4], 4: []}
    print("Graphe:")
    print(g)
    print("------------------- Test 1 -------------")
    print("Le sommet 3 est de degré 2")
    print("Resultat degre(G,3): ")
    print(degre(g,3))
    print("------------------- Test 2 -------------")
    print("Le sommet 1 est de degré 0")
    print("Resultat degre(G,1): ")
    print(degre(g,1))
    print("----------------------------------------")
#-----------------------------------------------------------------------------#


#-----------------------------------[Q 3.7]-----------------------------------<
#Paramètres: G -> un graphe non-orienté (créé avec graphe_non_oriente())
#            s -> un sommet
#But: La fonction renvoie Vrai si le degre du sommet s est pair, faux sinon.
# 
def degrePair(G,s):
    return degre(G,s) % 2 == 0
## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Tests >
def test_degrePair():
    g = {0: [2], 1: [], 2: [0,3], 3: [2,4], 4: [3]}
    print("Graphe:")
    print(g)
    print("------------------- Test 1 -------------")
    print("Le sommet 3 est de degré 2")
    print("On s'attend à un résultat vrai")
    print("Resultat degrePair(G,3): ")
    print(degrePair(g,3))
    print("------------------- Test 2 -------------")
    print("Le sommet 1 est de degré 0")
    print("On s'attend à un résultat vrai")
    print("Resultat degrePair(G,1): ")
    print(degrePair(g,1))
    print("------------------- Test 2 -------------")
    print("Le sommet 0 est de degré 1")
    print("On s'attend à un résultat faux")
    print("Resultat degrePair(G,0): ")
    print(degrePair(g,0))
    print("----------------------------------------")
#-----------------------------------------------------------------------------#


#-----------------------------------[Q 3.8]-----------------------------------<
#Paramètres: G -> un graphe non-orienté (créé avec graphe_non_oriente())
#            s -> un sommet
#But: La fonction renvoie Vrai si le degre de tous les sommets de G sont pair,
#      faux sinon.
# 
def degrePairs(G):
    for s in ensemble_sommet(G):
        if not degrePair(G,s):
            return False
    return True
## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Tests >
def test_degrePairs():
    print("------------------- Test 1 -------------")
    g = {0: [2], 1: [], 2: [0,3], 3: [2,4], 4: [3]}
    print("Graphe:")
    print(g)
    print("Le sommet 0 est de degré impair")
    print("On s'attend à un résultat faux")
    print("Resultat degrePairs(G): ")
    print(degrePairs(g))
    print("------------------- Test 2 -------------")
    g = {0: [2,1], 1: [3,0], 2: [0,3], 3: [2,1]}
    print("Graphe:")
    print(g)
    print("Tous les sommets sont de degré pair")
    print("On s'attend à un résultat vrai")
    print("Resultat degrePairs(G): ")
    print(degrePairs(g))
    print("------------------- Test 3 -------------")
    g = {}
    print("Graphe vide:")
    print(g)
    print("On décide que le graphe vide a tous ses")
    print("sommets de degré impair")
    print("On s'attend à un résultat vrai")
    print("Resultat degrePairs(G): ")
    print(degrePairs(g))
    print("----------------------------------------")
#-----------------------------------------------------------------------------#


#-----------------------------------[Q 3.9]-----------------------------------<
#Paramètres: G -> un graphe non-orienté (créé avec graphe_non_oriente())
#           x,y -> deux sommets
#But: La fonction renvoie le graphe G privé de l'arête x,y
#      faux sinon.
# 
def retireArete(G,x,y):
    # On essaie au cas où l'arête n'existe pas
    try:
        G[x].remove(y)
        G[y].remove(x)
    except ValueError:
        pass
    return G
## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Tests >
def test_retireArete():
    g = {0: [2], 1: [3], 2: [0,3], 3: [4,1,2], 4: [3]}
    print("Graphe:")
    print(g)
    print("------------------- Test 1 -------------")
    print("On retire l'arrete (1,3)")
    print("Resultat retireArete(g,1,3): ")
    print(retireArete(g,1,3))
    print("------------------- Test 2 -------------")
    print("On retire l'arrete (0,4)")
    print("Resultat retireArete(g,0,4): ")
    print(retireArete(g,0,4))
    print("----------------------------------------")
#-----------------------------------------------------------------------------#




################################################################################
########                                                                ########
########                     Partie 3.2 Théorie                         ########
########                                                                ########
################################################################################

#-----------------------------------[Q 3.10]-----------------------------------<
# Soit G un graphe non-orienté tel que tous ses sommets soit de degré pair avec
# au moins un sommet non nul.
# Lançons un algorithme de promenade suivant depuis ce point:
# Algo(x):
#   y ← un successeur de x
#   Tant que y est de degre pair
#       supprimer arrete (x,y)
#       x ← y
#       y ← un successeur de x
#   Fin Tant que.
#
# Le principe de cet algorithme est le suivant:
# * Un sommet de degree pair a forcément au moins 2 sommets successeurs.
# * A l'origine tous les sommets sont de degree pair
# * Le seul moyen de rencontrer un sommet de degree impair est de retomber
#   sur un sommet déjà rencontré (ie. auquel on a enlevé une arête)
# L'algorithme parcoure donc un chemin quelquonque du graphe jusqu'à sa
# terminaison.
# 
# Démontrer que dans un tel graphe (cf question) il existe toujours un cycle
# revient à faire la preuve de terminaison de cet algorithme.
#
#------------------------------------------------------------------------------#


#-----------------------------------[Q 3.11]-----------------------------------<
# Notons C1 et C2 deux cycle d'un graphe G tel que décrit dans l'énnoncé.
# On note X le sommet commun à ces cycles.
#-------------------| On représente cette configuration sur le shéma ci-contre
#       ¤ C1        | . On veut créer un cycle C correspondant à l'union
#       |           |  des cycles C1 et C2.
#   ¤---+---¤ C2    | On à:
#       |           |   - C1 = (x, s0, ..., sk, x), si € G, k € N+
#       ¤           |   - C2 = (x, t0, ..., tn, x), ti € G, n € N+
#___________________|
# On peut don écrire C= (x, s0, ...,sk, x, t0, ..., tn, x)
# C est bien un cycle car C1 et C2 n'ont pas d'arêtes en commun.
# Il existe donc bien un cycle C, union de C1 et C2.
#-------------------------------------------------------------------------------#



#-----------------------------------[Q 3.12]------------------------------------<
# Soit C un graphe non-orienté, C un cycle de G, et G' le graphe obtenu
# en retirant de G les arêtes de C.
# On veut montrer que si tous les sommets de C sont de degré 0 dans G',
# et si G' a des arêtes, alors G n'est pas connexe.
#   Preuve par l'absurde:
# Supposons que G est connexe, prenons le sommet s n'appartenant pas au cycle C.
# Comme G est connexe, il existe un chemin qui relie s à tous les sommets de C.
# Dans ces chemins il existe donc une arête (ck, x) qui relie un sommet de C
# (ck) avec un sommet en dehors de C (x). L'arête (ck,x) n'appartient donc pas
# au cycle C. L'arête (ck,x) appartient donc à G'.
# Il y a donc un sommet de C (ck) qui est de degré supérieur à 0 dans G'.
# Absurde, G n'est donc pas connexe.
#
#------------------------------------------------------------------------------#




################################################################################
########                                                                ########
########                     Partie 3.3 Pratique                        ########
########                                                                ########
################################################################################

#-----------------------------------[Q 3.13]-----------------------------------<
#Paramètres: G -> un graphe non-orienté dont tous les sommets sont de degré pair
#            s -> un sommet de G de degré non nul
#But: La fonction renvoie un cycle passant par ce sommet
#
def cycle_general(G,s):
    for x in G[s]:
        C = chemin(retireArete(G,s,x), x, s)
        if C :
            return [s] + C
    return None
# La fonction chemin permet de reconstruire un chemin de s à x dans le graphe G
# privé de l'arête (s,x). On lui retire cet arrête car on ne veut pas que la
# fonction retourne directement le chamin (x,s).

## Je crois comprendre qu'il faut utiliser l'algorithme de la question 3.10
def cycle(G,s):
    x = s
    y = G[s][0]
    g = retireArete(G,x,y)
    C = [x,y]
    while y != s:
        x = y
        y = g[y][0]
        g = retireArete(G,x,y)
        C.append(y)
    return C

## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Tests >
def test_cycle():
    print("------------------- Test 1 -------------")
    g = {0: [2,4], 1: [], 2: [0,3], 3: [2,4], 4: [3,0]}
    print("Graphe:")
    print(g)
    print("Ce graphe a un cycle passant par 0")
    print("On s'attend au cycle (0,2,3,4,0)")
    print("Resultat cycle(g,0): ")
    print(cycle(g,0))
    print("------------------- Test 2 -------------")
    print("Même graphe")
    print("1 n'est pas un sommet non nul")
    print("On s'attend à une Erreur")
    print("Resultat cycle(g,1): ")
    try:
        print(cycle(g,1))
    except IndexError:
        print("IndexError")
        pass
    print("------------------- Test 3 -------------")
    g={5:[5]}
    print("Graphe:")
    print(g)
    print("Ce graphe a un cycle passant par 5")
    print("On s'attend au cycle (5,5)")
    print("Resultat cycle(g,5): ")
    print(cycle(g,5))
    print("----------------------------------------")
#------------------------------------------------------------------------------#


#-----------------------------------[Q 3.14]-----------------------------------<
#Paramètres: G -> un graphe non-orienté 
#            S -> un ensemble de sommets
#But: La fonction renvoie un sommet de S de degree non nul dans G
#
def sommetDegreNonNul(G,S):
    for x in S:
        if nb_succ(x,G) :
            return x
    return None
## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Tests >
def test_sommetDegreNonNul():
    g = {0: [], 1: [], 2: [3], 3: [2,4], 4: [3]}
    print("Graphe:")
    print(g)
    print("------------------- Test 1 -------------")
    S = [0,1,2,3,4]
    print("Sommets:")
    print(S)
    print("Parmis ces sommets 2,3 et4 sont non nul")
    print("On s'attend à 2, 3, ou 4")
    print("Resultat sommetDegreNonNul(g,S): ")
    print(sommetDegreNonNul(g,S))
    print("------------------- Test 2 -------------")
    S = [0,1]
    print("Sommets:")
    print(S)
    print("Parmis ces sommets, aucun n'est non nul")
    print("On s'attend à None")
    print("Resultat sommetDegreNonNul(g,S): ")
    print(sommetDegreNonNul(g,S))
    print("----------------------------------------")
#------------------------------------------------------------------------------#


#-----------------------------------[Q 3.15]-----------------------------------<
#Paramètres: listeSommets -> un liste de sommets 
#               x         -> un sommet de cette liste
#But: La fonction renvoie le cycle C (décrit par listeSommets) commençant
#       depuis x.
#
def cycleDepuis(listeSommets,x):
    i = listeSommets.index(x)
    return listeSommets[i:] + listeSommets[1:i+1]
## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Tests >
def test_cycleDepuis():
    print("------------------- Test 1 -------------")
    C = [0,1,2,3,4,5,0]
    print("Cycle:")
    print(C)
    print("On s'attend à [3,4,5,0,1,2,3]")
    print("Resultat cycleDepuis(C,3): ")
    print(cycleDepuis(C,3))
    print("----------------------------------------")
#------------------------------------------------------------------------------#


#-----------------------------------[Q 3.16]-----------------------------------<
#Paramètres:  C1,C2 -> deux cycles (listes de sommets)
#               x   -> un sommet commun au deux cycles
#But: La fonction renvoie La concaténantion des deux cycles.
#
def unionCycle(C1,C2,x):
    return cycleDepuis(C1,x) + cycleDepuis(C2,x)[1:]
## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Tests >
def test_unionCycle():
    print("------------------- Test 1 -------------")
    C1 = [0,1,2,3,4,5,0]
    C2 = [6,7,8,9,5,6]
    print("Cycles:")
    print(C1)
    print(C2)
    print("On s'attend à [5,0,1,2,3,4,5,6,7,8,9,5]")
    print("Resultat unionCycle(C1,C2,5): ")
    print(unionCycle(C1,C2,5))
    print("----------------------------------------")
#------------------------------------------------------------------------------#


#-----------------------------------[Q 3.17]-----------------------------------<
#Paramètres: G -> un graphe non-orienté, non- vide, dont tous les sommets
#                   sont de degrés pair.
#But: La fonction renvoie soit un cycle parcourant la totalité de G,
#       soit une composante de G.
#
def composanteOuCycle(G):
    # Evil hack: On est sûr que ensemble_sommet(G)[0] est égal à
    # set(ensemble_sommet(G)).pop() (utile car on va redéfinir s dans le while)
    s = ensemble_sommet(G)[0]

    C = [s]
    # Evil hack2: On choisit C tel qu'il n'influence pas la première union
    # (entre C et cycle(G,s))    unionCycle(C,N,x) => N
    # ce n'est pas beau mais ça évite d'avoir à recopier du code pour la
    # première boucle
    
    S = set(ensemble_sommet(G))    
    while len(S) != 0:
        s = S.pop()
        
        if nb_succ(s,G)==0:
            return [s]
        
        N = cycle(G,s)

        # cherche un element commun au 2 cycles
        p = set(C).intersection(set(N))
        
        if len(p) == 0:
            return list(set(C))
        
        x = p.pop()
        C = unionCycle(C,N,x)
        
        A = list(set(C)) 
        list(map(S.discard,A))

    return C
## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Tests >
def test_composanteOuCycle():
    print("------------------- Test 1 -------------")
    g = {0: [2,4], 1: [], 2: [0,3], 3: [2,4], 4: [3,0]}
    print("Graphe:")
    print(g)
    print("Le graphe à deux composante")
    print("On s'attend à recevoir une composante")
    print("Resultat composanteOuCycle(g): ")
    print(composanteOuCycle(g))
    print("------------------- Test 1 -------------")
    g = {0: [2,4], 2: [0,3,5,6], 3: [2,4], 4: [3,0], 5: [2,6], 6: [5,2]}
    print("Graphe:")
    print(g)
    print("Le graphe à une composante")
    print("On s'attend à recevoir un cycle")
    print("Resultat composanteOuCycle(g): ")
    print(composanteOuCycle(g))
    print("----------------------------------------")
#------------------------------------------------------------------------------#



################################################################################
########                                                                ########
########             Partie 3.4 Conclusion Théoriques                   ########
########                                                                ########
################################################################################


#-----------------------------------[Q 3.18]-----------------------------------<
# Soit G un graphe non-orienté connexe dont tous les sommets soit de degré pair
#  On veut prouver qu'il existe un cycle eulérien.
# 1 - Comme le graphe est connexe, tous les sommets sont de degré supérieur à 0
# 2 - On a prouvé à la question 10 que tout graphe dont les sommets sont de
#   degré pair et ayant au moins un sommet non nul contient un cycle.
# Donc il existe un cycle C dans G.
# 3 - On a prouvé à la question 12, que si un graphe est privé des arrêtes
#   d'un de ses cycles et que les sommets de ce cycle sont ainsi de degré 0,
#   alors le graphe est connexe. Par contraposé, Si un graphe est connexe
#   et, une fois les arêtes d'un de ses cycles retirées, les sommets de ce
#   cycle sont de degré 0, alors il n'y a pas d'autres arêtes en dehors
#   du cycle dans ce graphe.
# Donc on peut faire un nouveau graphe G' correspondant à G privé des arêtes
# de C.
#On distingue maintenant deux cas:
# a) tous les sommets de C sont de degré 0,
#   donc il n'y a pas d'autres arêtes
#   donc C est un cycle eulérien
# b) certains sommets de C sont de degré supérieur ou égal à 2
#   d'après le point 2 on peut construire un cycle dans G', on le note C2
#   C et C2 auront au minimum un sommet en commun,
#   on sait aussi que C et C2 ont des ensembles d'arrêtes disjoints
#   Donc d'après la question 3.11, on peut créer un cycle dont l'ensemble
#   d'arêtes est précisément l'union des ensembles d'arrêtes de C et C2
#   On note ce cycle C'
#   On peut donc réaliser l'opération précédente (priver G des arrêtes de C')
#   Et répéter ces opérations jusqu'à ce retrouver dans le cas a)
#
# Dans tous les cas on se retrouvera bien dans un cas ou C est un cycle eulérien
#
#[Pour être complet il faudrait faire la preuve de terminaison de l'algorithme.]
#------------------------------------------------------------------------------#



#-----------------------------------[Q 3.19]-----------------------------------<
# Soit G un graphe eulérien.
# On veut démontrer que si on retire les sommets isolés de G, on obtient
# un graphe connexe dont tous les sommets sont de degré pairs.
#
# -- Prouver que tous les sommets d'un cycle eulérien sont de degré pairs:
# Par définition des cycles, un cycle est toujours une partie connexe et
# tous ses sommets sont de degré pair(en se restregnant au sous-graphe induit
# par les sommets du cycle).
# Comme le sous-graphe induit par les sommets du cycle eulérien est égal au
# graphe privé de ses sommets isolés, donc le cycle eulérien à bien tout ces
# élément de degré pairs.
# 
#
# -- Prouver que le cycle eulérien est une partie connexe:
# 1) Tous les sommets du cycle appartiennent à la même partie connexe
# 2) Comme le cycle est eulérien, on est sûr que "uniquement" les sommets
#    appartenant au cycle font partie de la partie connexe associé au cycle
# 3) Comme le cycle est eulérien, les autres parties connexes sont uniquement
#   constitué de sommet isolés (car toutes les arrêtes du graphes appartiennent
#   au cycle eulérien)
# 
#
#------------------------------------------------------------------------------#




















