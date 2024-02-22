;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strlen.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: vmonteco </var/spool/mail/vmonteco>        +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2024/02/21 14:19:05 by vmonteco          #+#    #+#              ;
;    Updated: 2024/02/22 02:13:10 by vmonteco         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global ft_strlen
	
ft_strlen:
	mov rax, 0
	mov rcx, 0
	
.loop:
	cmp [rdi], cl
	jz .end
	inc rdi
	inc rax
	jmp .loop

.end:
	ret

	
