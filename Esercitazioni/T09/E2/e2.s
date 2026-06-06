.globl crc32b

#ESI bytes puntatore
#EDX n
#ECX magic
#EBX crc
#EDI byte
#EAX index, eax
#EBP value

crc32b:
    #PROLOGO
    pushl %ebx
    pushl %esi
    pushl %edi
    pushl %ebp
    subl $12, %esp

    movl 32(%esp), %esi
    movl 36(%esp), %ebp
    movl $0, %ecx #magic
    notl %ecx
    movl %ecx, %ebx #crc
    E:
    testl %ebp, %ebp
    jz R
    decl %ebp
    movzbl (%esi), %edi
    incl %esi
    movl %ebx, %eax
    xorl %edi, %eax
    andl $0xFF, %eax
    leal 8(%esp), %ecx 
    movl %ecx, (%esp)
    movl %eax, 4(%esp)
    call get_constant
    sarl $8, %ebx
    xorl 8(%esp), %ebx
    jmp E


    R:
    movl $0, %ecx #magic
    notl %ecx
    movl %ebx, %eax
    xorl %ecx, %eax

    #EPILOGO
    addl $12, %esp
    popl %ebp
    popl %edi
    popl %esi
    popl %ebx

    ret
