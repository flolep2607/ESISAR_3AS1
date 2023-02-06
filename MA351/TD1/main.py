from graphes import *
g=graphe_oriente(100,10)
g
#1) sous forme de tableau sommet:[liste de successeurs ]
#1.1) successeurs de 0 : [2, 8, 22, 28, 42, 48, 62, 68, 82, 88]
#1.2) successeurs de 67: [3, 20, 33, 50, 71, 88]
#2)
def degres(graph:dict,sommet:int):
    return len(graph[sommet])

def test_degres():
    test_graph=graphe_oriente(2,3)
    assert degres(test_graph,0)==1
    assert degres(test_graph,1)==0
    test_graph=graphe_oriente(8,3)
    assert degres(test_graph,0)==3
    assert degres(test_graph,1)==1
#3)
def sommets(graph:dict):
    return list(graph.keys())

def test_sommets():
    test_graph=graphe_oriente(2,3)
    assert len(sommets(test_graph))==2
    test_graph=graphe_oriente(8,3)
    assert len(sommets(test_graph))==8

#4)
def arcs(graph:dict):
    for start,ends in graph.items():
        for end in ends:
            yield (start,end)


#si besoin d'une liste et non d'un iterateur
def list_arcs(graph:dict):
    liste=[]
    for start,ends in graph.items():
        for end in ends:
            liste.append((start,end))
    return liste

def test_arcs():
    test_graph=graphe_oriente(2,3)
    assert len(list_arcs(test_graph))==1
    test_graph=graphe_oriente(8,3)
    assert len(list_arcs(test_graph))==15

#5
def describe(graph:dict):
    return (len(sommets(graph)),len(arcs(graph)))

def test_describe():
    test_graph=graphe_oriente(2,3)
    assert describe(test_graph)==(2, 1)
    test_graph=graphe_oriente(8,3)
    assert describe(test_graph)==(8, 15)
#6
def mirroir(graph:dict):
    mirror_edge={key:[] for key in graph.keys()}
    for start,ends in graph.items():
        for end in ends:
            mirror_edge[end].append(start)
    return mirror_edge

def test_mirroir():
    test_graph=graphe_oriente(100,30)
    assert mirroir(mirroir(test_graph))==test_graph
#7
def degres_entrant_sommet(graph:dict,sommet:int):
    return sum([1 if sommet in predecesseurs else 0 for predecesseurs in graph.values()])
    # return len(mirror(graph)[somment])

def test_degres_entrant_sommet():
    test_graph=graphe_oriente(10,2)
    assert degres_entrant_sommet(test_graph,0)==5
#8
def sous_graph(graph:dict,sommets:list[int]):
    sous_graph_tmp={key:[] for key in graph.keys() if key in sommets}
    for start,ends in graph.items():
        if start in sommets:
            for end in ends:
                if end in sommets:
                    sous_graph_tmp[start].append(end)
    return sous_graph_tmp

def test_sous_graph():
    test_graph=graphe_oriente(10,2)
    assert sous_graph(test_graph,[0,1])=={0: [], 1: [0]}

