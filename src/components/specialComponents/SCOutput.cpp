/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** SCOutput
*/

#include "../../../include/components/specialComponents/SCOutput.hpp"

nts::component::SCOutput::SCOutput(const std::string &name):
    nts::AComponent(name)
{
    this->_innerValue = nts::Tristate::Undefined;
    this->_pins.emplace_back(new nts::Pin(nts::PinType::INPUT, 1));
}

nts::component::SCOutput::~SCOutput()
{
}

nts::Tristate nts::component::SCOutput::run(size_t)
{
    this->_innerValue = this->_pins[0]->getVal();
    return this->_innerValue;
}
