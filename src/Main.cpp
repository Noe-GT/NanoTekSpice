/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** Main
*/

#include "../include/AComponent.hpp"
#include "../include/Circuit.hpp"
#include "../include/CLI.hpp"

static int run(char *fname)
{
    nts::Parsing p(fname);
    nts::Circuit c(p);
    nts::CLI cli;
    cli.run();
    return 0;
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    run(av[1]);
    return 0;
}
