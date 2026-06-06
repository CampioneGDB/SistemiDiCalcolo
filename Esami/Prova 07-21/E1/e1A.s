.globl suffix

suffix:
    #PROLOGO
    pushl %ebx
    pushl %ebp
    pushl %esi
    pushl %edi

    movl 20(%esp), %eax
    subl $4, %esp
    movl %eax, (%esp)
    call strlen
    addl $4, %esp
    movl %eax, %esi

    movl 24(%esp), %ebp
    subl $4, %esp
    movl %ebp, (%esp)
    call strlen
    addl $4, %esp
    movl %eax, %edi

    cmpl %esi, %edi
    jg O

    movl %esi, %ebx
    subl %edi, %ebx
    F:
    cmpl %esi, %ebx
    jge I
    movl 20(%esp), %eax
    movb (%ebp), %dl
    cmpb %dl, (%eax, %ebx,1)
    jne O
    incl %ebp
    incl %ebx
    jmp F

    O:
    movl $0, %edx
    jmp R

    I:
    movl $1, %edx

    R:
    movl %edx, %eax
    popl %edi
    popl %esi
    popl %ebp
    popl %ebx
    ret
    