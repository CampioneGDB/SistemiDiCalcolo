.globl lower

lower:
    pushl %ebx
    pushl %esi

    movl $0, %ebx
    movl 12(%esp), %esi

    A:
    cmpl 16(%esp), %ebx
    jge R

    movzbl (%esi, %ebx, 1), %edx
    subl $4, %esp
    movl %edx, (%esp)
    call is_known
    addl $4, %esp
    testl %eax, %eax
    je K
    cmpb $97, (%esi, %ebx, 1)
    setge %ch
    cmpb $123, (%esi, %ebx, 1)
    setl %cl
    andb %ch, %cl
    testb %cl, %cl
    jne E
    cmpb $32, (%esi, %ebx, 1)
    sete %ch
    testb %ch, %ch
    jne E
    addb $32, (%esi, %ebx, 1)

    E:
    incl %ebx
    jmp A

    R:
    movl $0, %eax
    jmp B

    K:
    incl %ebx
    movl %ebx, %eax

    B:
    popl %esi
    popl %ebx
    ret

