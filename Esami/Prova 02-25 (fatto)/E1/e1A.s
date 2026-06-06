.globl count_tokens

count_tokens:
    #PROLOGO
    pushl %ebx
    pushl %ebp
    pushl %esi
    pushl %edi

    movl $0, %ebx
    movl 20(%esp), %ebp
    movl 24(%esp), %esi
    
    subl $8, %esp
    movl %ebp, (%esp)
    movl %esi, 4(%esp)
    call strtok
    movl %eax, %edi
    addl $8, %esp

    W:
    testl %edi, %edi
    jz R
    incl %ebx

    subl $8, %esp
    movl $0, (%esp)
    movl %esi, 4(%esp)
    call strtok
    movl %eax, %edi
    addl $8, %esp
    jmp W

    R:
    movl %ebx, %eax
    popl %edi
    popl %esi
    popl %ebp
    popl %ebx
    ret
