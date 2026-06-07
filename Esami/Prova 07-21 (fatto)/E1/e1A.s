.globl suffix

suffix:
    #PROLOGO
    pushl %ebx
    pushl %ebp
    pushl %esi
    pushl %edi

    movl 20(%esp), %esi
    movl 24(%esp), %edi

    subl $4, %esp
    movl %esi, (%esp)
    call strlen
    addl $4, %esp
    movl %eax, %ebp

    subl $4, %esp
    movl %edi, (%esp)
    call strlen
    addl $4, %esp
    movl %eax, %edx
    
    cmpl %ebp, %edx
    jg O

    movl %ebp, %ebx
    subl %edx, %ebx

    movl 20(%esp), %esi
    movl 24(%esp), %edi

    F:
    cmpl %ebp, %ebx
    jge I

    movb (%esi, %ebx,1), %al
    cmpb (%edi), %al
    jne O
    incl %edi
    incl %ebx
    jmp F

    I:
    movl $1, %eax
    jmp R

    O:
    movl $0, %eax

    R:
    popl %edi
    popl %esi
    popl %ebp
    popl %ebx
    ret