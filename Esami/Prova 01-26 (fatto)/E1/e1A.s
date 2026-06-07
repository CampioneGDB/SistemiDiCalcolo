.globl div_vectors

div_vectors:
    #PROLOGO
    pushl %ebx
    pushl %ebp
    pushl %esi
    pushl %edi

    cmpl $0, 20(%esp)
    je NUL
    cmpl $0, 24(%esp)
    je NUL
    cmpl $0, 28(%esp)
    je NUL

    movl $4, %eax
    imull 28(%esp), %eax

    subl $4, %esp
    movl %eax, (%esp)
    call malloc
    addl $4, %esp
    movl %eax, %ebp

    movl $0, %ebx

    F:
    cmpl 28(%esp), %ebx
    jge ret

    movl 24(%esp), %esi
    cmpl $0, (%esi, %ebx,4)
    je CASE2
    movl 20(%esp), %edi
    movl (%edi,%ebx,4), %eax
    movl (%esi,%ebx,4), %ecx

    movl %eax, %edx
    sarl $31, %edx
    idivl %ecx

    movl %eax, (%ebp,%ebx,4)
    incl %ebx
    jmp F

    CASE2:
    movl $0, (%ebp,%ebx,4)
    incl %ebx
    jmp F

    NUL:
    movl $0, %ebp

    ret:
    movl %ebp, %eax
    popl %edi
    popl %esi
    popl %ebp
    popl %ebx
    ret

    
