/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** SCOutput
*/

#include "../../../include/SCOutput.hpp"

nts::component::SCOutput::SCOutput(const std::string &name):
    nts::AComponent(0, 1, name)
{
    this->_innerValue = nts::Tristate::Undefined;
    this->_pins.push_back(nts::Pin(nts::PinType::INPUT, 1));
}

nts::component::SCOutput::~SCOutput()
{
}

nts::Tristate nts::component::SCOutput::run()
{
    this->_innerValue = this->_pins[0].getVal();
    return this->_innerValue;
}
