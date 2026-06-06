.globl binsearch
binsearch:
    #PROLOGO
    pushl %ebx
    pushl %esi

    movl $0, %eax
    movl 20(%esp), %ebx
    movl 16(%esp), %ecx
    movl 12(%esp), %esi
    E:
    cmpl %ecx, %eax
    jge F
    movl %eax, %edx
    addl %ecx, %edx
    sarl $1, %edx
    cmpl (%esi,%edx,4), %ebx
    je A
    cmpl %ebx, (%esi,%edx,4)
    jg B
    movl %edx, %eax
    incl %eax
    jmp E

    A:
        movl $1, %eax
        jmp R
    B:
        movl %edx, %ecx
        jmp E
    F:
        movl $0, %eax
        jmp R
    R:
        #EPILOGO
        popl %esi
        popl %ebx
        ret
        