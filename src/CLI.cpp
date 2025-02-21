/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** CLI
*/

#include "../include/CLI.hpp"

bool nts::CLI::_loop = true;

nts::CLI::CLI()
{
    this->_tick = 0;
    this->_stopCLI = false;
}

nts::CLI::CLI(nts::Circuit &circuit): _circuit(circuit)
{
    this->_tick = 0;
    this->_stopCLI = false;
}

nts::CLI::~CLI()
{
}

nts::Circuit &nts::CLI::getCircuit()
{
    return this->_circuit;
}

void nts::CLI::setCircuit(nts::Circuit &circuit)
{
    this->_circuit = circuit;
}

void nts::CLI::exit()
{
    this->_stopCLI = true;
}

static bool comp(std::shared_ptr<nts::IComponent> a, std::shared_ptr<nts::IComponent> b) {
    return a->getName() < b->getName();
}

void nts::CLI::sortInOut()
{
    std::vector<std::shared_ptr<nts::IComponent>> &inputs = this->getCircuit().getInputs();
    std::vector<std::shared_ptr<nts::IComponent>> &outputs = this->getCircuit().getOutputs();

    std::sort(inputs.begin(), inputs.end(), comp);
    std::sort(outputs.begin(), outputs.end(), comp);
}

void nts::CLI::displayInOut(std::vector<std::shared_ptr<nts::IComponent>> &comps) const
{
    nts::Tristate val;

    for (std::shared_ptr<nts::IComponent> comp : comps) {
        val = comp->compute(1);
        std::cout << "  " << comp->getName() << ": ";
        if (val == nts::Tristate::Undefined)
            std::cout << "U" << std::endl;
        else
            std::cout << val << std::endl;
    }
}

void nts::CLI::display()
{
    std::cout << "tick: " << this->_tick << std::endl;
    std::cout << "input(s):" << std::endl;
    this->displayInOut(this->getCircuit().getInputs());
    std::cout << "outputs(s):" << std::endl;
    this->displayInOut(this->getCircuit().getOutputs());
}

void nts::CLI::simulate()
{
    for (std::shared_ptr<nts::IComponent> out : this->getCircuit().getOutputs())
        out->simulate(1);
    this->_tick++;
}

void nts::CLI::ctrlCHandler(int signum)
{
    (void)signum;
    nts::CLI::_loop = false;
}

void nts::CLI::loop()
{
    std::signal(SIGINT, ctrlCHandler);

    while (nts::CLI::_loop) {
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
        (vect[1] != "U" && vect[1] != "0" && vect[1] != "1")) {
        std::cout << "Value assignation not valid (must be 'name=U/0/1')" << std::endl;
        return;
    }
    for (std::shared_ptr<nts::IComponent> in : this->getCircuit().getInputs()) {
        if (in->getName() == vect[0]) {
            in->setValue(vect[1]);
            return;
        }
    }
}

void nts::CLI::run()
{
    std::string buff;

    this->sortInOut();
    while (!this->_stopCLI) {
        std::cout << "> ";
        if (!std::getline(std::cin, buff))
            return this->exit();
        if (buff == "display")
            this->display();
        else if (buff == "exit")
            this->exit();
        else if (buff == "loop")
            this->loop();
        else if (buff == "simulate")
            this->simulate();
        else if (buff.find('=') != buff.npos)
            this->setInput(buff);
    }
}
