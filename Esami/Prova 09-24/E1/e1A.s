.globl slice


slice:
    #PROLOGO
    pushl %edi
    pushl %esi
    pushl %ebx
    pushl %ebp

    movl 20(%esp), %edi
    movl 32(%esp), %esi

    movl $0, %ebx
    movl 28(%esp), %ebp
    subl 24(%esp), %ebp
    subl $1, %ebp

    W:
    cmpb $0, (%edi)
    je I
    cmpl 24(%esp), %ebx
    jne K
    incl %ebx
    subl $12, %esp
    movl %edi, (%esp)
    movl %ebp, 4(%esp)
    movl %esi, 8(%esp)
    call slice_helper
    addl $12, %esp
    incl %edi
    jmp W

    K:
    incl %ebx
    incl %edi
    jmp W

    I:
    cmpl 24(%esp), %ebx
    jge R
    movl $0, %ebp

    R:
    movl %ebp, %eax
    popl %ebp
    popl %ebx
    popl %esi
    popl %edi
    ret