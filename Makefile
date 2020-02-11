# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mgross <mgross@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/08/08 10:14:38 by mgross         #+#    #+#                 #
#    Updated: 2020/02/11 11:15:17 by mgross        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include ./obj_files
include ./libft/ft_libft_obj_files
include ./libft/ft_printf/ft_printf_obj_files
-include ./bonus/obj_files
-include ./tests/test_obj_files

#### Start of project specific section. ####

NAME = lem-in

HEADER_FILES = $(INC_DIR)lem_in.h 

#### End project specific section. ####

REG_BONUS_FILES := $(addprefix ./srcs/bonus/, $(BONUS_OBJ_FILES))

REG_OBJ_FILES := $(addprefix ./srcs/, $(PROJECT_OBJ_FILES))

LIBFT_OBJ_FILES := $(addprefix ./libft/, $(LIBFT_OBJ_FILES)) \
$(addprefix ./libft/ft_printf/srcs/, $(FT_PRINTF_OBJ_FILES))

INC_DIR = includes/

LIBFT_INC_DIR = libft/includes/

LIBFT_HEADER_FILES = ./libft/includes/libft.h ./libft/includes/ft_printf.h 

LIB = -L ./libft/ -lft

CFLAGS = -Wall -Wextra -Werror

DEPS = -I$(INC_DIR) -I$(LIBFT_INC_DIR)

MAX_PARALLEL = 6

TYPE = 

ifdef WITH_BONUS
ifeq (, $(shell cat $(REG_BONUS_FILE_TXT)))
$(error "Path to bonus obj_files.txt not specified.")
endif
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

test:
	@$(MAKE) $(TYPE) -C tests/

run_test:
	@./tests/unit_test
	
norm:
	@echo "----project files----"
	@norminette $(OBJ_FILES:%.o=%.c) $(INC_DIR)
	@make norm -C ./libft

clean:
	@rm -f $(REG_OBJ_FILES) $(REG_BONUS_FILES) $(LIBFT_OBJ_FILES) $(addprefix \
	./tests/srcs/, $(ALL_TESTS))
	@echo "clean succes."

fclean: clean
	@rm -rf $(NAME) ./tests/unit_test
	@rm -rf ./libft/libft.a
	@echo "fclean succes."

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all bonus multi libft norm clean fclean re tests run_test
 