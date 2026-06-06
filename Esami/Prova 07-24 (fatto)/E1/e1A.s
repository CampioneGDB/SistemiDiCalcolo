.globl cond_compute

cond_compute:
    #EPILOGO
    pushl %ebx
    pushl %ebp
    pushl %esi
    pushl %edi

    movl $0, %ebx
    movl 32(%esp), %ebp
    movl 20(%esp), %esi
    movl 24(%esp), %edi

    F:
    cmpl 28(%esp), %ebx
    jge R
    movl (%edi,%ebx,4), %ecx
    testl %ecx, %ecx
    jne P
    movw (%esi, %ebx, 2), %dx
    movw %dx, (%ebp, %ebx, 2)
    incl %ebx
    jmp F
    P:
    movw (%esi, %ebx, 2), %dx
    subl $4, %esp
    movw %dx, (%esp)
    call compute
    addl $4, %esp
    movw %ax, (%ebp, %ebx, 2)
    incl %ebx
    jmp F

    R:
    #PROLOGO
    movl %ebp, %eax
    popl %edi
    popl %esi
    popl %ebp
    popl %ebx
    ret
