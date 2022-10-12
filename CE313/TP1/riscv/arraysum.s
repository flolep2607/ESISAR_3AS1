# Programme pour ajouter 1 à chacune des cases d'un tableau
# 
	.globl main
main:
    addi	sp,sp,-16
	sd	ra,8(sp)
## TODO Your assembly code there
	# chargement de l'adresse de début de tableau dans a0
	la t2,tab
	mv a0, t2
	# et contenu au label len dans a1
	la t1, len
	ld a1, 0(t1)
	li t1, 0
	call arraysum
	# pour vérifier on peut regarder le contenu à la case numéro 3
	#la t2, tab # t2 a été écrasé durant la routine
	mv a0, t1
	call print_int
	call newline #### THIS IS 42 !!
## end of user assembly code
	ld	ra,8(sp)
	addi	sp,sp,16
        ret

# routine d'ajout
# l'appel dans le main n'est pas demandé dans l'exo du TD1
	#a0 contient l'adresse de début et a1 la taille
arraysum:
	mv t3, a1 # t3 est la taille
	mv t4, zero # compteur de boucle
	mv t5, a0 #compteur d'adresse (on inc de 8 à chaque tour)
loop:
	beq t4, t3, end	# si égalité, alors c'est fini
	# on récupère la valeur à l'adresse t5
	ld t6, 0(t5)
	# on calcule la nouvelle valeur
	add t1, t1, t6
	# on modifie la valeur à l'adresse t5
	sd t6, 0(t5)
	# la suite est pour réaliser la boucle de parcours
	addi t4, t4, 1 # incrémentation du compteur
	mv a0, t4
	addi t5, t5, 8 # incrémentation du pointeur (+64 bits)
	j loop
end:	
	ret
	.section .data
len:
	.dword 4
tab:
	.dword 7
	.dword -1
	.dword 12
	.dword 41
