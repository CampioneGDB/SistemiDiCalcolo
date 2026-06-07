# Inserire qui il codice assembly
.globl lower

lower:
	pushl %esi
	pushl %ebx
    pushl %edi
	subl $4, %esp
    movl 20(%esp), %edi # data è in esp + 20
                        # len è in esp + 24
    xorl %esi,%esi      # unsigned int si = 0;
for_start:
	cmpl 24(%esp), %esi	#	if (si >= len)
	jge for_exit 				#		 goto for_exit; 
    movb (%edi, %esi, 1), %bl   # char bl = data[si];
    movb %bl, (%esp)
    call is_known       # char al = is_known(bl);
    cmpb $1, %al        # if (al)
    je not_if           #   goto not_if;
    movl %esi, %eax     # ax = si;
    incl %eax           # ax += 1;
    jmp exit           # goto exit;
not_if:
    cmpb $97, %bl       # if (bl < 97)  //lower letter
    jl not_if2          #   goto not_if2
    cmpb $123, %bl      # if (bl>=123)  //lower letter
    jge not_if2         #   goto not_if2
    incl %esi            # si += 1;
    jmp for_start      # goto for_start;
not_if2:
    cmpb $32, %bl       # if (bl!=32) //space
    jne not_if3         #    goto not_if3;
    incl %esi           # si += 1;
    jmp for_start      # goto for_start;
not_if3:
    addb $32, %bl        # bl += 32;
    movb %bl, (%edi, %esi, 1) # data[si] = bl;
    incl %esi           # si += 1;
    jmp for_start      # goto for_start;

	
for_exit:
    xorl %eax, %eax     # ax=0;
exit:
    addl $4, %esp
    popl %edi
    popl %ebx
    popl %esi
    ret


