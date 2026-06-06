.globl count_digits
count_digits:
    movl $0, %eax
    movl 4(%esp), %ecx
    L:
    movb (%ecx), %dl
    testb %dl, %dl
    jz R
    cmpb $48, %dl
    jl E
    cmpb $57, %dl
    jg E
    incl %eax
    E:
    incl %ecx
    jmp L

    R:
    ret


