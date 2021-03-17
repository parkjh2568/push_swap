# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/15 07:31:46 by junhypar          #+#    #+#              #
#    Updated: 2021/03/17 15:53:14 by junhypar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_NAME	=	checker
P_NAME	=	push_swap



C_SRCS	=	./utils/*.c checker.c

P_SRCS	=	./utils/*.c



C_OBJS	=	${C_SRCS:.c=.o}
P_OBJS	=	${P_SRCS:.c=.o}



C_LIB	=	libchecker.a
P_LIB	=	libpush_swap.a


CC		=	gcc -Wall -Werror -Wextra


MKLIBFT	=	mklibft
DILIBFT	=	./libft
LIBFT	=	./libft/libft.a

all:		${MKLIBFT} ${C_NAME} ${P_NAME}

.c.o:
			${CC} -c $< -o ${<:.c=.o}

${MKLIBFT}:
			$(MAKE) bonus -C ${DILIBFT}

${C_NAME}:	${C_OBJS}
			cp ${LIBFT} ${C_LIB}
			${CC} -o ${C_NAME} -L. -l${C_NAME}


${P_NAME}:	${P_OBJS}
			cp ${LIBFT} ${P_LIB}
			${CC} -o ${P_NAME} -L. -l${P_NAME}


clean:
			$(MAKE) clean -C ${DILIBFT}
			rm -f ${C_OBJS}
			rm -f ${P_OBJS}
			rm -f ${P_LIB}
			rm -f ${C_LIB}

fclean:		clean
			$(MAKE) fclean -C ${DILIBFT}
			rm -f ${C_NAME}
			rm -f ${P_NAME}

re:			fclean all

.PHONY: all clean fclean re .c.o

