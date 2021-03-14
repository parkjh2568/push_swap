# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/15 07:31:46 by junhypar          #+#    #+#              #
#    Updated: 2021/03/15 07:54:03 by junhypar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_NAME	=	checker

P_NAME	=	push_swap

C_SRCS	=

P_SRCS	=

C_OBJS	=	${C_SRCS: .c=.o}

P_OBJS	=	${P_SRCS: .c=.o}

CC		=	gcc -Wall -Werror -Wextra

LIBFT	=	./libft

all:		${C_NAME} ${P_NAME}

.c.o:
			${CC} -c $< -o ${<:.c=.o}



${C_NAME}:	



${P_NAME}:


clean:


fclean:


re:

.PHONY: all clean fclean re

