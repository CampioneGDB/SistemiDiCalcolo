.globl adler32_simplified

adler32_simplified:
    #PROLOGO
    pushl %ebx
    pushl %ebp
    pushl %edi
    pushl %esi

    movl $0, %ebx
    movl $1, %ebp
    movl $0, %edi
    movl 20(%esp), %esi

    F:
    cmpl 24(%esp), %ebx
    jge R
    movzbl (%esi, %ebx, 1), %ecx
    addl %ecx, %ebp
    andl $0xFFFF, %ebp
    addl %ebp, %edi
    andl $0xFFFF, %edi
    incl %ebx
    jmp F

    R:
    sall $16, %edi
    orl %ebp, %edi
    movl %edi, %eax

    popl %esi
    popl %edi
    popl %ebp
    popl %ebx
    ret
