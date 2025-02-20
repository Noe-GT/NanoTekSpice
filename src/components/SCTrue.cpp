/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** SCTrue
*/

#include "../../include/SCTrue.hpp"

nts::component::SCTrue::SCTrue(const std::string &name):
    nts::AComponent(0, 1, name)
{
    this->_pins.push_back(nts::Pin(nts::PinType::OUTPUT, 1));
    this->_pins[0].setVal(nts::Tristate::True);
}

nts::component::SCTrue::~SCTrue()
{
}

nts::Tristate nts::component::SCTrue::run()
{
    return this->_pins[0].getVal();
}
