# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 15:30:27 by xbeheydt          #+#    #+#              #
#    Updated: 2021/11/29 06:44:35 by xbeheydt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean mandatory bonus

SRCS		= test_main.c
INCLUDES	= deps/cunits42/include \
			  pipex \
			  .
LINKS		= deps/cunits42/lib \
			  pipex
LIBS		= cunits42 \
			  pipex

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g3
IFLAGS		= $(addprefix -I, ${INCLUDES})
LDFLAGS		= $(addprefix -L, ${LINKS})
LFLAGS		= $(addprefix -l, ${LIBS})

RM			= rm -rf

clean:
	$(MAKE) -C pipex clean
	$(MAKE) -C deps/cunits42 clean

fclean:
	$(MAKE) -C pipex fclean
	$(MAKE) -C deps/cunits42 fclean
	$(RM) a.out

mandatory:
	$(MAKE) -C deps/cunits42 all
	$(MAKE) -C pipex mandatory
	$(CC) ${CFLAGS} ${IFLAGS} -DINTERNAL -DMANDATORY ${LDFLAGS} -o a.out $(addprefix tests/, ${SRCS}) ${LFLAGS}

bonus:
	$(MAKE) -C deps/cunits42 all
	$(MAKE) -C pipex bonus
	$(CC) ${CFLAGS} ${IFLAGS} -DINTERNAL -DBONUS ${LDFLAGS} -o a.out $(addprefix tests/, ${SRCS}) ${LFLAGS}

re: fclean mandatory

build:
	$(MAKE) -C pipex bonus

install: build
	mkdir -p ~/.local/bin
	install -D -m 755 ./pipex/pipex ~/.local/bin/pipex
