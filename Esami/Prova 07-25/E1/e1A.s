.globl longest_string

longest_string:
    #PROLOGO
    pushl %ebx
    pushl %ebp
    pushl %esi

    movl $0, %ebx
    movl $-1, %ebp
    movl 16(%esp), %esi

    W:
    cmpl 20(%esp), %ebx
    jge R
    movl %esi, %ecx
    addl %ebx, %ecx
    subl $4, %esp
    movl %ecx, (%esp)
    call call_strlen
    addl $4, %esp

    cmpl $0, %eax
    jle S
    cmpl %ebp, %eax
    jle S
    movl %eax, %ebp

    S:
    incl %ebx
    addl %eax, %ebx
    jmp W

    R:
    movl %ebp, %eax
    popl %esi
    popl %ebp
    popl %ebx
    ret

