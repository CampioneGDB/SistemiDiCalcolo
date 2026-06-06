.globl lcm

lcm:
    #PROLOGO
    pushl %ebx
    pushl %edi
    pushl %esi

    movl 16(%esp), %edi
    movl 20(%esp), %ebx
    movl %ebx, %ecx
    cmpl %ebx, %edi
    cmovg %edi, %ecx

    L:
    movl %ecx, %eax
    movl %eax, %edx
    sarl $31, %edx
    idivl %edi
    movl %edx, %esi

    movl %ecx, %eax
    movl %eax, %edx
    sarl $31, %edx
    idivl %ebx
    
    cmpl $0, %esi
    sete %ah

    cmpl $0, %edx
    sete %al

    andb %ah, %al
    cmpb $0, %al
    jg F

    incl %ecx
    jmp L

    F:
    movl %ecx, %eax
    #EPILOGO
    popl %esi
    popl %edi
    popl %ebx
    ret


