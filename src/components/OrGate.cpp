/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** OrGate
*/

#include "../../include/components/OrGate.hpp"

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
    nts::Tristate in1 = this->getPin(1).getVal();
    nts::Tristate in2 = this->getPin(2).getVal();

    if (in1 == TTRUE || in2 == TTRUE)
        this->setPin(3, TTRUE);
    else if (in1 == TUNDEF || in2 == TUNDEF)
        this->setPin(3, TUNDEF);
    else
        this->setPin(3, TFALSE);
    return this->getPin(3).getVal();
}
