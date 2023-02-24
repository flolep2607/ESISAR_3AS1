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


################################
####  ~~~  Partie 2.2  ~~~  ####
################################

## [ Q1 ] ----------------------<
# g = graphe_oriente(100,10)
# g : Graphe
##  print(g[0])
##  print(g[67])
#-------------------------------#


## [ Q2 ] ----
def nb_succ(x, g):
 
    return len(g[x])
### Usage:
# Deg_in0 = nb_succ(0,g)
# Deg_in0 : int                 #   
#-------------------------------#
def _Test_nb_succ():
    result = nb_succ(0,graphe_oriente(10,10)) == 2
    result = result and (nb_succ(0,graphe_oriente(100,10)) == 2) == False
    return result

## [ Q3 ] ----------------------<

def ensemble_sommet(g):
    
    return g.keys()             # Equivalent à "list(g)"
### Usage:
# S = ensemble_sommet(g)
# S: liste d'entiers            #   
#-------------------------------#
def _Test_ensemble_sommet():
    result = (ensemble_sommet(graphe_oriente(10,10)) == [2,8])
    result = result and (ensemble_sommet(graphe_oriente(10,10)) == []) == False

## [ Q4 ] ----------------------<
def ensemble_arc(g):
    
    E=[]
    for i in list(g):
        for succ in g[i]:
            E.append((i,succ))

    return E
### Usage:
# A = ensemble_arc(g)
# A : liste de couples d'entiers#        
#-------------------------------#

## [ Q5 ] ----------------------<
def nb_sommarc(g):
    
    return (len(ensemble_sommet(g)),len(ensemble_arc(g)))
### Usage:
# C = nb_sommarc(g)
# C : couple d'entier           #
#-------------------------------#

## [ Q6 ] ----------------------<
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
#-------------------------------#

## [ Q7 ] ----------------------<
def nb_pred(x,g):
    
    return nb_succ(x,mirroir(g))
### Usage:
# Deg_out0 = nb_pred(0,g)
# Deg_out0 : int                #  
#-------------------------------#

## [ Q8 ] ----------------------<
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
#-------------------------------#

################################
####  ~~~  Partie 2.3  ~~~  ####
################################

def Accessibles1(g,x):
    
    M=[x]
    
    for y in g[x]:
        R = Accessibles1(g,y)
        M = M + R
        M = list(set(M))
    return M

#-----------------------------------#

def Appel_accessibles2(g,x):
    return Accessibles2(g,x,[x])

def Accessibles2(g,x,M):
    for y in g[x]:
        if not y in M:
            M = M + [y]
            M = Accessibles2(g,y,M)
    return M

#-----------------------------------#

def Appel_accessibles3(g,x):
    return Accessibles3(g,x,[x],{})

def Accessibles3(g,x,M,o):
    for y in g[x]:
        if not y in M:
            M = M + [y]
            o[y] = x
            (M,o) = Accessibles3(g,y,M,o)
    return (M,o)

#-----------------------------------#
    
def Reconstruire_chemin(s,z,o):
    if z != s:
#   vérification si o[z] est possible (robustesse)
        if z in o.keys():
            return Reconstruire_chemin(s, o[z], o) + [z]
        else:
            return [-1]
    else:
        return [s]

#-----------------------------------#
        
def Accessible(g, s, t):
    C = Reconstruire_chemin(s,t,Appel_accessibles3(g,s)[1])
    if C[0] == -1:
        return None
    else:
        return C

#-----------------------------------#

def Verifier_chemin(g, s, t,C):
    Verif = C[0]==s and C[-1]==t
    for i in range(len(C)-1):
        if not C[i+1] in g[C[i]]:
            Verif = False
    return Verif
        


def Verifier_chemin_mieux(g,s,t,C):
    return C[0]==s and C[-1]==t and not False in list(map(lambda x: x in ensemble_arc(g),list(sliding_window(C,2))))




def Test():
    Result = True
    
    
    return Result













