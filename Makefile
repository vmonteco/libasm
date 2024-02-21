#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmonteco </var/spool/mail/vmonteco>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 14:00:52 by vmonteco          #+#    #+#              #
#    Updated: 2024/02/21 18:31:45 by vmonteco         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =								libasm.a
AS =								nasm
CC =								gcc
ASFLAGS =							
ASDEBUGFLAGS =						-g
LIBASM_FLAG =						$(subst .a,,$(subst lib,-l,$(NAME)))
CFLAGS =							-v -W -Wall -Werror -Wextra $(LIBASM_FLAG)

SRC =								src/mandatory/ft_strlen.s

BONUS_SRC =

OBJ  =								$(subst .s,.o,$(SRC))
OBJ_BONUS =							$(subst .s,.o,$(BONUS_SRC))

# Test related :
TEST_SRC =							tests/mandatory/test_main.c \
									tests/mandatory/test_ft_strlen.c
TEST_H =							tests/mandatory/includes/test.h
TEST_BONUS_SRC =					tests/bonus/test_bonus_main.c
TEST_BONUS_H =						tests/bonus/includes/test_bonus.h

TEST_EXECUTABLE =					test_libasm
TEST_BONUS_EXECUTABLE =				test_bonus_libasm

# CLEAN_FILES :
LIBASM_CLEAN_FILES =				$(OBJ)
LIBASM_BONUS_CLEAN_FILES =			$(OBJ_BONUS)
TEST_CLEAN_FILES =					$(subst .c,.o,$(TEST_SRC)) \
									$(TEST_EXECUTABLE)
TEST_BONUS_CLEAN_FILES =			$(subst .c,.o,$(TEST_BONUS_SRC)) \
									$(TEST_BONUS_EXECUTABLE)
CLEAN_FILES =						$(LIBASM_CLEAN_FILES) \
									$(LIBASM_BONUS_CLEAN_FILES) \
									$(TEST_CLEAN_FILES) \
									$(TESTS)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $(OBJ)
	ranlib $@

src/%.o: src/%.s
	$(AS) $(ASFLAGS) -f elf64 -o $@ $^

test: $(TEST_EXECUTABLE)
	./$<

$(TEST_EXECUTABLE): $(TEST_SRC) $(TEST_H) $(NAME)
	$(CC) $(CFLAGS) -o $@ -I tests/mandatory/includes -I src/mandatory/includes -L . $(TEST_SRC) 

test_bonus: $(TEST_BONUS_EXECUTABLE)
	./$<

$(TEST_BONUS_EXECUTABLE): $(TEST_BONUS_SRC) $(TEST_BONUS_H) $(NAME)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm $(CLEAN_FILES)

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re test test_bonus
