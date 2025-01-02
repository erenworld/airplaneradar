##
## EPITECH PROJECT, 2024
## day
## File description:
## project
##

NAME	=	my_radar

SRC	=	./src/main.c \
	./src/get_size.c \
	./src/linkedlist.c \
	./lib/my_putchar.c \
	./lib/my_putstr.c \
	./lib/my_strcmp.c \
	./lib/my_strcpy.c \
	./lib/my_strdup.c \
	./lib/my_strlen.c \
	./lib/my_swap.c \
	./lib/my_putnbr.c \
	./lib/my_revstr.c \
	./lib/my_strcat.c \
	./lib/my_strncat.c \
	./lib/my_strncpy.c \
	./lib/my_str_to_array.c \
	./lib/my_str_array_space.c

CFLAGS	=	-W -Wall -Wextra

OBJ	=	$(SRC:.c=.o)

CSFML	=		-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

MAC_ONE	=	-L/opt/homebrew/Cellar/csfml/2.6.1/lib

MAC_TWO	=	-I/opt/homebrew/Cellar/csfml/2.6.1/include

MAC_THREE = -Wno-deprecated-declarations

all:
	gcc -g $(SRC) -o $(NAME) $(MAC_ONE) $(MAC_TWO) $(CSFML) $(MAC_THREE)

clean:
	rm -f a.out
	rm -f my_radar
	find . -name "*.o" -type f -delete

fclean: clean

re: fclean all
