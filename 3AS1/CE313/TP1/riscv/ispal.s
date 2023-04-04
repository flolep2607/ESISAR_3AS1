# Palindromes en RISCV
	.text
	.globl main
main:
        addi    sp,sp,-16 
        sd      ra,8(sp)
	li t1,0
	## your assembly code here
	la a0, machaine    # convention: a0 contient le premier argument
	call length
	mv t1,a0
	la a0, machaine
	call ispal
	#la t4, machaine
	call print_int
	call newline
	#mv a0, t1  # 3*8 (3 cases de 8 octets)
	#call print_int
	#call newline #### THIS IS 42 !!
	# TODO : call ispal and print the result
	## /TODO
	## end of user assembly code
        ld      ra,8(sp)
        addi    sp,sp,16
        ret

length:
	addi    sp,sp,-16 
        sd      ra,8(sp)
	## code "fonctionnel" de la routine
	li t1, -1 # compteur de taille
	mv t3, a0 # l'argument de la routine contient l'adresse de début
loop:	
	lb t5, 0(t3) # caractère courant
	addi t1,t1,1 #incrément du compteur de taille
	addi t3,t3,1 #incrément de l'adresse
	bne t5,zero,loop
	mv a0,t1  # a0 contient le résultat
	## fin du code fonctionnel
    	 ld      ra,8(sp)
    	 addi    sp,sp,16	
	ret


ispal:	
	addi    sp,sp,-16 
        sd      ra,8(sp)
	mv t5, a0 #compteur d'adresse (on inc de 8 à chaque tour)
	add a0,a0,t1
	mv t6, a0 #compteur d'adresse (on dec de 8 à chaque tour)
	li t0,1
loop_pal:
	blt t6, t5, end	# si atteint fin tableau
	ld t1, 0(t5)
	ld t2, 0(t6)
	bne t1,t2,faux
	## code "fonctionnel" de la routine
	## convention : a0 contient l'adresse de la chaine
	## le resultat sera stocké dans a0: 1 si Vrai, 0 si Faux
	addi t5, t5, 1 # incrémentation du pointeur (+64 bits)
	addi t6, t6, -1 # incrémentation du pointeur (-64 bits)
	j loop_pal
faux:
	li t0,0
end:
	mv a0,t0
	    ld      ra,8(sp)
        addi    sp,sp,16
	ret
	.section .rodata
machaine:
	.string "kayak"
	
