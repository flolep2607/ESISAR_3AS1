from graphes import *





################################
####  ~~~  Partie 2.2  ~~~  ####
################################

## [ Q1 ] -------------------------------------------------<
# g = graphe_oriente(100,10)
# g : Graphe
##  print(g[0])
##  print(g[67])
#----------------------------------------------------------#


############################################################
## [ Q2 ] -------------------------------------------------<
def nb_succ(x, g):
    
    return len(g[x])
### Usage:
# Deg_in0 = nb_succ(0,g)
# Deg_in0 : int 
## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Tests >
def test_nb_succ():
    g = {0: [2], 1: [], 2: [3,4,0], 3: [4], 4: []}
    print("Graphe:")
    print(g)
    print("Le sommet 1 a 0 successeurs")
    print("Resultat nb_succ(1,g): ")
    print(nb_succ(1,g))
    print("Le sommet 2 a 3 successeurs")
    print("Resultat nb_succ(2,g): ")
    print(nb_succ(2,g))
#----------------------------------------------------------#


############################################################
## [ Q3 ] -------------------------------------------------<
def ensemble_sommet(g):
    
    return list(g.keys())             # Equivalent à "list(g)"
### Usage:
# S = ensemble_sommet(g)
# S: liste d'entiers            #   
## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Tests >
def test_ensemble_sommet():
    g = {0: [2], 1: [], 2: [0]}
    print("Graphe:")
    print(g)
    print("Les sommets sont [0, 1, 2]")
    print("Resultat ensemble_sommet(g): ")
    print(ensemble_sommet(g))
    g = {}
    print("Graphe:")
    print(g)
    print("Le graphe n'a pas de sommet")
    print("Resultat ensemble_sommet(g): ")
    print(ensemble_sommet(g))
#----------------------------------------------------------#


############################################################
## [ Q4 ] -------------------------------------------------<
def ensemble_arc(g):
    
    E=[]
    for i in list(g):
        for succ in g[i]:
            E.append((i,succ))

    return E
### Usage:
# A = ensemble_arc(g)
# A : liste de couples d'entiers#
## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Tests >
def test_ensemble_arc():
    g = {0: [2], 1: [], 2: [3], 3: [4], 4: []}
    print("Graphe:")
    print(g)
    print("Les arcs sont [(0,2),(2,3),(3,4)]")
    print("Resultat ensemble_arc(g): ")
    print(ensemble_arc(g))
    g = {0: [], 1: [], 2: [], 3: [], 4: []}
    print("Graphe:")
    print(g)
    print("Ce graphe n'a pas d'arc")
    print("Resultat ensemble_arc(g): ")
    print(ensemble_arc(g))
#----------------------------------------------------------#


############################################################
## [ Q5 ] -------------------------------------------------<
def nb_sommarc(g):
    
    return (len(ensemble_sommet(g)),len(ensemble_arc(g)))
### Usage:
# C = nb_sommarc(g)
# C : couple d'entier           #
## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Tests >
def test_nb_sommarc():
    g = {0: [2], 1: [], 2: [3], 3: [4], 4: []}
    print("Graphe:")
    print(g)
    print("Ce graphe a 5 sommets et 3 arcs")
    print("Resultat nb_sommarc(g): ")
    print(nb_sommarc(g))
    g = {}
    print("Graphe:")
    print(g)
    print("Ce graphe n'a ni sommets ni arcs")
    print("Resultat nb_sommarc(g): ")
    print(nb_sommarc(g))
#----------------------------------------------------------#


############################################################
## [ Q6 ] -------------------------------------------------<
def mirroir(g):
    
    m={}
    for sommet in ensemble_sommet(g):
        m[sommet]=[]
    for arc in ensemble_arc(g):
        m[arc[1]].append(arc[0])
    
    return m
### Usage:
# M = mirroir(g)
# M : Graphe
## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Tests >
def test_mirroir():
    g = {0: [1], 1: [2], 2: [0], 3: [4], 4: []}
    print("Graphe:")
    print(g)
    print("Resultat mirroir(g): ")
    print(mirroir(g))
    g = {}
    print("Graphe:")
    print(g)
    print("Resultat mirroir(g): ")
    print(mirroir(g))
