# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejolyn <ejolyn@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/17 15:50:36 by ejolyn            #+#    #+#              #
#    Updated: 2020/11/23 17:42:51 by ejolyn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 	ft_atoi.c ft_itoa.c ft_printf.c ft_strlen.c parser.c processor.c ft_strchr.c ft_isdigit.c

OBJS		=	${SRCS:.c=.o}

NAME		=	libftprintf.a

INCLUDE		=	ft_printf.h

RM			=	rm -f

AR			=	ar rc

CFLAGS		=	-Wall -Werror -Wextra

.c.o: 		${OBJS} ${INCLUDE}
			gcc ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS} ${INCLUDE}
			${AR} ${NAME} ${OBJS}
			ranlib ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS} ${BONOBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re