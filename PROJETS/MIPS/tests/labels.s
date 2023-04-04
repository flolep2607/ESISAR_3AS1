# Main program
main:
    # Call function1
    jal function1

    # Call function2
    jal function2

    # Exit program
    syscall
#  Declare function1
function1:
    # Function1 code goes here
    jr $ra

# Declare function2
function2:
    # Function2 code goes here
    jr $ra


# EXPECTED_ASSEMBLY
# 0C000003
# 0c000004
# 0000000c
# 03e00008
# 03e00008

# EXPECTED_FINAL_STATE
# $31:8