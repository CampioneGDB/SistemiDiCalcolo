.globl deleetify

deleetify:
    pushl %ebx
    pushl %ebp
    pushl %esi
    pushl %edi

    movl 24(%esp), %ecx
    movl 20(%esp), %ebp
    movl $-1, %ebx

    subl $4, %esp
    movl %ecx, (%esp)
    call malloc
    addl $4, %esp
    movl %eax, %esi

    F:
    incl %ebx
    cmpl 24(%esp), %ebx
    jge R
    movb (%ebp, %ebx, 1), %dl
    cmpb $57, %dl
    jg E

    subl $4, %esp
    movzbl %dl, %eax
    movl %eax, (%esp)
    call deleetify_helper
    movb %al, %dh
    addl $4, %esp
    movb %dh, (%esi, %ebx,1)
    jmp F

    E:
    movb %dl, (%esi, %ebx,1)
    jmp F


    R:
    movl %esi, %eax
    popl %edi
    popl %esi
    popl %ebp
    popl %ebx

    ret
    