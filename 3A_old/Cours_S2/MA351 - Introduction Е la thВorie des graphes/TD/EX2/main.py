from graphes import *

#------------------------------------------#
# Import from TD1

def nb_succ(x, g):
    return len(g[x])

def ensemble_sommet(g):
    return list(g.keys())

def ensemble_arc(g):
    E=[]
    for i in list(g):
        for succ in g[i]:
            E.append((i,succ))
    return E

def mirroir(g):
    m={}
    for sommet in ensemble_sommet(g):
        m[sommet]=[]
    for arc in ensemble_arc(g):
        m[arc[1]].append(arc[0])
    return m

def sous_graphe(S,g):
    s={}
    for i in g.keys():
        if i in S:
            s[i]=[]
            for elem in list(g[i]):
                if elem in S:
                    s[i].append(elem)
    return s

#------------------------------------------#

def ensemble_puits(g):
    l = []
    for x in g.keys():
        if len(g[x]) == 0:
            l.append(x)
    return l

def ensemble_sources(g):
    return ensemble_puits(mirroir(g))

#------------------------------------------#

################################
####  ~~~  Partie 2.1  ~~~  ####
################################

## [ Q1 ] ----------------------<
def Trouve_Puits(g,s):
    while(nb_succ(s,g)!=0):
        s = g[s][0]
        #s = random.choice(g[s])
    return s
# Tests    ---------------------#
#-------------------------------#

## [ Q2 ] ----------------------<
# L'algorithme de trouver puit
# s'arrête uniquement lorsqu'il
# trouve un puit ( |N+(s)| = 0 ).
#
# Or notre algorithme s'applique
# uniquement à un graphe sans circuit.
# Ce type de graphe contient 
# forcément des puits. En effet
# dans ce type de graphe, au
# moins une source et un puit
# est accessible de chaque sommet.
#-------------------------------#

## [ Q3 ] ----------------------<
# Non un circuit ne peut pas 
# passer par un puit. On ne peut
# pas construire d'arc à partir
# d'un puit, or un circuit est
# un chemin qui retourne à son 
# sommet d'origine, ce qui est
# donc incompatible avec la
# définition du puit.
#-------------------------------#

######################################
####    ~~~   Partie 2.2   ~~~    ####
######################################

## [ Q4 ] ---------------------------<
# g_ex = { A:[B,C], B:[], C:[B,D], D:[B]}
# tri_topologique(g_ex) = { A:1, B:4, C:2, D:3}
#------------------------------------#
    
## [ Q5 ] ---------------------------<
# Fait sur papier
#------------------------------------#
    
## [ Q6 ] ---------------------------<
# Fait sur papier
#------------------------------------#
    
############################################
####      ~~~    Partie 2.3    ~~~      ####
############################################
    
## [ Q7 ] ---------------------------------<
#Tri topologique d'un graphe sans circuit.
#Pas la bonne méthode
def Tri_topo_sans_circuit_par_sources(g):
    sources = ensemble_sources(g)
    phi = dict()
    for s in sources:
        phi = Aux(g,s,0,phi)
    return phi
    
def Aux(g,s,n,phi):
    if not ((s in phi) and (phi[s] > n)):
            phi[s] = n+1
    
    for x in g[s]:
        phi = Aux(g,x,n+1,phi)
        
    return phi

def Aux2(g,s,n,phi):
    if not(s in phi):
            phi[s] = n+1
    elif (phi[s] >= n):
        return phi
    
    for x in g[s]:
        phi = Aux(g,x,n+1,phi)
        
    return phi
#------------------------------------------#
# Tests
g = {0: [2, 8], 1: [8], 2: [3], 3: [], 4: [5], 5: [8], 6: [], 7: [], 8: [], 9: [8]}
# resultat:{0: 1, 2: 2, 3: 3, 8: 3, 1: 1, 4: 1, 5: 2, 6: 1, 7: 1, 9: 1}
g = {0: [3], 1: [3,4], 2: [4], 3:[5,6], 4:[7], 5:[], 6:[4], 7:[] }
# resultat:{0: 1, 3: 2, 5: 3, 6: 3, 4: 4, 7: 5, 1: 1, 2: 1}
#-------------------------------------------#

