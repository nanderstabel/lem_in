# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mgross <mgross@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/02/06 08:47:04 by mgross         #+#    #+#                 #
#    Updated: 2020/02/07 19:33:45 by mgross        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include ./test_obj_files
include ../obj_files

#### HOW TO ADD TESTS ####

# Step 1: Add name of object file to the file "test_obj_files" under it's own
# variable aswell as under the ALL_TESTS variable
## Example: ALL_TESTS := test_file1.o test_file.o
## TEST1 := test_file.o

# Step 2: Add else or else ifeq statement for adding a rule to compile only one test.
# In this example I chose the name HASH_TEST for the variable and filled in
# $(TEST1) as variable from where to get the name of the object files.
## Example: else ifeq ($(HASH_TEST), 1)
## TEST_OBJ_FILES = $(addprefix ./srcs/, $(TEST1))

# Step 3: Add rule for easy compiling. Use the variable specified in step 2.
# In this example it would be HASH_TEST
## Example: hash:
##				@$(MAKE) HASH_TEST=1 all

# Step 4: Add name of the rule to the .PHONY rule at the bottem of the rules.
## Example: .PHONY: all clean fclean re hash

### aantekeningen
# Laten we het bestand waar de main in zit gewoon main noemen zodat dat
# altijd het zelfde kan blijven binnen de makefile


NAME = unit_test

PROJECT_OBJ_FILES := $(filter-out ../srcs/lem_in.o,$(addprefix ../srcs/, $(PROJECT_OBJ_FILES)))

ALL_TEST_OBJ_FILES := $(addprefix ./srcs/, $(ALL_TESTS))

INC_DIR = includes/

HEADER_FILES = $(INC_DIR)tests.h

LIB = -L ./libft/ -lft

CFLAGS = -Wall -Wextra -Werror -g

DEPS = -Iincludes/ -I../libft/includes -I../includes/

LIB = -L ../libft/ -lft

ifeq ($(INPUT_TEST), 1)
TEST_OBJ_FILES = $(addprefix ./srcs/, $(TEST1))
else ifeq ($(STRUCT_TEST), 1)
TEST_OBJ_FILES = $(addprefix ./srcs/, $(TEST2))
else
TEST_OBJ_FILES = $(ALL_TEST_OBJ_FILES)
endif

all: $(NAME)

$(NAME): $(TEST_OBJ_FILES) $(PROJECT_OBJ_FILES)
	@$(CC) -o $@ $^ -I$(INC_DIR) -lcriterion $(LIB)
	@echo "Unit test compiled."

%.o: %.c $(HEADER_FILES)
	@$(CC) -c $(CFLAGS) $(DEPS) -o $@ $<

input:
	@$(MAKE) INPUT_TEST=1 all

struct:
	@$(MAKE) STRUCT_TEST=1 all

clean:
	rm -f $(ALL_TEST_OBJ_FILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re input struct
