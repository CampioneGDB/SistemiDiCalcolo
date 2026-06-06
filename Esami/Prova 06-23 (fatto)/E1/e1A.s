.globl rc4_encrypt

rc4_encrypt:

#PROLOGO
pushl %edi
pushl %esi
pushl %ebx
pushl %ebp

movl $0, %edi
movl $0, %esi
movb $0, %bh

movl 24(%esp), %ebp

W:
cmpb $0, (%ebp)
jz R

incl %esi
andl $255, %esi
movl 20(%esp), %edx
addb (%edx, %esi,1), %bh
subl $20, %esp
movl %edx, (%esp)
movl %esi, 4(%esp)
movb %bh, 8(%esp)
movb %bl, 16(%esp)
leal 16(%esp), %eax
movl %eax, 12(%esp)
call rc4_helper
movl 12(%esp), %eax
movb (%eax), %bl
addl $20, %esp
movl 28(%esp), %eax
movb %bl, %ch
xorb (%ebp), %ch
movb %ch, (%eax,%edi,1)
incl %edi
incl %ebp
jmp W

R:
popl %ebp
popl %ebx
popl %esi
popl %edi
ret
