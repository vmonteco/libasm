;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcpy.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: vmonteco </var/spool/mail/vmonteco>        +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2024/02/22 01:14:01 by vmonteco          #+#    #+#              ;
;    Updated: 2024/02/22 17:29:38 by vmonteco         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global ft_strcpy

ft_strcpy:
	; rdi will contain dst
	; rsi will contain src
	; At the end, rax will contain the return value
	push rdi
	mov rax, 0
	
.loop:
	cmp byte [rsi], 0
	mov al, [rsi]
	mov [rdi], al
	inc rdi
	inc rsi
	jz .end
	jmp .loop
	
.end:
	pop rax
	ret
