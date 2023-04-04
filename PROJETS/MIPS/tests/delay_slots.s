# Rappel sur les delay slots:
# - Pour des raisons d'optimisation, durant un saut l'instruction après le saut
#   (le "delay slot") est exécutée à la volée.
# - L'exécution doit se faire dans cet ordre:
#   1. En arrivant sur l'instruction de saut, calcul de la destination du saut
#      et de la condition si le saut est conditionnel.
#   2a. Si le saut se fait:
#       3a. Exécution du delay slot
#       4a. Poursuite de l'exécution à la cible du saut
#   2b. Si le saut ne se fait pas:
#       3b. Exécution du delay slot
#       4b. Poursuite de l'exécution à l'instruction qui suit le delay slot

# D'abord on fait un test où le saut ne se fait pas.
ADDI $1, $0, 12
BEQ $1, $0, 2        # On saute PAS 2 instructions (la cible est le prochain BEQ)
ADDI $2, $0, 16	     # Toujours exécutée (delay slot)
ADDI $1, $1, 4       # Exécutée parce qu'on n'a pas sauté

# Ensuite un test où le saut se fait.
BEQ $1, $2, 3
ADDI $3, $0, 6       # Toujours exécutée (delay slot)
ADDI $1, $1, 1000    # Pas exécutée parce qu'on a sauté
ADDI $2, $2, 1000    # Pas exécutée parce qu'on a sauté

# Ici la branche n'est pas prise parce que $1 et $3 sont différents. Mais pour
# le voir il faut calculer la condition avant d'exécuter le delay slot.
BEQ $1, $3, 2
ADDI $3, $3, 10      # Exécutée (delay slot) après que BEQ ait vu que $1 != $3
ADDI $3, $3, 2       # Exécutée parce qu'on n'a pas sauté

# De même, cette branche est prise si vous calculez correctement la condition
# (ie. avant le delay slot).
SUB $4, $1, $3       # $4 = 16 - 18 = -2
BLEZ $4, 2
ADDI $1, $1, 4       # Toujours exécutée (delay slot)
ADDI $4, $4, 1000    # Pas exécutée parce qu'on a sauté

# Cas intéressant pour finir : si on prend un saut de longueur 0, on exécute le
# delay slot deux fois (mais si on ne le prend pas on ne l'exécute qu'une fois)
BEQ $0, $0, 0
ADDI $5, $5, 1       # Exécuté deux fois ! (1: delay slot, 2: après le saut)

BNE $0, $0, 0
ADDI $6, $6, 1       # Exécuté une seule fois (delay slot)

ADDI $2, $2, 8

# EXPECTED_ASSEMBLY
# 2001000C
# 10200002
# 20020010
# 20210004
# 10220003
# 20030006
# 202103E8
# 204203E8
# 10230002
# 2063000A
# 20630002
# 00232022
# 18800002
# 20210004
# 208403E8
# 10000000
# 20A50001
# 14000000
# 20C60001
# 20420008

# EXPECTED_FINAL_STATE
# $01:20
# $02:24
# $03:18
# $04:-2
# $05:2
# $06:1