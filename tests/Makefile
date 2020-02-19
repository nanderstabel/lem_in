# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mgross <mgross@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/02/06 08:47:04 by mgross         #+#    #+#                 #
#    Updated: 2020/02/19 14:51:59 by mgross        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include ./test_obj_files
include ../obj_files

#### HOW TO ADD TESTS to Makefile ####

# Add name of source file in the *.o extension to the file "test_obj_files".
## Example: ALL_TESTS := test_file1.o test_file.o

NAME = unit_test

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
	@$(CC) -o $@ $^ -I$(INC_DIR) -lcriterion $(LIB)
	@echo "Unit test compiled.\n"

run:
	@echo "		========== Run Tests =========="
	@./unit_test

%.o: %.c $(HEADER_FILES)
	@$(CC) -c $(CFLAGS) $(DEPS) -o $@ $<

clean:
	rm -f $(ALL_TEST_OBJ_FILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re run
