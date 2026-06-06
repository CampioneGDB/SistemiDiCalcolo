.globl count_tokens

count_tokens:
    #PROLOGO
    pushl %ebx
    pushl %edi
    pushl %ebp
    pushl %esi

    movl $0, %ebx
    movl 20(%esp), %edi
    movl 24(%esp), %ebp
    subl $8, %esp
    movl %edi, (%esp)
    movl %ebp, 4(%esp)
    call strtok
    addl $8, %esp
    movl %eax, %esi
    W:
    testl %esi, %esi
    je R
    incl %ebx
    subl $8, %esp
    movl $0, (%esp)
    movl %ebp, 4(%esp)
    call strtok
    addl $8, %esp
    movl %eax, %esi
    jmp W

    R:
    #PROLOGO
    movl %ebx, %eax
    popl %esi
    popl %ebp
    popl %edi
    popl %ebx
    ret

