;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcmp.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: vmonteco </var/spool/mail/vmonteco>        +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2024/02/23 04:14:14 by vmonteco          #+#    #+#              ;
;    Updated: 2024/02/23 04:42:59 by vmonteco         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global ft_strcmp
	
ft_strcmp:
	;; rdi ; s1
	;; rsi : s2
	mov rax, 0
	
.loop:
	cmp byte [rdi], 0
	jz .end
	cmp byte [rsi], 0
	jz .end
	mov cl, [rdi]
	mov dl, [rsi]
	sub cl, dl
	jnz .end
	inc rdi
	inc rsi
	jmp .loop
	
.end:
	ret
