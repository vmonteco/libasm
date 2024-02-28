;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcpy.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: vmonteco </var/spool/mail/vmonteco>        +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2024/02/22 01:14:01 by vmonteco          #+#    #+#              ;
;    Updated: 2024/02/28 05:13:05 by vmonteco         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section			.text
	global		ft_strcpy

ft_strcpy:
	push		rdi				;; Str to copy will have a pointer to it passed
								;; through rdi. We must return it but will
								;; alter it so we preserve it with a push.
	
.loop:
	cmp			byte [rsi], 0	;; We check for the end of the str to copy.
	pushf						;; But we push flags to preserve them as we
								;; still have to copy the nul char at the end.
	mov			al, [rsi]		;; We use the byte-long register as we only
								;; copy char by char.
	mov			[rdi], al		;; Using two addresses isn't allowed with mov.
	inc			rdi				;; We increment the addresses.
	inc			rsi
	popf						;; We retrieve the previously saved flags.
	jz			.end			;; We check if we should jump to end with the
								;; ZF previously possibly set by cmp.
	jmp			.loop
	
.end:
	pop rax
	ret
