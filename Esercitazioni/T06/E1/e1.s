.globl list_add_first

list_add_first:
    #PROLOGO
    pushl %esi

    subl $4, %esp
    movl $8, (%esp)
    call malloc
    addl $4, %esp
    movl 12(%esp), %esi
    movl 8(%esp), %ecx
    movl (%ecx), %edx
    
    testl %eax, %eax
    jnz F
    jmp E
F:
    movl %esi, (%eax)
    movl %edx, 4(%eax)
    movl %eax, (%ecx)
    movl $0, %eax
    jmp R


E:
    movl $-1, %eax

R:
    #EPILOGO
    popl %esi
    ret
