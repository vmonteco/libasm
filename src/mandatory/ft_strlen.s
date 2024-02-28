;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strlen.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: vmonteco </var/spool/mail/vmonteco>        +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2024/02/21 14:19:05 by vmonteco          #+#    #+#              ;
;    Updated: 2024/02/27 22:41:17 by vmonteco         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	;; ft_strlen's signature :
	;; size_t	ft_strlen(const char *s);

	;; According to the calling convention, parameters and result are passed as
	;; the following :
	;; - rdi will contain the first pointer 
	;; - Result will be passed through rax.

	;; Here we declare ft_strlen as a global symbol to make it accessible for
	;; the whole codebase.
section .text
	global		ft_strlen

ft_strlen:
	mov			rax, 0		;; Fill rax with 0, initial result value that will
							;; be returned
	mov			cl, 0		;; Fill cl with 0, i-e the value of nul char.

	;; Labels with a leading dot aren't meant to be exported.
.loop:
	;; rdi contains our pointer to the string passed as a parameter.
	;; We compare it to the zero contained in cl (cl is one byte wide, we use
	;; rather than rcx since the cmp instruction will deduce what data size
	;; at pointer address to compare with the second operand. We only want to
	;; compare char by char.
	cmp			[rdi], cl	;; rdi contains our pointer
	;; cmp may have set ZF (Zero Flag). If so it means that current address
	;; contains a nul char (and therefore the end of the char array). If so,
	;; This will jump to .end.
	jz			.end
	;; Other wise we increment both result and pointer address.
	inc			rdi
	inc			rax
	;; And we jump (loop back) at .loop.
	jmp			.loop

.end:
	;; This will give control back to the caller.
	ret
