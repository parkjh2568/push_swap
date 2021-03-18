# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhypar <junhypar@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/15 07:31:46 by junhypar          #+#    #+#              #
#    Updated: 2021/03/18 11:48:19 by junhypar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

U_NAME	=	utils
C_NAME	=	checker
P_NAME	=	push_swap


U_SRCS	=	./gnl/get_next_line.c ./gnl/get_next_line_utils.c \
			./utils/ft_lstfree.c ./utils/ft_lstnew_chardata.c \
			./utils/ft_lstreset.c ./utils/is_available.c \
			./utils/ft_error.c	./utils/ft_lstlen.c \
			./utils/ft_command_solo.c ./utils/ft_command_duo.c \
			./utils/print_data.c

C_SRCS	=	checker.c

P_SRCS	=


U_OBJS	=	${U_SRCS:.c=.o}
C_OBJS	=	${C_SRCS:.c=.o}
P_OBJS	=	${P_SRCS:.c=.o}


U_LIB	=	libutils.a
C_LIB	=	libchecker.a
P_LIB	=	libpush_swap.a


CC		=	gcc -Wall -Werror -Wextra


MKLIBFT	=	mklibft
DILIBFT	=	./libft
LIBFT	=	./libft/libft.a


all:		${MKLIBFT} ${U_NAME} ${C_NAME} #${P_NAME}


.c.o:
			${CC} -c $< -o ${<:.c=.o}


${MKLIBFT}:
			$(MAKE) bonus -C ${DILIBFT}


${U_NAME}:	${U_OBJS}
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
			rm -f ${U_LIB}


fclean:		clean
			$(MAKE) fclean -C ${DILIBFT}
			rm -f ${C_NAME}
			rm -f ${P_NAME}


re:			fclean all


.PHONY: all clean fclean re .c.o

