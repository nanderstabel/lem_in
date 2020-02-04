# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mgross <mgross@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/05/21 10:58:41 by mgross         #+#    #+#                 #
#    Updated: 2020/01/21 10:33:51 by mgross        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Usage
# make		# compile all binarys to a archive file
# clean		# removes all object files
# fclean	# runs clean & removes $(NAME)
# re		# runs fclean & make 

SHELL = /bin/sh 

NAME = ft_printf.a

FT_PRINTF_OBJ_FILE_NAMES := ft_printf_obj_file_names.txt

OBJ_FILES := $(addprefix ., $(shell cat $(FT_PRINTF_OBJ_FILE_NAMES)))

INCL_DIR = includes/

HEADER_FILES = $(INCL_DIR)ft_printf.h

CFLAGS = -Wall -Wextra -Werror -I

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@ar rcs $@ $^
	@echo $(NAME) "compiled."

%.o: %.c $(HEADER_FILES)
	$(CC) -c $(CFLAGS)$(INCL_DIR) -o $@ $<

clean:
	@rm -f $(OBJ_FILES)
	@echo "ft_printf clean succes."

fclean: clean
	@rm -f $(NAME)
	@echo "ft_printf fclean succes."

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
