##
## EPITECH PROJECT, 2025
## NanoTekSpice
## File description:
## Makefile
##

CC	=	g++

SRC	=   src/Exception.cpp 	\
		src/Parsing.cpp		\
		src/Circuit.cpp		\
		src/AComponent.cpp	\
		src/Pin.cpp			\
		src/Connection.cpp	\
		src/AndGate.cpp		\
		src/OrGate.cpp		\
		src/XorGate.cpp		\
		src/NotGate.cpp		\
		src/SCClock.cpp		\
		src/SCInput.cpp		\
		src/SCTrue.cpp		\
		src/SCFalse.cpp		\
		src/CLI.cpp			\
		src/SCOutput.cpp	\
		# src/CD4030.cpp		\

TEST_SRC =	tests/TestBasicGates.cpp \
			tests/TestSC.cpp

OBJ	=	$(SRC:src/%.cpp=bin/%.o)

CPPFLAGS	=	-std=c++20 -Wall -Wextra -Werror -g3

CRITERION	=	--coverage -lcriterion

EXEC	=	nanotekspice

all:	$(EXEC)

$(EXEC):
	$(CC) -o $(EXEC) -I include $(SRC) src/Main.cpp

tests_run:
	$(CC) -o unit_tests $(SRC) $(TEST_SRC) $(CRITERION)
	./unit_tests

bin/%.o:	src/%.cpp
	@mkdir -p bin
	$(CC) -c $< -o $@ $(CPPFLAGS)

clean:
	rm -rf bin
	rm -f *gcno
	rm -f *gcda

fclean:	clean
	rm -f $(EXEC)
	rm -f unit_tests

re:	fclean all

.PHONY:	all clean fclean re