#----------------------------------------------------------#


############################################################
## [ Q7 ] -------------------------------------------------<
def nb_pred(x,g):
    
    return nb_succ(x,mirroir(g))
### Usage:
# Deg_out0 = nb_pred(0,g)
# Deg_out0 : int
## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Tests >
def test_nb_pred():
    g = {0: [2], 1: [], 2: [3,4,0], 3: [4], 4: []}
    print("Graphe:")
    print(g)
    print("Le sommet 1 à 0 prédécesseurs")
    print("Resultat nb_pred(1,g): ")
    print(nb_pred(1,g))
    print("Le sommet 2 à 1 prédécesseurs")
    print("Resultat nb_pred(2,g): ")
    print(nb_pred(2,g))
#----------------------------------------------------------#


############################################################
## [ Q8 ] -------------------------------------------------<
def sous_graphe(S,g):
    
    s={}
    for i in g.keys():
        if i in S:
            s[i]=[]
            for elem in list(g[i]):
                if elem in S:
                    s[i].append(elem)
    
    return s
### Usage:
# s = sous_graphe([i for i in range (10)],g)
# s : Graphe
## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Tests >
def test_sous_graphe():
    g = {0: [2], 1: [], 2: [3,4,0], 3: [4], 4: []}
    print("Graphe:")
    print(g)
    print("Sous graphe induit par [0,1,2]")
    print("Resultat sous_graphe([0,1,2],g): ")
    print(sous_graphe([0,1,2],g))
    print("Sous graphe induit par []")
    print("Resultat sous_graphe([],g): ")
    print(sous_graphe([],g))
#----------------------------------------------------------#


############# ################################ #############
############# ####  ~~~  Partie 2.3  ~~~  #### #############
############# ################################ #############

## [ Q1 ] -------------------------------------------------<
def Accessibles1(g,x):
    
    M=[x]
    
    for y in g[x]:
        R = Accessibles1(g,y)
        M = M + R
        M = list(set(M))
    return M
## [ Q2 ] ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Tests >
def test_Accessibles1():
    g = {0: [2], 1: [], 2: [1], 3: []}
    print("Graphe:")
    print(g)
    print("Les sommets accessibles de 0 sont [0,1,2]")
    print("Resultat Accessibles1(g,0): ")
    print(Accessibles1(g,0))
    g = {0: [2], 1: [1], 2: [1], 3: []}
    print("Graphe:")
    print(g)
    print("Les sommets accessibles de 0 sont [0,1,2]")
    print("Mais il y a une boucle dans le graphe")
    print("Resultat Accessibles1([],g): ")
    try:
        print(Accessibles1(g,0))
    except RecursionError:
        print("RecursionError")
        pass
#----------------------------------------------------------#


############################################################
## [ Q3 ] -------------------------------------------------<
def Appel_accessibles2(g,x):
    return Accessibles2(g,x,[x])

def Accessibles2(g,x,M):
    for y in g[x]:
        if not y in M:
            M = M + [y]
            M = Accessibles2(g,y,M)
    return M
## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Tests >
def test_Accessibles2():
    g = {0: [2], 1: [], 2: [1], 3: []}
    print("Graphe:")
    print(g)
    print("Les sommets accessibles de 0 sont [0,1,2]")
    print("Resultat Appel_accessibles2(g,0): ")
    print(Appel_accessibles2(g,0))
    g = {0: [2], 1: [1], 2: [1], 3: []}
    print("Graphe:")
    print(g)
    print("Les sommets accessibles de 0 sont [0,1,2]")
    print("Mais il y a une boucle dans le graphe")
    print("Resultat Appel_accessibles2([],g): ")
    try:
        print(Appel_accessibles2(g,0))
    except RecursionError:
        print("RecursionError")
        pass
#----------------------------------------------------------#


