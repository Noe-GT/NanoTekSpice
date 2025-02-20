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

void nts::CLI::display()
{
    nts::Tristate val;

    std::cout << "tick: " << this->_tick << std::endl;
    std::cout << "input(s):" << std::endl;
    std::cout << "outputs(s):" << std::endl;
    for (std::shared_ptr<nts::IComponent> out : this->getCircuit().getOutputs()) {
        val = out->compute(1);
        std::cout << "  " << out->getName() << ": ";
        if (val == -1)
            std::cout << "U" << std::endl;
        else
            std::cout << val << std::endl;
    }
}

void nts::CLI::simulate()
{
    for (std::shared_ptr<nts::IComponent> out : this->getCircuit().getOutputs())
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

void nts::CLI::setInput(std::string buff)
{
    std::vector<std::string> vect;
    std::istringstream iss(buff);
    std::string token;

    while (std::getline(iss, token, '='))
    {
        vect.push_back(token);
    }
    if (vect.size() != 2 ||
        (vect[1] != "U" && vect[1] != "0" && vect[1] != "1"))
        return;
    for (std::shared_ptr<nts::IComponent> in : this->getCircuit().getInputs()) {
        if (in->getName() == vect[0])
            return;
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
        if (buff.find('=') != buff.length())
            this->setInput(buff);
    }
}

nts::Circuit &nts::CLI::getCircuit()
{
    return this->_circuit;
}
