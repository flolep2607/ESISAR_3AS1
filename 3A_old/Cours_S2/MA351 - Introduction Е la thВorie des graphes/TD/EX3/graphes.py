"""Exemples de graphes"""

"Generateur de graphe oriente"
def graphe_oriente(n, k):
  d = {}
  for i in range(0, n):
    d[i] = list()
    for j in range(0, n):
      if ((i + j)^2) % (i % k + k) == 0 and i != j:
        d[i].append(j)
  return d

"Generateur de graphe non-oriente"
def graphe_non_oriente(n, k):
  d = {}
  for i in range(0, n):
    d[i] = list()
  for i in range(0, n):
    for j in range(0, i):
      if ((i + j)^2) % (i % k + k) == 0 and i != j:
        d[i].append(j)
        d[j].append(i)
  return d

"Une fonction longueur sur les arcs"
def longueur(x, y):
  return x^3 + (x + 2*y -1) ^2

