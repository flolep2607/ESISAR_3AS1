	.text
	.globl main
main: 	                                                           
	addi	sp,sp,-16
	sd	ra,8(sp)
## Your assembly code there
# min
# max
	la 	t3, mydata # load reading address
	ld 	t4,  0(t3) # first op of minmax => 7
	ld 	t5,  8(t3) # second op of minmax => 42
	la 	t6, min # load writing adress
	blt 	t4, t5, fst_is_min
	mv 	a0, t5
	j 	end_min
fst_is_min:
	mv 	a0, t4
end_min:
	sd 	a0, 0(t6) # write result
	call 	print_int
	call	newline
	la 	t6, min # load writing adress
	blt 	t5, t4, fst_is_max
	mv 	a0, t5
	j 	end_max
fst_is_max:
	mv 	a0, t4
end_max:
	sd 	a0, 0(t6) # write result
	call 	print_int
	call	newline
## End of user assembly code
	ld	ra,8(sp)
	addi	sp,sp,16
	ret

# Data comes here
	.section	.data
mydata:
	.dword 69
	.dword -7
min:
	.dword 0
