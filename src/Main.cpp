/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** Main
*/

#include "../include/AComponent.hpp"
#include "../include/Circuit.hpp"
#include "../include/CLI.hpp"

int main()
{
    // nts::CLI cli;

    // cli.Run();

    nts::Parsing p("or_gate.nts");
    p.debug();
    nts::Circuit c(p);
    return 0;
}
