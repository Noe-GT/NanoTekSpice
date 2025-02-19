/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** OrGate
*/

#include "../include/OrGate.hpp"

nts::component::OrGate::OrGate(const std::string &name):
    nts::AComponent(2, 1, name)
{
    this->_pins.push_back(nts::Pin(nts::PinType::INPUT, 1));
    this->_pins.push_back(nts::Pin(nts::PinType::INPUT, 2));
    this->_pins.push_back(nts::Pin(nts::PinType::OUTPUT, 3));
}

nts::component::OrGate::~OrGate()
{
}

nts::Tristate nts::component::OrGate::run()
{
    nts::Tristate in1;
    nts::Tristate in2;

    in1 = this->_pins[0].getVal();
    in2 = this->_pins[1].getVal();

    if (in1 == nts::Tristate::True || in2 == nts::Tristate::True)
        this->_pins[2].setVal(nts::Tristate::True);
    else
        this->_pins[2].setVal(nts::Tristate::False);
    return this->_pins[2].getVal();
}
