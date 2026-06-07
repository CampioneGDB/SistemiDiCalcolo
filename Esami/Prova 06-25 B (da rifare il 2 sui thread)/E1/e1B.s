.globl check

check:
    #PROLOGO
    pushl %ebx
    pushl %ebp
    pushl %esi

    movl $0, %ebx
    movl $0, %ebp
    movl 16(%esp), %esi

    W:
    cmpl $0, %esi
    je R

    incl %ebx
    
    subl $4, %esp
    movl %esi, (%esp)
    call is_valid_move
    addl $4, %esp
    movb %al, %cl

    cmpb $0, %cl
    je E
    incl %ebp
    E:
    movl 12(%esi), %esi
    jmp W

    R:
    cmpl %ebp, %ebx
    je A
    movl $0, %eax
    jmp ret

    A:
    movl $1, %eax
    jmp ret

    ret:
    popl %esi
    popl %ebp
    popl %ebx
    ret