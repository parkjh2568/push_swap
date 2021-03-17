# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/15 07:31:46 by junhypar          #+#    #+#              #
#    Updated: 2021/03/17 16:17:07 by junhypar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_NAME	=	checker
P_NAME	=	push_swap


U_OBJS	=	./utils/ft_lstfree.c ./utils/ft_lstnew_chardata.c

C_SRCS	=	checker.c

P_SRCS	=



C_OBJS	=	${C_SRCS:.c=.o}
P_OBJS	=	${P_SRCS:.c=.o}


U_LIB	=	libutils.a
C_LIB	=	libchecker.a
P_LIB	=	libpush_swap.a


CC		=	gcc -Wall -Werror -Wextra


MKLIBFT	=	mklibft
DILIBFT	=	./libft
LIBFT	=	./libft/libft.a


all:		${MKLIBFT} ${C_NAME} #${P_NAME}


.c.o:
			${CC} -c $< -o ${<:.c=.o}


${MKLIBFT}:	${U_OBJS}
			$(MAKE) bonus -C ${DILIBFT}
			cp ${LIBFT} ${U_LIB}
			ar rc ${U_LIB} ${U_OBJS}


${C_NAME}:	${C_OBJS}
			cp ${U_LIB} ${C_LIB}
			ar rc ${C_LIB} ${C_OBJS}
			${CC} -o ${C_NAME} -L. -l ${C_NAME}


${P_NAME}:	${P_OBJS}
			cp ${U_LIB} ${P_LIB}
			ar rc ${P_LIB} ${P_OBJS}
			${CC} -o ${P_NAME} -L. -l${P_NAME}


clean:
			$(MAKE) clean -C ${DILIBFT}
			rm -f ${C_OBJS}
			rm -f ${P_OBJS}
			rm -f ${U_OBJS}
			rm -f ${P_LIB}
			rm -f ${C_LIB}
			rm =f ${U_LIB}


fclean:		clean
			$(MAKE) fclean -C ${DILIBFT}
			rm -f ${C_NAME}
			rm -f ${P_NAME}


re:			fclean all


.PHONY: all clean fclean re .c.o

