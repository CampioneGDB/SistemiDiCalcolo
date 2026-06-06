.globl fight

fight:
    #PROLOGO
    pushl %ebx
    pushl %ebp
    pushl %esi
    pushl %edi

    movl 20(%esp), %ecx
    movl 24(%esp), %edx
    movw (%ecx), %si
    movw (%edx), %di
    movb $0, %bh

    F:
    incb %bh
    movb $0, %bl
    cmpb $10, %bh
    jg R

    movl 20(%esp), %ecx
    
    subl $12, %esp
    movzbl %bh, %eax
    movl %eax, (%esp)
    movl %ecx, 4(%esp)
    movzwl %di, %eax
    movl %eax, 8(%esp)
    call update
    addl $12, %esp
    movw %ax, %di

    movl 24(%esp), %edx

    subl $12, %esp
    movb %bh, (%esp)
    movl %edx, 4(%esp)
    movw %si, 8(%esp)
    call update
    addl $12, %esp
    movw %ax, %si

    subl $8, %esp
    movzwl %si, %eax
    movl %eax, (%esp)
    movzwl %di, %eax
    movl %eax, 4(%esp)
    call winner
    addl $8, %esp
    movb %al, %bl
    cmpb $0, %bl
    jl F
    jmp R

    R:
    movb %bl, %al
    popl %edi
    popl %esi
    popl %ebp
    popl %ebx
    ret

    

