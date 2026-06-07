.globl slice

slice:
    #PROLOGO
    pushl %ebx
    pushl %ebp
    pushl %esi

    movl $0, %ebx
    movl 24(%esp), %esi
    movl 16(%esp), %ebp
    subl 20(%esp), %esi
    subl $1, %esi

    W:
    cmpb $0, (%ebp)
    je I

    cmpl 20(%esp), %ebx
    jne E

    subl $12, %esp
    movl %ebp, (%esp)
    movl %esi, 4(%esp)
    movl 40(%esp), %eax
    movl %eax, 8(%esp)
    call slice_helper
    addl $12, %esp

    E:
    incl %ebx
    incl %ebp
    jmp W

    I:
    cmpl 20(%esp),%ebx
    jge R

    movl $0, %esi

    R:
    movl %esi, %eax

    #EPILOGO
    popl %esi
    popl %ebp
    popl %ebx
    ret