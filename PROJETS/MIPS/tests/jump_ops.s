# Tests des sauts conditionnels. Il n'y a pas grand-chose de subtil ici car les
# delay slots sont tous NOP, donc vous obtiendrez le bon résultat même si vous
# ne gérez pas le delay slots correctement. Ici le but c'est juste de vérifier
# que vous sautez au bon endroit et quand il faut.

ADDI $1, $0, 32 #1

# Saut à l'instruction #4 du programme (comptée à partir du début, en
# commençant à #0), c'est-à-dire le JAL
J 4 #2
NOP                  # Delay slot 3
ADDI $10, $0, 1000   # Pas exécutée car on a sauté 4

# Saut à l'instruction #8 (le BEQ) ; de plus, $31 <- PC+8 = 16+8 = 24
JAL 8 #5
NOP                  # Delay slot 6
ADDI $11, $0, 1000   # Pas exécutée car on a sauté 7
ADDI $12, $0, 1000   # Pas exécutée car on a sauté 8

# On saute par-dessus 2 instructions car $0 = $0
BEQ $0, $0, 2 #9
NOP                  # Delay slot 10
ADDI $13, $0, 1000   # Pas exécutée car on a sauté 11

# On essaie de sauter 2 instructions, mais $1 = 32 != $0; donc on ne saute pas
BEQ $1, $0, 2 #12
NOP                  # Delay slot 13
ADDI $1, $1, -16     # Exécutée car on n'a pas sauté 14

# On saute car $1 > 0
BGTZ $1, 2 #15
NOP        #16
ADDI $14, $0, 1000 #17

# On ne saute pas car $1 n'est pas <= 0
BLEZ $1, 3 #18
NOP        #19
NOP        #20
ADDI $2, $0, -4 #21

# On ne saute pas car $0 n'est pas > 0
BGTZ $0, 2 #22
NOP #23
ADDI $2, $2, -4 #24

# On saute car $0 <= 0
BLEZ $0, 3 #25
NOP #26
ADDI $15, $0, 1000 #27
ADDI $16, $0, 1000 #28

# On ne saute pas car $2 = -8 n'est pas > 0
BGTZ $2, 2 #29
NOP #30
ADDI $2, $2, -4 #31

# On saute car $2 = -12 est <= 0
BLEZ $2, 2 #32
NOP #33
ADDI $17, $0, 1000 #34

# On saute car $1 != $2
BNE $1, $2, 3 #35
NOP #36
ADDI $18, $0, 1000 #37
ADDI $19, $0, 1000 #38

# On ne saute pas car $2 n'est pas != $2
BNE $2, $2, 2 #39
NOP #40
ADD $3, $1, $2 #41

# Saut de 0 instructions
BEQ $0, $0, 0 #42
NOP #43


# 20010020#ADDI $1, $0, 32
# 08000004#J 4
# 00000000#NOP
# 200A03E8#ADDI
# 0C000008#JAL 8
# 00000000#NOP               
# 200B03E8#ADDI $11, $0, 1000
# 200C03E8#ADDI $12, $0, 1000
# 10000002#BEQ $0, $0, 2
# 00000000#NOP                  # Delay slot
# 200D03E8#ADDI $13, $0, 1000   # Pas exécutée car on a sauté
# 10200002#BEQ $1, $0, 2
# 00000000#NOP                  # Delay slot
# 2021FFF0#ADDI $1, $1, -16     # Exécutée car on n'a pas sauté
# 1C200002#BGTZ $1, 2
# 00000000#NOP
# 200E03E8#ADDI $14, $0, 1000
# 18200003#BLEZ $1, 3
# 00000000#NOP
# 00000000#NOP
# 2002FFFC#ADDI $2, $0, -4
# 1C000002#BGTZ $0, 2
# 00000000#NOP
# 2042FFFC#ADDI $2, $2, -4
# 18000003#BLEZ $0, 3
# 00000000#NOP
# 200F03E8#ADDI $15, $0, 1000
# 201003E8#ADDI $16, $0, 1000
# 1C400002#BGTZ $2, 2
# 00000000#NOP
# 2042FFFC#ADDI $2, $2, -4
# 18400002#BLEZ $2, 2
# 00000000#NOP
# 201103E8#ADDI $17, $0, 1000
# 14220003#BNE $1, $2, 3
# 00000000#NOP
# 201203E8#ADDI $18, $0, 1000
# 201303E8#ADDI $19, $0, 1000
# 14420002#BNE $2, $2, 2
# 00000000#NOP
# 00221820#ADD $3, $1, $2
# 10000000#BEQ $0, $0, 0
# 00000000#NOP
# EXPECTED_ASSEMBLY
# 20010020
# 08000004
# 00000000
# 200A03E8
# 0C000008
# 00000000
# 200B03E8
# 200C03E8
# 10000002
# 00000000
# 200D03E8
# 10200002
# 00000000
# 2021FFF0
# 1C200002
# 00000000
# 200E03E8
# 18200003
# 00000000
# 00000000
# 2002FFFC
# 1C000002
# 00000000
# 2042FFFC
# 18000003
# 00000000
# 200F03E8
# 201003E8
# 1C400002
# 00000000
# 2042FFFC
# 18400002
# 00000000
# 201103E8
# 14220003
# 00000000
# 201203E8
# 201303E8
# 14420002
# 00000000
# 00221820
# 10000000
# 00000000

# EXPECTED_FINAL_STATE
# $01:16
# $02:-12
# $03:4
# $31:24