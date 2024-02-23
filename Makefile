#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmonteco </var/spool/mail/vmonteco>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 14:00:52 by vmonteco          #+#    #+#              #
#    Updated: 2024/02/23 01:54:40 by vmonteco         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =								libasm.a
AS =								nasm
CC =								gcc
ASFLAGS =							
ASDEBUGFLAGS =						-g
LIBASM_FLAG =						$(subst .a,,$(subst lib,-l,$(NAME)))
DEBUG_FLAGS =						-v -W -g
CFLAGS =							-Wall -Werror -Wextra
CFLAGS +=							$(DEBUG_FLAGS)

SRC =								src/mandatory/ft_strlen.s \
									src/mandatory/ft_strcpy.s

BONUS_SRC =

OBJ  =								$(subst .s,.o,$(SRC))
OBJ_BONUS =							$(subst .s,.o,$(BONUS_SRC))

INCLUDES_DIR =						includes/

# Test related :
TESTS_DIR =							tests/
TESTS_INCLUDES_DIR =				$(addprefix $(TESTS_DIR),includes/)
TESTS_SRC_DIR =						$(addprefix $(TESTS_DIR),src/)

TESTS_SRC =							$(addprefix $(TESTS_SRC_DIR), \
										test_main.c \
										test_ft_strlen.c \
										test_ft_strcpy.c \
										test_ft_strcmp.c \
										test_ft_write.c \
										test_ft_read.c \
										test_ft_strdup.c \
									)

TESTS_H =							$(addprefix $(TESTS_INCLUDES_DIR),tests.h)

TESTS_INC_FLAGS =					-I $(TESTS_INCLUDES_DIR) -I $(INCLUDES_DIR)
CFLAGS +=							$(TESTS_INC_FLAGS)

TEST_EXECUTABLE =					test_libasm


# CLEAN_FILES :
LIBASM_CLEAN_FILES =				$(OBJ)
LIBASM_BONUS_CLEAN_FILES =			$(OBJ_BONUS)
TEST_CLEAN_FILES =					$(subst .c,.o,$(TEST_SRC)) \
									$(TEST_EXECUTABLE)
TEST_BONUS_CLEAN_FILES =			$(subst .c,.o,$(TEST_BONUS_SRC)) \
									$(TEST_BONUS_EXECUTABLE)
CLEAN_FILES =						$(LIBASM_CLEAN_FILES) \
									$(TEST_CLEAN_FILES)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $(OBJ)
	ranlib $@

src/%.o: src/%.s
	$(AS) $(ASFLAGS) -f elf64 -o $@ $^

test: $(TEST_EXECUTABLE)
	./$<

$(TEST_EXECUTABLE): $(TESTS_SRC) $(TESTS_H) $(NAME)
	$(CC) -o $@ $(CFLAGS) $(TESTS_SRC) -L. $(LIBASM_FLAG)

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
