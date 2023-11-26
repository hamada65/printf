SRCS = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_unbr.c ft_putnbr_base.c ft_putvoid.c
NAME = libftprintf.a
LIBC = ar -rcs
OBJS = ${SRCS:.c=.o}
CC = cc
FLAGS = -Wall -Werror -Wextra
RM = rm -f

all: ${NAME}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

clean:
	${RM} ${OBJS} ${OBJS_B}

fclean: clean
	${RM} ${NAME}

re: fclean all