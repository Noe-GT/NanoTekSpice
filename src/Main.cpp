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
    nts::Parsing p("test.nts");

    p.printFile(2);
    return 0;
}
