/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** SCOutput
*/

#include "../include/SCOutput.hpp"

nts::component::SCOutput::SCOutput(const std::string &name):
    nts::AComponent(0, 1, name)
{
    this->_outputValue = nts::Tristate::Undefined;
    this->_pins.emplace_back(new nts::Pin(nts::PinType::INPUT, 1));
}

nts::component::SCOutput::~SCOutput()
{
}

nts::Tristate nts::component::SCOutput::run()
{
    this->_outputValue = this->_pins[0]->getVal();
    return this->_pins[0]->getVal();
}

nts::Tristate nts::component::SCOutput::getOutput() const
{
    return this->_outputValue;
}
