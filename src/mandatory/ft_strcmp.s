;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcmp.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: vmonteco </var/spool/mail/vmonteco>        +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2024/02/23 04:14:14 by vmonteco          #+#    #+#              ;
;    Updated: 2024/03/01 04:06:47 by vmonteco         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	section					.text
	global					ft_strcmp
	
ft_strcmp:
	;; According to the calling convention :
	;; - The s1 parameter will be passed through rdi.
	;; - The s2 parameter will be passed through rsi.
	
.loop:
	mov						rax, 0
	mov						ecx, 0
	mov						edx, 0
	mov						cl, [rdi]	;; Put s1 in cl byte per byte.
	mov						dl, [rsi]	;; Same for s2.
	
	mov						eax, ecx	;; We need to preserve current chars
										;; for both s1 and s2 so we can check
										;; it's not nul.
	sub						eax, edx	;; Actual substraction.
	jnz						.end		;; Sub might have set ZF.
										;; We end in case of difference.
	cmp						cl, 0		;; We check if any of the str ends.
	jz						.end
	cmp						dl, 0
	jz						.end
	inc						rdi			;; We increment each str.
	inc						rsi
	jmp						.loop		;; We loop back on .loop label

.end:
	ret
