;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strlen.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: vmonteco </var/spool/mail/vmonteco>        +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2024/02/21 14:19:05 by vmonteco          #+#    #+#              ;
;    Updated: 2024/02/21 22:52:17 by vmonteco         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	global ft_strlen
	
ft_strlen:
	mov rax, 0
	mov rcx, 0
	
_ft_strlen_loop:
	cmp [rdi], cl
	jz _ft_strlen_end
	inc rdi
	inc rax
	jmp _ft_strlen_loop

_ft_strlen_end:
	ret

	