## [ Q7 ] ----------------------------------<
#Tri topologique d'un graphe sans circuit.
def Tri_topo_sans_circuit(g):
    return Tri_topo_sans_circuit_par_puits(g)[0]

def Tri_topo_sans_circuit_par_puits(g):
    if len(g)==0:
        phi=dict()
        n=0
    else:
        puits = ensemble_puits(g)
        S = ensemble_sommet(g)
        #priver S des puits
        list(map(S.remove,puits))
        #map ne modifie S que si on fait list()
        sg = sous_graphe(S,g)
        (phi,n) = Tri_topo_sans_circuit_par_puits(sg)
        #phi[puits] = n
        for x in puits:
            phi[x]=n
    return (phi,n+1)
# Tests    ---------------------------------#
def Tri_topo_sans_circuit_test():
    g = {0: [3], 1: [3,4], 2: [4], 3:[5,6], 4:[7], 5:[], 6:[4], 7:[] }
    print("resultat:")
    print(Tri_topo_sans_circuit(g))
    print("Attendu")
    print("{0: 1, 1: 1, 3: 2, 2: 3, 6: 3, 4: 4, 5: 5, 7: 5}")
#-------------------------------------------#
    
## [ Q8 ] ----------------------------------<
# Hypothèse: On peut reconstruire n'importe
# quel graphe (sans circuit) à partir du 
# graphe vide simplement en rajoutant des puits
# 
# Soit un graphe G, orienté, sans circuit
# D'après la question 6, si on a un graphe
# trié, on peut le maintenir trié quand on 
# rajoute des puits. Or d'après l'hypothèse
# ci-dessus on peut reconstruire G à partir
# du graphe vide, et comme le graphe vide
# est trié, alors G est trié.
#-------------------------------------------#
    
    
## [ Q10 ] ---------------------------------<
#Renvoie soit un circuit, soit un puit
def Circuit_ou_Puits(g,x):
    chemin=[]
    s=x
    while(nb_succ(s,g)!=0 and not s in chemin):
        chemin.append(s)
        s = g[s][0]
    if(s in chemin):
        chemin.append(s)
        i = chemin.index(s)
        return chemin[i:]
    else:
        return [s]
# Tests    ---------------------------------#
def Circuit_ou_Puits_test():
    g = {0: [3], 1: [3,4], 2: [4], 3:[5,6], 4:[7], 5:[], 6:[4], 7:[] }
    print("g:")
    print(g)    
    print("resultat pour (g,0):")
    print(Circuit_ou_Puits(g,0))
    print("Attendu")
    print("[5]")
    g = graphe_oriente(10,10)
    print("g:")
    print(g)    
    print("resultat pour (g,0):")
    print(Circuit_ou_Puits(g,0))
    print("Attendu")
    print("[0, 2, 0]")
#-------------------------------------------#


## [ Q11 ] ---------------------------------<
#Renvoie soit un circuit soit un tri topologique
def Circuit_ou_Tri_topologique(g):
    for x in g.keys():
        C = Circuit_ou_Puits(g,x)
        if(len(C)>1):
            return C
    return Tri_topo_sans_circuit(g)
# Tests    ---------------------------------#
#-------------------------------------------#

## [ Q12 ] ---------------------------------<
#Soit un graphe orienté G
#Si G à un ou plus circuit:
#    Alors G à au moins un circuit
#    (et donc il n'a pas de tri topologique)
#Si G n'à pas de circuit:
#    Alors on a prouvé à la question 8
#    qu'un graphe orienté sans circuit
#    possède un tri topologique
#
#-------------------------------------------#

## [ Q13 ] ---------------------------------<
#
#-------------------------------------------#