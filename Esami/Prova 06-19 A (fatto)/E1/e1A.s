.globl init_matrix

init_matrix:
    #PROLOGO
    pushl %ebx
    pushl %ebp
    pushl %esi
    pushl %edi

    movl $-1, %ebx
    movl $0, %ebp
    movl 20(%esp), %esi
    movl 24(%esp), %edi

    F1:
    incl %ebx
    cmpl %edi, %ebx
    jge R
    movl $0, %ebp
    F2:
    cmpl %edi, %ebp
    jge F1

    subl $8, %esp
    movl %ebx, (%esp)
    movl %ebp, 4(%esp)
    call value
    addl $8, %esp

    movl (%esi, %ebx,4), %edx
    movw %ax, (%edx,%ebp,2)
    incl %ebp
    jmp F2

    R:
    #EPILOGO
    popl %edi
    popl %esi
    popl %ebp
    popl %ebx
    ret



    