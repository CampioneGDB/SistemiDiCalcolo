.globl str_to_upper

str_to_upper:
    #PROLOGO
    pushl %ebx
    pushl %ebp
    pushl %esi
    pushl %edi

    movl 20(%esp), %ebx
    cmpl $0, %ebx
    jz NUL

    subl $4, %esp
    movl %ebx, (%esp)
    call strdup
    addl $4, %esp
    movl %eax, %ebp
    movl %ebp, %esi
    W:
    movb (%esi), %dh
    cmpb $0, %dh
    jz R

    subl $4, %esp
    movzbl (%esi), %edx
    movl %edx, (%esp)
    call toupper
    addl $4, %esp
    movb %al, %bl
    movb %bl, (%esi)
    incl %esi
    jmp W

    NUL:
    movl $0, %eax
    jmp RET

    R:
    movl %ebp, %eax

    RET:
    popl %edi
    popl %esi
    popl %ebp
    popl %ebx
    ret
    