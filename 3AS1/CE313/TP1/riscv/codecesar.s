# Code de César en RISCV
# CE313, binôme : MONCORGE,LEPRAT
    .section .text
    .globl main
main:
        addi    sp,sp,-16 
        sd      ra,8(sp)
	li t1,0
	## your assembly code here
	la t3, result
	la a0, s    # convention: a0 contient le premier argument
	ld a1, dec
	call caesar
	la a0, s
	call newline
	call println_string
	call newline
        ld      ra,8(sp)
        addi    sp,sp,16
        ret

caesar:
	addi    sp,sp,-16 
        sd      ra,8(sp)
	mv t2, a0 # l'argument de la routine contient l'adresse de début
	mv t1, a1
loop:
	lb t6, 0(t2)
	beq t6,zero,end
	# on calcule la nouvelle valeur
	add t6, t6, t1
	li t0,122
	blt t6,t0,continue
	addi t6, t6, -26
continue:
	#sb t6, 0(t2)
	mv a0,t6
	call print_char
	addi t2,t2,1
	j loop
end:
	## fin du code fonctionnel
		ld      ra,8(sp)
		addi    sp,sp,16	
	ret

s:
	.string "abcz"
dec:
    .dword 2

