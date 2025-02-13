##
## EPITECH PROJECT, 2025
## NanoTekSpice
## File description:
## Makefile
##

CC	=	g++

SRC	=	src/Main.cpp					\
		src/Exception.cpp				\
		src/Connection.cpp				\
		src/AComponent.cpp				\
		src/AndGate.cpp					\
		src/OrGate.cpp

OBJ	=	$(SRC:src/%.cpp=bin/%.o)

CPPFLAGS	=	-std=c++20 -Wall -Wextra -Werror -g3

EXEC	=	nanotekspice

all:	$(EXEC)

$(EXEC):	$(OBJ)
	$(CC) -o $(EXEC) -I include $(OBJ)

bin/%.o:	src/%.cpp
	@mkdir -p bin
	$(CC) -c $< -o $@ $(CPPFLAGS)

clean:
	rm -rf bin

fclean:	clean
	rm -f $(EXEC)

re:	fclean all

.PHONY:	all clean fclean re
