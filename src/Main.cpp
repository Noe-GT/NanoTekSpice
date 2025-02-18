/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** Main
*/

#include "../include/AComponent.hpp"
// #include "../include/Circuit.hpp"
// #include "../include/CLI.hpp"
#include <memory>
#include "../include/AndGate.hpp"
#include "../include/OrGate.hpp"

int main()
{
    std::shared_ptr<nts::IComponent> test1(new nts::component::AndGate("AND"));
    std::shared_ptr<nts::IComponent> test2(new nts::component::OrGate("OR"));

    test1->setLink(3, *test2, 1);

    // nts::CLI cli;

    // cli.Run();

    // nts::Parsing p("or_gate.nts");
    // p.debug();
    // nts::Circuit c(p);
    return 0;
}
