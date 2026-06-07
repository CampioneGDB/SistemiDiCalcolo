.globl base64lessless

base64lessless:
    pushl %ebx
    pushl %ebp
    pushl %esi
    pushl %edi

    cmpl $0, 20(%esp)
    je O
    cmpl $0, 24(%esp)
    je O

    movl 24(%esp), %ebx

    subl $4, %esp
    movl %ebx, (%esp)
    call malloc
    addl $4, %esp
    movl %eax, %edi

    movb $0, %dh
    movb $0, %dl
    movl 20(%esp), %esi

    movl $0, %ebx

    F:
    cmpl 24(%esp), %ebx
    jge R

    movb (%esi), %ah

    movb $6, %cl
    subb %dh, %cl

    movb %dl, %ch
    shlb %cl, %ch

    movb $2, %cl
    addb %dh, %cl
    movb %ah, %al
    shrb %cl, %al
    orb %al, %ch

    movb $6, %cl
    subb %dh, %cl
    movb $8, %dh
    subb %cl, %dh
    andb $7, %dh

    movb $8, %al
    subb %dh, %al
    movb %ah, %dl
    movb %al, %cl
    shlb %cl, %dl
    
    movb %al, %cl
    shrb %cl, %dl

    cmpb $6, %dh
    jl J

    S:
    movl 28(%esp), %ebp
    movzbl %ch, %eax
    movb (%ebp,%eax,1), %cl
    movb %cl, (%edi,%ebx,1)
    incl %ebx
    jmp F

    J:
    incl %esi
    jmp S

    O:
    movl $0, %edi

    R:
    movl %edi, %eax
    popl %edi
    popl %esi
    popl %ebp
    popl %ebx
    ret
