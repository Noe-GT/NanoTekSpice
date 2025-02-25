/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** SCFalse
*/

#include "../../../include/components/specialComponents/SCFalse.hpp"

nts::component::SCFalse::SCFalse(const std::string &name):
    nts::AComponent(0, 1, name)
{
    this->_pins.push_back(nts::Pin(nts::PinType::OUTPUT, 1));
    this->_pins[0].setVal(nts::Tristate::False);
}

nts::component::SCFalse::~SCFalse()
{
}

nts::Tristate nts::component::SCFalse::run()
{
    return this->_pins[0].getVal();
}
