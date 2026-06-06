.globl list_equal
list_equal:
    #PROLOGO
    pushl %ebx

    movl 8(%esp), %edx
    movl 12(%esp), %eax
F:
    testl %edx, %edx
    setz %cl
    testl %eax, %eax
    setz %ch
    testb %cl, %cl
    jnz R
    testb %ch, %ch
    jnz R
    movw (%edx), %bx
    cmpw %bx, (%eax)
    jne O
    movl 4(%edx), %edx
    movl 4(%eax), %eax
    jmp F


O:
    movl $0, %eax
    jmp RET
R:
    andb %cl, %ch
    movzbl %ch, %eax

RET:
    #EPILOGO
    popl %ebx
    ret

