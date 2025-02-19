/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** CLI
*/

#include "../include/CLI.hpp"

nts::CLI::CLI()
{
    this->_tick = 0;
}

nts::CLI::CLI(nts::Circuit &circuit): _circuit(circuit)
{
    this->_tick = 0;
}

nts::CLI::~CLI()
{
}

void nts::CLI::setCircuit(nts::Circuit &circuit)
{
    this->_circuit = circuit;
}

void nts::CLI::exit() const
{
    std::exit(0);
}

void nts::CLI::display() const
{
    std::cout << "tick: " << this->_tick << std::endl;
    std::cout << "input(s):" << std::endl;
    std::cout << "outputs(s):" << std::endl;
    // std::vector<std::shared_ptr<nts::IComponent>> &outputs = this->_circuit->getOutputs();

    // for (std::shared_ptr<nts::IComponent> out : outputs)
    //     out->();
}

void nts::CLI::simulate()
{
    for (std::shared_ptr<nts::IComponent> out : this->_circuit.getOutputs())
        out->simulate(1);
    this->_tick++;
}

void nts::CLI::loop()
{
    while (1) {
        this->simulate();
        this->display();
    }
}

void nts::CLI::run()
{
    std::string buff;

    while (1) {
        std::cout << "> ";
        std::getline(std::cin, buff);
        if (buff == "display")
            this->display();
        if (buff == "exit")
            this->exit();
        if (buff == "loop")
            this->loop();
        if (buff == "simulate")
            this->simulate();
    }
}

nts::Circuit &nts::CLI::getCircuit()
{
    return this->_circuit;
}
