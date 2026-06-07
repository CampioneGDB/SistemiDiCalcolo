.globl lower

lower:
    #PROLOGO
    pushl %ebx
    pushl %ebp

    movl 12(%esp), %ebp
    movl $-1, %ebx

    F:
    incl %ebx
    cmpl 16(%esp), %ebx
    jge O
    
    movb (%ebp,%ebx,1), %dl
    subl $4, %esp
    movzbl %dl, %ecx
    movl %ecx, (%esp)
    call is_known
    addl $4, %esp
    movb %al, %dl
    cmpb $0, %dl
    je I1

    cmpb $97, (%ebp, %ebx,1)
    setge %cl

    cmpb $123, (%ebp, %ebx,1)
    setl %ch

    andb %ch, %cl

    cmpb $0, %cl
    jne F

    cmpb $32, (%ebp, %ebx,1)
    sete %cl

    cmpb $0, %cl
    jne F

    addb $32, (%ebp, %ebx,1)
    jmp F

    I1:
    incl %ebx
    jmp R

    O:
    movl $0, %ebx

    R:
    movl %ebx, %eax
    popl %ebp
    popl %ebx
    ret
