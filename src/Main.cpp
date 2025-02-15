/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** Main
*/

#include "../include/AComponent.hpp"
#include "../include/Parsing.hpp"

int main()
{
    nts::Parsing p("or_gate.nts");

    // p.printFile();
    p.parseFile();
    return 0;
}