############################################################
## [ Q4 ] -------------------------------------------------<
def Appel_accessibles3(g,x):
    return Accessibles3(g,x,[x],{})

def Accessibles3(g,x,M,o):
    for y in g[x]:
        if not y in M:
            M = M + [y]
            o[y] = x
            (M,o) = Accessibles3(g,y,M,o)
    return (M,o)
## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Tests >
def test_Accessibles3():
    g = {0: [2], 1: [], 2: [1], 3: []}
    print("Graphe:")
    print(g)
    print("Les sommets accessibles de 0 sont [0,1,2]")
    print("Resultat Appel_accessibles3(g,0): ")
    print(Appel_accessibles3(g,0))
    g = {0: [2], 1: [1], 2: [1], 3: []}
    print("Graphe:")
    print(g)
    print("Les sommets accessibles de 0 sont [0,1,2]")
    print("Mais il y a une boucle dans le graphe")
    print("Resultat Appel_accessibles2([],g): ")
    print(Appel_accessibles3(g,0))
#----------------------------------------------------------#


############################################################
## [ Q5 ] -------------------------------------------------<
def Reconstruire_chemin(s,z,o):
    if z != s:
#   vérification si o[z] est possible (robustesse)
        if z in o.keys():
            return Reconstruire_chemin(s, o[z], o) + [z]
        else:
            return [-1]
    else:
        return [s]
## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Tests >
def test_Reconstruire_chemin():
    g = {0: [2], 1: [1], 2: [3,1], 3: []}
    M=[]
    o={}
    (M,o) = Appel_accessibles3(g,0)
    print("Graphe:")
    print(g)
    print("Le chemin de 0 à 1 est (0,2,1)")
    print("Resultat Reconstruire_chemin(0,1,o): ")
    print(Reconstruire_chemin(0,1,o))
#----------------------------------------------------------#


############################################################
## [ Q6 ] -------------------------------------------------<
def Accessible(g, s, t):
    C = Reconstruire_chemin(s,t,Appel_accessibles3(g,s)[1])
    if C[0] == -1:
        return None
    else:
        return C
## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Tests >
def test_Reconstruire_chemin():
    g = {0: [2], 1: [1], 2: [3,1], 3: []}
    M=[]
    o={}
    (M,o) = Appel_accessibles3(g,0)
    print("Graphe:")
    print(g)
    print("Le chemin de 0 à 1 est (0,2,1)")
    print("Resultat Reconstruire_chemin(0,1,o): ")
    print(Reconstruire_chemin(0,1,o))
#----------------------------------------------------------#


############################################################
## [ Q6 ] -------------------------------------------------<
def Verifier_chemin(g, s, t,C):
    Verif = C[0]==s and C[-1]==t
    for i in range(len(C)-1):
        if not C[i+1] in g[C[i]]:
            Verif = False
    return Verif
## ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Tests >
def test_Verifier_chemin():
    g = {0: [2], 1: [1], 2: [3,1], 3: []}
    M=[]
    o={}
    (M,o) = Appel_accessibles3(g,0)
    C = Reconstruire_chemin(0,1,o)
    print("Graphe:")
    print(g)
    print("Chemin:")
    print(C)
    print("On s'attends à ce que le chamin soit valide")
    print("Resultat Verifier_chemin(g,0,1,C): ")
    print(Verifier_chemin(g,0,1,C))  
#----------------------------------------------------------#





## [ Bonus ] ----------------------------------------------<

# from more_itertools import sliding_window
import collections
from itertools import islice
# sliding_window('ABCDEFG', 4) -> ABCD BCDE CDEF DEFG
def sliding_window(iterable, n):
    it = iter(iterable)
    window = collections.deque(islice(it, n), maxlen=n)
    if len(window) == n:
        yield tuple(window)
    for x in it:
        window.append(x)
        yield tuple(window)

        
def Verifier_chemin_mieux(g,s,t,C):
    return C[0]==s and C[-1]==t and not False in list(map(lambda x: x in ensemble_arc(g),list(sliding_window(C,2))))















