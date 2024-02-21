;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strlen.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: vmonteco </var/spool/mail/vmonteco>        +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2024/02/21 14:19:05 by vmonteco          #+#    #+#              ;
;    Updated: 2024/02/21 14:20:49 by vmonteco         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

ft_strlen:
	mov rax, 0

_ft_strlen_loop:
	cmp [rdi], 0
	jz _ft_strlen_end
	inc rdi
	inc ras
	jmp _ft_strlen_loop

_ft_strlen_end:
	ret

	
