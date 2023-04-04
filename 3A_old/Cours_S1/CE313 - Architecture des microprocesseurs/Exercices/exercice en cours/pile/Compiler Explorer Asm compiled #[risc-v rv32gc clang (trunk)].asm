square: # @square
  addi sp, sp, -16
  sw ra, 12(sp) # 4-byte Folded Spill
  sw s0, 8(sp) # 4-byte Folded Spill
  addi s0, sp, 16
  sw a0, -12(s0)
  lw a0, -12(s0)
  mul a0, a0, a0
  lw s0, 8(sp) # 4-byte Folded Reload
  lw ra, 12(sp) # 4-byte Folded Reload
  addi sp, sp, 16
  ret
sum: # @sum
  addi sp, sp, -16
  sw ra, 12(sp) # 4-byte Folded Spill
  sw s0, 8(sp) # 4-byte Folded Spill
  addi s0, sp, 16
  sw a0, -12(s0)
  sw a1, -16(s0)
  lw a0, -12(s0)
  lw a1, -16(s0)
  slli a1, a1, 1
  add a0, a0, a1
  lw s0, 8(sp) # 4-byte Folded Reload
  lw ra, 12(sp) # 4-byte Folded Reload
  addi sp, sp, 16
  ret
toto: # @toto
  addi sp, sp, -32
  sw ra, 28(sp) # 4-byte Folded Spill
  sw s0, 24(sp) # 4-byte Folded Spill
  addi s0, sp, 32
  sw a0, -12(s0)
  sw a1, -16(s0)
  lw a0, -16(s0)
  sw a0, -20(s0) # 4-byte Folded Spill
  lw a0, -12(s0)
  call square
  mv a1, a0
  lw a0, -20(s0) # 4-byte Folded Reload
  call sum
  lw s0, 24(sp) # 4-byte Folded Reload
  lw ra, 28(sp) # 4-byte Folded Reload
  addi sp, sp, 32
  ret