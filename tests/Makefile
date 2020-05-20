# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mgross <mgross@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/02/06 08:47:04 by mgross         #+#    #+#                 #
#    Updated: 2020/03/12 11:35:30 by mgross        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include ./test_obj_files
include ../obj_files

#### HOW TO ADD TESTS to Makefile ####

# Add name of source file in the *.o extension to the file "test_obj_files".
## Example: ALL_TESTS := test_file1.o test_file.o

NAME = unit_test

TEST_MAIN = test_main

TEST_MAIN_OBJ = ./srcs/test_main.o

PROJECT_OBJ_FILES := $(filter-out ../srcs/main.o,$(addprefix ../srcs/, \
$(PROJECT_OBJ_FILES)))

ALL_TEST_OBJ_FILES := $(addprefix ./srcs/, $(ALL_TESTS))

INC_DIR = ./includes/

HEADER_FILES = $(INC_DIR)tests.h

LIB = -L ../libft/ -lft

CFLAGS = -Wall -Wextra -Werror -g

DEPS = -Iincludes/ -I../libft/includes/ -I../includes/

LIB = -L ../libft/ -lft

all: $(NAME)

$(NAME): $(ALL_TEST_OBJ_FILES) $(PROJECT_OBJ_FILES)
	@$(CC) -o $@ $^ -I$(INC_DIR) -lcriterion $(LIB) $(CFLAGS)
	@echo "Unit test compiled."

run:
	@echo "\n"
	@./unit_test
	@echo "\n"

%.o: %.c $(HEADER_FILES)
	@$(CC) -c $(CFLAGS) $(DEPS) -o $@ $<

test_main: $(TEST_MAIN_OBJ) $(PROJECT_OBJ_FILES)
	@$(CC) -o $(TEST_MAIN) $^ -I$(INC_DIR) $(LIB) $(CFLAGS)
	@./test_main

clean:
	@rm -f $(ALL_TEST_OBJ_FILES) $(TEST_MAIN_OBJ)

fclean: clean
	@rm -rf $(NAME) $(TEST_MAIN)

re: fclean all

.PHONY: all clean fclean re run test_main
