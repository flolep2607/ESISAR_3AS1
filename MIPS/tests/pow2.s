addi $10, $0, 5
addi $11, $0, 3 #power
addi $12, $0, 1

mult $12, $10
mflo $12
addi $11, $11, -1
bne $0, $11, -12
NOP

# EXPECTED_ASSEMBLY
# 200A0005
# 200B0003
# 200C0001
# 018A0018
# 00006012
# 216BFFFF
# 140BFFF4
# 00000000

# EXPECTED_FINAL_STATE
# $10:5
# $12:125
# HI:0
# LO:125