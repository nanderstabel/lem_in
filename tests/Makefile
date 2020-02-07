# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mgross <mgross@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/02/06 08:47:04 by mgross         #+#    #+#                 #
#    Updated: 2020/02/07 14:23:51 by mgross        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = unit_test

TESTS_OBJ_FILE_TXT := obj_files.txt

TEST_OBJ_FILES := $(addprefix ./srcs/, $(shell cat $(TESTS_OBJ_FILE_TXT)))

INPUT_VALIDATION := ./srcs/crit_test.o

INPUT_STRUCT := ./srcs/crit_test2.o

PROJECT_OBJ_FILE_TXT := ../obj_files.txt

TEMP := $(addprefix ../srcs/, $(shell cat $(PROJECT_OBJ_FILE_TXT)))

PROJECT_OBJ_FILES := $(filter-out ../srcs/lem_in.o,$(TEMP))

INC_DIR = includes/

# INPUT_TEST = 0

# STRUCT_TEST = 0

HEADER_FILES = $(INC_DIR)tests.h

LIB = -L ./libft/ -lft

CFLAGS = -Wall -Wextra -Werror -g

DEPS = -Iincludes/ -I../libft/includes -I../includes/

LIB = -L ../libft/ -lft

ifeq ($(INPUT_TEST), 1)
OBJECT_FILES = $(INPUT_VALIDATION)
else ifeq ($(STRUCT_TEST), 1)
OBJECT_FILES = $(INPUT_STRUCT)
else
OBJECT_FILES = $(TEST_OBJ_FILES)
endif

all: $(NAME)

$(NAME): $(OBJECT_FILES) $(PROJECT_OBJ_FILES)
	@$(CC) -o $@ $^ -I$(INC_DIR) -lcriterion $(LIB)
	@echo "Unit test compiled."

%.o: %.c $(HEADER_FILES)
	@$(CC) -c $(CFLAGS) $(DEPS) -o $@ $<

input:
	@$(MAKE) INPUT_TEST=1 all

struct:
	@$(MAKE) STRUCT_TEST=1 all

clean:
	rm -f $(TEST_OBJ_FILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all input clean fclean re input struct