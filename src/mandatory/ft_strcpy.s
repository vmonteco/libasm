;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcpy.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: vmonteco </var/spool/mail/vmonteco>        +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2024/02/22 01:14:01 by vmonteco          #+#    #+#              ;
;    Updated: 2024/02/23 04:10:22 by vmonteco         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global ft_strcpy

ft_strcpy:
	push rdi
	mov rax, 0
	
.loop:
	cmp byte [rsi], 0
	pushf
	mov al, [rsi]
	mov [rdi], al
	inc rdi
	inc rsi
	popf
	jz .end
	jmp .loop
	
.end:
	pop rax
	ret
