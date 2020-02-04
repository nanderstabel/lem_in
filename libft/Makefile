# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mgross <mgross@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/28 13:12:07 by mgross         #+#    #+#                 #
#    Updated: 2020/01/28 16:45:19 by mgross        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Usage
# make		# compile all binarys to a archive file
# clean		# removes all object files
# fclean	# runs clean & removes $(NAME)
# re		# runs fclean & make 

SHELL = /bin/sh 

NAME = libft.a

LIBFT_OBJ_FILE_NAMES := ft_libft_obj_file_names.txt

LIBFT_OBJ_FILES := $(shell cat $(LIBFT_OBJ_FILE_NAMES))

FT_PRINTF_OBJ_FILE_NAMES := ./ft_printf/ft_printf_obj_file_names.txt

FT_PRINTF_OBJ_FILES := $(addprefix ./ft_printf, $(shell cat \
$(FT_PRINTF_OBJ_FILE_NAMES)))

INCL_DIR = includes/

HEADER_FILES = $(INCL_DIR)libft.h $(INCL_DIR)ft_printf.h

CFLAGS = -Wall -Wextra -Werror -I

all: $(NAME)

$(NAME): $(LIBFT_OBJ_FILES) $(FT_PRINTF_OBJ_FILES)
	@ar rcs $@ $^
	@echo $(NAME) "compiled."

%.o: %.c $(HEADER_FILES)
	$(CC) -c $(CFLAGS)$(INCL_DIR) -o $@ $<

norm:
	@echo "----libft files:----"
	@norminette $(LIBFT_OBJ_FILES:%.o=%.c) $(FT_PRINTF_OBJ_FILES:%.o=%.c) \
	$(INCL_DIR)
	
clean:
	@rm -f $(LIBFT_OBJ_FILES) $(FT_PRINTF_OBJ_FILES)
	@echo "libft clean succes."

fclean: clean
	@rm -f $(NAME)
	@echo "libft fclean succes."

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all norm clean fclean re
