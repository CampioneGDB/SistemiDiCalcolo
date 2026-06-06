.globl is_suffix

is_suffix:
    pushl %ebx
    pushl %esi

    movl 12(%esp), %ecx
    movl 16(%esp), %esi

    A:
    cmpb $0, (%ecx)
    je B
    incl %ecx
    jmp A

    B:
    cmpb $0, (%esi)
    je F
    incl %esi
    jmp B

    F:
    cmpl %ecx, 12(%esp)
    setne %al
    cmpl %esi, 16(%esp)
    setne %ah
    andb %ah, %al
    G:
    testb %al, %al
    je L
    decl %ecx
    decl %esi
    movb (%esi), %dl
    cmpb (%ecx), %dl
    sete %bh
    testb %bh, %bh
    jne F

    L:
    cmpl %ecx, 12(%esp)
    sete %al
    movb (%esi), %dl
    cmpb %dl, (%ecx)
    sete %ah
    andb %ah, %al
    movzbl %al, %eax
    R:
    popl %esi
    popl %ebx
    ret
