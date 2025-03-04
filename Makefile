##
## EPITECH PROJECT, 2025
## NanoTekSpice
## File description:
## Makefile
##

CC	=	g++

MAIN	=	src/Main.cpp	\

SRC	=	src/Exception.cpp 	\
		src/Parsing.cpp		\
		src/Circuit.cpp		\
		src/Pin.cpp			\
		src/Connection.cpp	\
		src/CLI.cpp			\
		src/components/AComponent.cpp	\
		src/components/AndGate.cpp		\
		src/components/OrGate.cpp		\
		src/components/XorGate.cpp		\
		src/components/NotGate.cpp		\
		src/components/specialComponents/SCClock.cpp		\
		src/components/specialComponents/SCInput.cpp		\
		src/components/specialComponents/SCTrue.cpp		\
		src/components/specialComponents/SCFalse.cpp		\
		src/components/specialComponents/SCOutput.cpp	\
		src/components/gateComponents/GC4011.cpp	\
		src/components/CD4030.cpp		\

TEST	=	tests/src/TestBasicGates.cpp	\
			tests/src/TestSC.cpp			\

MAIN_OBJ	=	$(MAIN:src/%cpp=bin/%o)

OBJ	=	$(SRC:src/%cpp=bin/%o)

TEST_OBJ	=	$(TEST:tests:.cpp=bin:.o)

CPPFLAGS	=	-std=c++20 -Wall -Wextra -Werror -g3

CRITERION	=	--coverage -lcriterion

EXEC	=	nanotekspice

TEST_EXEC	=	unit_tests

all:	$(EXEC)

$(EXEC):	$(MAIN_OBJ) $(OBJ)
	$(CC) -o $(EXEC) $(MAIN_OBJ) $(OBJ) -I include

tests_run:	$(OBJ) $(TEST_OBJ)
	$(CC) -o $(TEST_EXEC) $(OBJ) $(TEST_OBJ) $(CRITERION) -I include
	./$(TEST_EXEC)

bin/%.o:	src/%.cpp
	@mkdir -p bin
	@mkdir -p bin/components
	@mkdir -p bin/components/specialComponents
	@mkdir -p bin/components/gateComponents
	$(CC) -c $< -o $@ $(CPPFLAGS)

bin/%.o:	tests/%.cpp
	$(CC) -c $< -o $@ $(CPPFLAGS)

clean:
	rm -rf bin
	rm -f *gcno
	rm -f *gcda

fclean:	clean
	rm -f $(EXEC)
	rm -f unit_tests

re:	fclean all

.PHONY:	all clean fclean re tests_run
