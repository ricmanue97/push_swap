# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ricmanue < ricmanue@student.42lisboa.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/24 10:31:38 by ricmanue          #+#    #+#              #
#    Updated: 2024/07/25 11:14:37 by ricmanue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCS	=	${wildcard *.c}


CC	=	@cc
CFLAGS	=	-Wall -Werror -Wextra
OBJS	=	${SRCS:.c=.o}
RM	=	@rm -f

all: ${NAME}

${NAME}: ${OBJS}
	@echo "Created .o files and executable."
	${CC} ${OBJS} -o ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $^ -o $@

fclean: clean
	${RM} ${NAME}
	@echo "Cleaned executable."

clean:
	${RM} -f ${OBJS}
	@echo "Cleaned .o files."

re: fclean all

.PHONY: all fclean clean re .c.o