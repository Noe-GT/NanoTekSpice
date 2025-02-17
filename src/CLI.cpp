/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** CLI
*/

#include "../include/CLI.hpp"

// nts::CLI::CLI(nts::Circuit &circuit):
// _circuit(circuit)
// {
//     this->_tick = 0;
// }

nts::CLI::CLI()
{
    this->_tick = 0;
}

nts::CLI::~CLI()
{
}

void nts::CLI::Exit() const
{
    exit(0);
}

void nts::CLI::Display() const
{
    std::cout << "tick: " << this->_tick << std::endl;
    std::cout << "input(s):" << std::endl;
    std::cout << "outputs(s):" << std::endl;
}

void nts::CLI::Simulate()
{
    this->_tick++;
}

void nts::CLI::Loop()
{
    while (1) {
        this->Simulate();
        this->Display();
    }
}

void nts::CLI::Run()
{
    std::string buff;

    while (1) {
        std::cout << "> ";
        std::getline(std::cin, buff);
        if (buff == "display")
            this->Display();
        if (buff == "exit")
            this->Exit();
        if (buff == "loop")
            this->Loop();
        if (buff == "simulate")
            this->Simulate();
    }
}
