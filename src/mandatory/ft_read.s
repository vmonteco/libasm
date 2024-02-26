;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_read.s                                          :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: vmonteco </var/spool/mail/vmonteco>        +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2024/02/23 04:49:12 by vmonteco          #+#    #+#              ;
;    Updated: 2024/02/26 22:04:16 by vmonteco         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	extern __errno_location
	global ft_read

	;; fd in rdi
	;; buf in rsi
	;; count in rdx
	
ft_read:
	mov rax, 0x00
	syscall
	cmp rax, 0
	js .error_handling
	jmp .end

.error_handling:
	neg		eax

	call	__errno_location wrt ..plt
	mov		[rax], eax
	mov		eax, -1

.end:
	ret

