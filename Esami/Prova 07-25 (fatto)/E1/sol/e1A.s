.globl longest_string

longest_string:			# unsigned int longest_string(const char* data, int len) {
	pushl %ebp			#	char * b;
	pushl %edi
	pushl %esi
	pushl %ebx
	subl $4, %esp
	movl 28(%esp), %ebx
	xorl %edi, %edi		#	int d = 0;
	movl $-1, %esi		#	int s = -1;
L:
	cmpl %ebx, %edi		#	if (d >= len)
	jge E				#		goto E;
	movl 24(%esp), %ebp	#	b = (char *)data;
	addl %edi, %ebp		#	b = b + d;
	movl %ebp, (%esp)
	call call_strlen			#	int a = strlen(b);
	testl %eax, %eax	#	if (a==0)
	jz S				#		goto S;
	cmpl %esi, %eax		#	if (a<=s)
	jle S 				#		 goto S; 
	movl %eax, %esi		#		s = a;
S:
	incl %eax			
	addl %eax, %edi		#	d = d + a + 1;
	jmp L				#	goto L;
E: 
	movl %esi, %eax		#	a = s;
	addl $4, %esp
	popl %ebx
	popl %esi
	popl %edi
	popl %ebp
	ret					#	return a;
