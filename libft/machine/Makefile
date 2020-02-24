# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nstabel <nstabel@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/02/19 13:26:04 by nstabel        #+#    #+#                 #
#    Updated: 2020/02/19 13:28:13 by nstabel       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include machine_obj_files

# Usage
# make		# compile all binarys to a archive file
# clean		# removes all object files
# fclean	# runs clean & removes $(NAME)
# re		# runs fclean & make 

SHELL = /bin/sh 

NAME = machine.a

OBJ_FILES := $(addprefix ./srcs/, $(MACHINE_OBJ_FILES))

INCL_DIR = includes/

HEADER_FILES = $(INCL_DIR)machine.h

CFLAGS = -Wall -Wextra -Werror -I

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@ar rcs $@ $^
	@echo $(NAME) "compiled."

%.o: %.c $(HEADER_FILES)
	@$(CC) -c $(CFLAGS)$(INCL_DIR) -o $@ $<

clean:
	@rm -f $(OBJ_FILES)
	@echo "machine clean succes."

fclean: clean
	@rm -f $(NAME)
	@echo "machine fclean succes."

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
