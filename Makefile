SRCS = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_unbr.c ft_putnbr_base.c
NAME = libftprintf.a
LIBC = ar -rcs
OBJS = ${SRCS:.c=.o}
CC = cc
FLAGS = -Wall -Werror -Wextra
RM = rm -f
INCS = .

all: ${NAME}

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

clean:
	${RM} ${OBJS} ${OBJS_B}

fclean: clean
	${RM} ${NAME}

re: fclean all