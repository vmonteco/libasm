;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcmp.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: vmonteco </var/spool/mail/vmonteco>        +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2024/02/23 04:14:14 by vmonteco          #+#    #+#              ;
;    Updated: 2024/02/25 12:46:20 by vmonteco         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

	;; Possible instructions to use :
	;; - NEG
	;; - OR
	;; - POR
	;; - movsx
	;; CF. also :
	;; - Carry Flag (CF)
	;; - Sub Flag (SF)
	;; - How are negative numbers represented in ASM
	;; - 19:52 < Jester01> note that subtracting unsigned can give a (seemingly) negative result which isn't really negative ... e.g. 0xff - 0x01 = 0xfe
	;; - you should use the carry flag for unsigned ... you can easily shift that into the MSB
	;; 
	
	global ft_strcmp
	
ft_strcmp:
	;; rdi ; s1
	;; rsi : s2
	mov rax, 0
	
.loop:
	mov cl, [rdi]
	mov dl, [rsi]
	mov al, cl
	sub al, dl
	js .sub_sign
	jnz .end
	cmp cl, 0
	jz .end
	cmp dl, 0
	jz .end
	inc rdi
	inc rsi
	jmp .loop

.sub_sign:
	;; por rax, 80 00 00 00h

.end:
	ret
