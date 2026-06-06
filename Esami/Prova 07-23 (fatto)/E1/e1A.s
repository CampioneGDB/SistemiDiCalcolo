.globl adler32

adler32:
    #PROLOGO
    pushl %ebx
    pushl %ebp
    pushl %esi
    pushl %edi

    movl 20(%esp), %eax
    movl 24(%esp), %ecx
    cmpl $0, %eax
    je O
    cmpl $0, %ecx
    je O

    movl $1, %esi
    movl $0, %edi

    subl $8, %esp
    movl %ebp, 4(%esp)
    leal 4(%esp), %ecx
    movl %ecx, (%esp)
    call get_adler_constant
    movl (%esp), %ecx
    movl (%ecx), %ebp
    addl $8, %esp

    movl $0, %ebx

    F:
    cmpl 24(%esp), %ebx
    jge R
    movl 20(%esp), %eax

    movzbl (%eax, %ebx, 1), %ecx
    addl %ecx, %esi
    movl $0, %edx
    movl %esi, %eax
    divl %ebp
    movl %edx, %esi

    addl %esi, %edi
    movl $0, %edx
    movl %edi, %eax
    divl %ebp
    movl %edx, %edi
    incl %ebx
    jmp F

    O:
    movl $0, %edi
    jmp FIN

    R:
    shll $16, %edi
    orl %esi, %edi

    FIN:
    movl %edi, %eax
    #EPILOGO
    popl %edi
    popl %esi
    popl %ebp
    popl %ebx
    ret
