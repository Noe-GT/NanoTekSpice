/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** Main
*/

#include "../include/Circuit.hpp"
#include "../include/CLI.hpp"

int main(int ac, char **av)
{
    nts::Parsing parsing;
    nts::Circuit circuit;
    nts::CLI cli;

    if (ac != 2) {
        std::cerr << "Incorrect number of arguments" << std::endl;
        return 84;
    }
    try {
        parsing.setFilePath(av[1]);
        parsing.parseFile();
        circuit.constructCircuit(parsing);
        cli.setCircuit(circuit);
        cli.run();
    } catch(Exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    std::cout << "return 0" << std::endl;
    return 0;
}
