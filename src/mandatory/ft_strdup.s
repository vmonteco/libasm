;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strdup.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: vmonteco </var/spool/mail/vmonteco>        +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2024/02/23 04:49:50 by vmonteco          #+#    #+#              ;
;    Updated: 2024/02/26 22:19:57 by vmonteco         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	extern __errno_location
	extern malloc
	global ft_strdup
	;; s in rdi
	
ft_strdup:
	call malloc wrt ..plt
	cmp rax, 0
	jz .error_handling
	jmp .end
	
.error_handling:
	call	__errno_location wrt ..plt
	mov		ebx, 0x0C
	mov		[rax], ebx
	mov		eax, 0
	
.end:
	ret
