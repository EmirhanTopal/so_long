NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
FILES = ft_printf.c staticfunctions.c

OBJECTS = $(FILES:.c=.o)

all: ${NAME}

$(NAME): $(OBJECTS) 
	$(AR) $(NAME) $(OBJECTS)

clean:
	${RM} ${OBJECTS}

fclean: clean
	${RM} ${NAME}

re: fclean all

