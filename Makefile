SRCS 	 = ft_printf.c
OBJS	 = ${SRCS:.c=.o}
INCS	 = .	
NAME	 = libftprintf.a
LIBC	 = ar rc
LIBR	 = ranlib
CC		 = gcc
RM		 = rm -f
CFLAGS	 = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}
	${LIBR} ${NAME}

test: ${TEST_OBJ} ${NAME}
	${CC} ${TEST_OBJ} -L. -lftprintf -o test

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean	
	${RM} ${NAME}

re: fclean all