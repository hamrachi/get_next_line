NAME = getnextline.a
CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = get_next_line.c get_next_line_utils.c

OBJE = ${SRCS:%.c=%.o}

%.o : %.c get_next_line.h
	${CC} ${CFLAGS} -c $< -o $@ 

all : ${NAME}

${NAME} : ${OBJE}
	ar rc ${NAME} ${OBJE}

clean :
	rm -rf ${OBJE}

fclean : clean
	rm -rf ${NAME}

re : all clean 