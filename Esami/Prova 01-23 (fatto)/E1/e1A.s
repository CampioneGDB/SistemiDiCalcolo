.globl strings_are_upper

strings_are_upper:
    #PROLOGO
    pushl %ebx
    pushl %ebp
    pushl %esi
    pushl %edi

    cmpl $0, 24(%esp)
    jle NULL
    cmpl $0, 20(%esp)
    je NULL

    movl 20(%esp), %ebp
    movl 24(%esp), %ecx
    imull $4, %ecx
    subl $4, %esp
    movl %ecx, (%esp)
    call malloc
    addl $4, %esp
    movl %eax, %edi
    movl $-1, %ebx
    
    F:
    incl %ebx
    cmpl 24(%esp), %ebx
    jge R
    movl (%ebp, %ebx,4), %esi
    movl $1, (%edi,%ebx,4)
    
    W:
    movb (%esi), %ch
    testb %ch, %ch
    je F
    movb (%esi), %ch
    subl $4, %esp
    movzbl %ch, %eax
    movl %eax, (%esp)
    call isupper
    addl $4, %esp
    movl %eax, %ecx
    cmpl $0, %ecx
    jne S
    movl $0, (%edi,%ebx,4)
    jmp F

    S:
    incl %esi
    jmp W



    R:
    movl %edi, %eax
    jmp FIN

    NULL:
    movl $0, %eax
    jmp FIN

    FIN:
    popl %edi
    popl %esi
    popl %ebp
    popl %ebx
    ret
