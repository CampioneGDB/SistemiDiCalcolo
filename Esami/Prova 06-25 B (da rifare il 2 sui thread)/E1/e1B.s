.globl check

check:
    #PROLOGO
    pushl %ebx
    pushl %ebp
    pushl %esi
    pushl %edi

    movl 20(%esp), %ebp
    movl $0, %ebx
    movl $0, %esi
    
    W:
    cmpl $0, %ebp
    je R
    incl %ebx

    subl $4, %esp
    movl %ebp, (%esp)
    call is_valid_move
    addl $4, %esp
    movb %al, %cl

    cmpb $0, %cl
    je E
    incl %esi
    
    E:
    movl 12(%ebp), %ebp
    jmp W

    R:
    cmpl %esi, %ebx
    je I

    movl $0, %eax
    jmp RET

    I:
    movl $1, %eax

    RET:
    popl %edi
    popl %esi
    popl %ebp
    popl %ebx
    ret
