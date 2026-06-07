.globl crc32

crc32:
    pushl %ebx
    pushl %ebp
    pushl %esi
    pushl %edi

    movl $-1, %ebx
    movl $0, %ebp
    movl $0xFFFFFFFF, %esi

    F1:
    incl %ebx
    cmpl 24(%esp), %ebx
    jge RET
    movl 20(%esp), %eax
    movzbl (%eax,%ebx,1), %edi
    xorl %edi, %esi
    movl $0, %ebp
    F2:
    cmpl $8, %ebp
    jge F1
    movl %esi, %ecx
    andl $1, %ecx
    negl %ecx
    movl %esi, %edi
    sarl $1, %edi
    movl $0xEDB88320, %edx
    andl %ecx, %edx
    movl %edi, %esi
    xorl %edx, %esi
    incl %ebp
    jmp F2

    RET:
    notl %esi
    movl %esi, %eax

    popl %edi
    popl %esi
    popl %ebp
    popl %ebx
    ret
    