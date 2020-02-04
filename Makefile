# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mgross <mgross@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/08/08 10:14:38 by mgross         #+#    #+#                 #
#    Updated: 2020/02/04 17:21:12 by nstabel       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Usage
# make		# compile all binarys to a archive file
# bonus		# compile project with bonus
# multi		# run make with multible processes
# norm		# runs the norm on all .c files
# clean		# removes all object files
# fclean	# runs clean & removes $(NAME)
# re		# runs fclean & make 

#### Start of project specific section. ####

NAME =	lem-in

PROJECT_OBJ_FILE_NAMES := lem-in_obj_file_names.txt

REG_BONUS_FILES = 

INC_DIR = includes/

HEADER_FILES = $(INC_DIR)lem_in.h 

#### End project specific section. ####

REG_OBJ_FILES := $(shell cat $(PROJECT_OBJ_FILE_NAMES))

LIBFT_OBJ_FILE_NAMES := ./libft/ft_libft_obj_file_names.txt

FT_PRINTF_OBJ_FILE_NAMES := ./libft/ft_printf/ft_printf_obj_file_names.txt

LIBFT_OBJ_FILES := $(addprefix ./libft/, $(shell cat $(LIBFT_OBJ_FILE_NAMES))) \
$(addprefix ./libft/ft_printf, $(shell cat $(FT_PRINTF_OBJ_FILE_NAMES)))

LIBFT_INC_DIR = libft/includes/

LIBFT_HEADER_FILES = ./libft/includes/libft.h ./libft/includes/ft_printf.h 

LIB = -L ./libft/ -lft


CFLAGS = -Wall -Wextra -Werror

# UTEST_CFLAGS = -Wall -Wextra -Werror -g

DEPS = -I$(INC_DIR) -I$(LIBFT_INC_DIR)

MAX_PARALLEL = 6

ifdef WITH_BONUS
OBJ_FILES = $(REG_OBJ_FILES) $(REG_BONUS_FILES)
else
OBJ_FILES = $(REG_OBJ_FILES)
endif

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT_OBJ_FILES)
	@make -C ./libft
	@$(CC) -o $@ $^ $(LIB)
	@echo $(NAME) "compiled."

%.o: %.c $(HEADER_FILES) $(LIBFT_HEADER_FILES)
	@$(CC) -c $(CFLAGS) $(DEPS) -o $@ $<

bonus:
	@$(MAKE) WITH_BONUS=1 all

multi:
	@$(MAKE) -j$(MAX_PARALLEL) all

# test: 
# 	$(CFLAGS) := $(CFLAGS)-g
# 	$(MAKE) all

norm:
	@echo "----project files----"
	@norminette $(OBJ_FILES:%.o=%.c) $(INC_DIR)
	@make norm -C ./libft

clean:
	@rm -f $(REG_OBJ_FILES) $(REG_BONUS_FILES) $(LIBFT_OBJ_FILES)
	@echo "clean succes."

fclean: clean
	@rm -rf $(NAME)
	@echo "fclean succes."

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all bonus multi libft norm clean fclean re