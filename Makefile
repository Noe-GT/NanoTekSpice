##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile for cpp
##

CC	=	g++

SRC	=	src/Main.cpp \

OBJ	=	$(SRC:%.cpp=%.o)

CFLAGS	=	-std=c++20 -Wall -Wextra -Werror -g

EXEC	=	nanotekspice

all:	 $(EXEC)

$(EXEC):	$(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(EXEC)

re:	fclean all

# cmake ?

.PHONY:	all compile_lib clean fclean re
