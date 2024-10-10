CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
SRC:
OBJS:$(SRC:.c=.o)


all:

%.o:%.c

clean:
	rm -rsc
fclean:
	rm -rsc
re: clean all
