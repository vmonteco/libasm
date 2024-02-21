#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmonteco </var/spool/mail/vmonteco>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 14:00:52 by vmonteco          #+#    #+#              #
#    Updated: 2024/02/21 14:11:48 by vmonteco         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =								libasm.a
AS =								nasm
CC =								gcc
ASFLAGS =							
ASDEBUGFLAGS =						-g
CFLAGS =							-Wall -Werror -Wextra

SRC =

BONUS_SRC =

OBJ  =								$(subst .s,.o,$(SRC))
BONUS_OBJ =							$(subst .s,.o,$(BONUS_SRC))

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $(OBJ)
	ranlib $@

%.o: %.s
	$(AS) $(ASFLAGS) -f elf64 -o $@ $^

clean:

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY:
