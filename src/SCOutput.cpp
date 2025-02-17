/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** SCOutput
*/

#include "../include/SCOutput.hpp"

nts::component::SCOutput::SCOutput(const std::string &name):
    nts::AComponent(1, 0, name)
{
    nts::Pin p1(nts::PinType::INPUT, 1);

    p1.setVal(nts::Tristate::Undefined);
    this->_pins.push_back(p1);
}

nts::component::SCOutput::~SCOutput()
{
}

void nts::component::SCOutput::simulate(std::size_t tick)
{
    if (tick <= 0)
        return;
    this->_outputValue = this->_pins[0].getVal();
    return;
}

nts::Tristate nts::component::SCOutput::getOutput() const
{
    return this->_outputValue;
}
