.globl factorial

.data
n: .word 10

.text
main:
    la t0, n
    lw a0, 0(t0)
    jal ra, factorial

    addi a1, a0, 0
    addi a0, x0, 1
    ecall # Print Result

    addi a1, x0, '\n'
    addi a0, x0, 11
    ecall # Print newline

    addi a0, x0, 10
    ecall # Exit

factorial:
    #StartEpiloque
    addi sp,sp,-12
    sw s0, 0(sp)
    sw ra, 4(sp)
    sw a0, 8(sp)
    #EndEpilogue
    

    #StartBODY
    addi s0, x0, 2
    blt a0, s0, answer
    else:
    addi a0 a0, -1
    jal ra factorial
    #EndBody
    
    #StartPrologue
    mv t0 a0
    lw s0, 0(sp)
    lw ra, 4(sp)
    lw a0, 8(sp)
    mul a0 t0, a0
    addi sp,sp,12
    #EndPrologue
    answer: 
    jr ra
    
    jr ra
