/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** AndGate
*/

#include "../../include/components/AndGate.hpp"

nts::component::AndGate::AndGate(const std::string &name):
    nts::AComponent(name)
{
    this->_pins.emplace_back(new nts::Pin(nts::PinType::INPUT, 1));
    this->_pins.emplace_back(new nts::Pin(nts::PinType::INPUT, 2));
    this->_pins.emplace_back(new nts::Pin(nts::PinType::OUTPUT, 3));
}

nts::component::AndGate::~AndGate()
{
}

nts::Tristate nts::component::AndGate::run(size_t)
{
    nts::Tristate in1 = this->getPin(1)->getVal();
    nts::Tristate in2 = this->getPin(2)->getVal();

    // this->switchRunState();
    if (in1 == in2)
        this->setPin(3, in1);
    else if (in1 == TFALSE || in2 == TFALSE)
        this->setPin(3, TFALSE);
    else
        this->setPin(3, TUNDEF);
    return this->getPin(3)->getVal();
}
