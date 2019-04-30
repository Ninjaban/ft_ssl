#  ----------------------------------------------------------------------------+
#                                                                              |
#   .------..------..------..------..------..------..------..------..------.   |
#   |P.--. ||R.--. ||E.--. ||V.--. ||I.--. ||S.--. ||I.--. ||O.--. ||N.--. |   |
#   | :/\: || :(): || (\/) || :(): || (\/) || :/\: || (\/) || :/\: || :(): |   |
#   | (__) || ()() || :\/: || ()() || :\/: || :\/: || :\/: || :\/: || ()() |   |
#   | '--'P|| '--'R|| '--'E|| '--'V|| '--'I|| '--'S|| '--'I|| '--'O|| '--'N|   |
#   `------'`------'`------'`------'`------'`------'`------'`------'`------'   |
#                                                                              |
#    Created by Jonathan Carra.                                                |
#    Copyright (c) 2019 Prévision. All rights reserved.                        |
#  ----------------------------------------------------------------------------+

NAME_BASE	=	ft_ssl

LIB			=	libft.a

SRC_BASE	=	main.c \
                ft_ssl.c \
                ft_ssl_usage.c \
				ft_ssl_print.c \
				ft_ssl_flags.c \
				ft_ssl_launch.c \
				ft_ssl_init.c \
				ft_ssl_tools.c \
				ft_map.c \
				md5/ft_md5_main.c \
                md5/ft_md5_init.c \
                md5/ft_md5_padding.c \
                md5/ft_md5_loop.c \
                whirlpool/ft_whirlpool_main.c \
                whirlpool/ft_whirlpool_init.c \
                whirlpool/ft_whirlpool_add.c \
                whirlpool/ft_whirlpool_process.c \
                whirlpool/ft_whirlpool_finalize.c \
				sha256/ft_sha256_main.c \
				sha256/ft_sha256_init.c \
				sha256/ft_sha256_padding.c \
				sha256/ft_sha256_loop.c
				
DIRSRC		=	sources/
DIRINC		=	include/
DIRLIB		=	library/
DIROBJ		=	objects/

LIBS		=	$(LIB:%=$(DIRLIB)%)

OBJS_BASE	=	$(addprefix $(DIROBJ), $(SRC_BASE:.c=.o))

CFLAGS		=	-Wall -Wextra -Werror -I./$(DIRINC) -I./$(DIRLIB)$(DIRINC)
LFLAGS		=

CC			=	gcc
RM			=	rm -rf
ECHO		=	printf
MAKE		=	make -sC

CLEAN		=	"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         "
LEN			=	$$(/bin/echo -n $(NAME) | wc -c)
DELTA		=	$$(echo "$$(tput cols)-32-$(LEN)"|bc)
NB			=	$(words $(SRC))
INDEX		=	0
SHELL		=	/bin/bash

all				:	$(DIROBJ) $(NAME_BASE)

$(NAME_BASE)	:	data_BASE $(OBJS_BASE)
	@$(eval OBJ_LEN=$(shell echo "$(NAME)" | wc -c))
	@$(eval CLEAN_LEN=$(shell echo "$$(tput cols)-6-$(OBJ_LEN)"|bc))
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS_BASE) $(LIBS)
	@$(ECHO) "\r\033[38;5;040m✓ MAKE $(NAME)%.*s\033[0m\033[0m\n" $(CLEAN_LEN) $(CLEAN)
data_BASE		:
	@$(eval LEN=$(shell echo $$(/bin/echo -n $(NAME_BASE) | wc -c)))
	@$(eval DELTA=$(shell echo $$(echo "$$(tput cols)-32-$(LEN)"|bc)))
	@$(eval NB=$(shell echo $(words $(SRC_BASE))))
	@$(eval INDEX=0)
	@$(eval NAME=$(shell echo $(NAME_BASE)))


$(DIROBJ)%.o	:	$(DIRSRC)%.c | $(DIROBJ)
	@$(eval DONE=$(shell echo $$(($(INDEX)*20/$(NB)))))
	@$(eval PERCENT=$(shell echo $$(($(INDEX)*100/$(NB)))))
	@$(eval TO_DO=$(shell echo $$((20-$(INDEX)*20/$(NB) - 1))))
	@$(eval COLOR=$(shell list=(20 21 26 27 32 33 38 39 44 45 50 51); index=$$(($(PERCENT) * $${#list[@]} / 100)); echo "$${list[$$index]}"))
	@$(ECHO) "\r\033[38;5;%dm⌛ [%s]: %2d%% `printf '█%.0s' {0..$(DONE)}`%*s❙%*.*s\033[0m\033[0m" $(COLOR) $(NAME) $(PERCENT) $(TO_DO) "" $(DELTA) $(DELTA) "$(shell echo "$@" | sed 's/^.*\///')"
	@$(CC) $(CFLAGS) -MMD -c $< -o $@
	@$(eval OBJ_LEN=$(shell echo "$$(echo "$@" | sed 's/^.*\///')" | wc -c))
	@$(eval CLEAN_LEN=$(shell echo "$$(tput cols)-1-$(OBJ_LEN)"|bc))
	@$(ECHO) "\r\033[38;5;%dm✓ %s\033[0m\033[0m%.*s\n\033[38;5;%dm⌛ [%s]: %2d%% `printf '█%.0s' {0..$(DONE)}`%*s❙%*.*s\033[0m\033[0m"  $(COLOR) "$(shell echo "$@" | sed 's/^.*\///')"  $(CLEAN_LEN) $(CLEAN) $(COLOR) $(NAME) $(PERCENT) $(TO_DO) "" $(DELTA) $(DELTA) "$(shell echo "$@" | sed 's/^.*\///')"
	@$(eval INDEX=$(shell echo $$(($(INDEX)+1))))


$(DIROBJ)		:
	@$(MAKE) $(DIRLIB)
	@mkdir -p $(DIROBJ)
	@$(eval SUBDIR=$(shell echo $(SRC_BASE) | grep -oE "[a-zA-Z0-9_]+/" | sed -E "s@(.*)@$(DIROBJ)\1@g" | uniq))
	@mkdir -p $(SUBDIR)

clean			:
	@$(MAKE) $(DIRLIB) clean
	@if [ -e $(DIROBJ) ];											\
	then															\
		$(RM) $(DIROBJ);											\
		$(ECHO) "\033[38;5;202m✗ Objects\033[0m\033[0m\n";			\
	fi;

fclean			:	clean
	@$(MAKE) $(DIRLIB) fclean
	@if [ -e $(NAME_BASE) ];										\
	then															\
		$(RM) $(NAME_BASE);											\
		$(ECHO) "\033[38;5;196m✗ $(NAME_BASE)\033[0m\033[0m\n";		\
	fi;

re				:	fclean all

.PHONY			:	all fclean clean re data_BASE
