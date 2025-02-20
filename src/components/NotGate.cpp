/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** NotGate
*/

#include "../../include/NotGate.hpp"

nts::component::NotGate::NotGate(const std::string &name):
    nts::AComponent(1, 1, name)
{
    this->_pins.push_back(nts::Pin(nts::PinType::INPUT, 1));
    this->_pins.push_back(nts::Pin(nts::PinType::OUTPUT, 2));
}

nts::component::NotGate::~NotGate()
{
}

nts::Tristate nts::component::NotGate::run()
{
    nts::Tristate in1;

    in1 = this->_pins[0].getVal();
    if (in1 == nts::Tristate::True)
        this->_pins[1].setVal(nts::Tristate::False);
    else
        this->_pins[1].setVal(nts::Tristate::True);
    return this->_pins[1].getVal();
}
