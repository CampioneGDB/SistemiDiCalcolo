.globl deleetify

deleetify:
    pushl %esi
    pushl %ebp
    pushl %ebx
    pushl %edi

    movl 20(%esp), %esi
    movl 24(%esp), %ebp
    movl $0, %ebx
    subl $4, %esp
    movl %ebp, (%esp)
    call malloc
    addl $4, %esp
    movl %eax, %edi

    A:
    cmpl %ebp, %ebx
    jge R
    movb (%esi, %ebx, 1), %cl
    cmpb $57, %cl
    jle L
    movb %cl, (%edi, %ebx, 1);
    incl %ebx
    jmp A

    L:
    subl $4, %esp
    movb %cl, (%esp)
    call deleetify_helper
    addl $4, %esp
    movl %eax, (%edi, %ebx, 1)
    incl %ebx
    jmp A

    R:
    movl %edi, %eax
    popl %edi
    popl %ebx
    popl %ebp
    popl %esi
    ret    
