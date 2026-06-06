.globl hextodec_sum

hextodec_sum:
    #PROLOGO
    pushl %ebx
    pushl %ebp
    pushl %esi
    pushl %edi

    movl $0, %ebx
    movl $0, %ebp
    movl 24(%esp), %edi

    W:
    movl 20(%esp), %eax
    movb (%eax), %ch
    testb %ch, %ch
    jz R

    subl $12, %esp
    movl %eax, (%esp)
    movl %esi, 8(%esp)
    leal 8(%esp), %edx
    movl %edx, 4(%esp)
    call hextodec_helper
    movl 8(%esp), %esi
    addl $12, %esp

    cmpl $0, %esi
    jle G

    addl %esi, %ebx

    G:
    movl %esi, (%edi, %ebp, 4)
    incl %ebp
    addl $2, 20(%esp)
    jmp W

    R:
    #EPILOGO
    movl %ebx, %eax
    popl %edi
    popl %esi
    popl %ebp
    popl %ebx
    ret
