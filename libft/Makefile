# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mgross <mgross@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/28 13:12:07 by mgross        #+#    #+#                  #
#    Updated: 2020/05/20 13:54:54 by nstabel       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include ./ft_printf/ft_printf_obj_files
include ./machine/machine_obj_files
include ft_libft_obj_files

# Usage
# make		# compile all binarys to a archive file
# clean		# removes all object files
# fclean	# runs clean & removes $(NAME)
# re		# runs fclean & make 

SHELL = /bin/sh 

NAME = libft.a

FT_PRINTF_OBJECT_FILES := $(addprefix ./ft_printf/srcs/, \
$(FT_PRINTF_OBJ_FILES))

MACHINE_OBJECT_FILES := $(addprefix ./machine/srcs/, \
$(MACHINE_OBJ_FILES))

INCL_DIR = includes/

HEADER_FILES = $(INCL_DIR)libft.h $(INCL_DIR)ft_printf.h $(INCL_DIR)machine.h

CFLAGS = -Wall -Wextra -Werror -I

all: $(NAME)

$(NAME): $(LIBFT_OBJ_FILES) $(FT_PRINTF_OBJECT_FILES)
	@ar rcs $@ $^
	@echo $(NAME) "compiled."

%.o: %.c $(HEADER_FILES)
	@$(CC) -c $(CFLAGS)$(INCL_DIR) -o $@ $<

norm:
	@echo "----libft files:----"
	@norminette $(LIBFT_OBJ_FILES:%.o=%.c) $(FT_PRINTF_OBJECT_FILES:%.o=%.c) \
	$(MACHINE_OBJECT_FILES:%.o=%.c) $(INCL_DIR)
	
clean:
	@rm -f $(LIBFT_OBJ_FILES) $(FT_PRINTF_OBJECT_FILES) $(MACHINE_OBJECT_FILES)
	@echo "libft clean succes."

fclean: clean
	@rm -f $(NAME)
	@echo "libft fclean succes."

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all norm clean fclean re objects
