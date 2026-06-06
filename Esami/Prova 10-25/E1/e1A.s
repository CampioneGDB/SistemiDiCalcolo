.globl div_vectors

div_vectors:
    #PROLOGO
    pushl %ebp
    pushl %edi
    pushl %esi
    pushl %ebx
    subl $4, %esp
    
    movl 24(%esp), %ebp
    movl 28(%esp), %edi
    testl %ebp, %ebp
    movl $0, %eax
    je R
    testl %edi, %edi
    movl $0, %eax
    je R
    cmpl $0, 32(%esp)
    movl $0, %eax
    je R
    movl 32(%esp), %ecx
    imull $4, %ecx
    movl %ecx, (%esp)
    call malloc
    movl %eax, %esi
    movl $0, %ebx
    F:
    cmpl 32(%esp), %ebx
    movl %esi, %eax
    jge R
    movl (%ebp, %ebx, 4), %eax
    movl (%edi, %ebx, 4), %ecx
    movl $0, %edx
    divl %ecx
    movl %eax, (%esi, %ebx, 4)
    incl %ebx
    jmp F



    R:
    addl $4, %esp
    popl %ebx
    popl %esi
    popl %edi
    popl %ebp
    ret