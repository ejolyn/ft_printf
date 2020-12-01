# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejolyn <ejolyn@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/17 15:50:36 by ejolyn            #+#    #+#              #
#    Updated: 2020/11/27 10:42:44 by ejolyn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 	ft_atoi.c ft_putnbr_fd.c ft_printf.c ft_strlen.c parser.c processor.c ft_strchr.c ft_isdigit.c processor_numbers.c processor_16x.c \
				processor_pointer.c

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
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re