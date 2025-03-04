/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** XorGate
*/

#include "../../include/components/XorGate.hpp"

nts::component::XorGate::XorGate(const std::string &name):
    nts::AComponent(name)
{
    this->_pins.emplace_back(new nts::Pin(nts::PinType::INPUT, 1));
    this->_pins.emplace_back(new nts::Pin(nts::PinType::INPUT, 2));
    this->_pins.emplace_back(new nts::Pin(nts::PinType::OUTPUT, 3));
}

nts::component::XorGate::~XorGate()
{
}

nts::Tristate nts::component::XorGate::run(size_t)
{
    nts::Tristate in1 = this->getPin(1)->getVal();
    nts::Tristate in2 = this->getPin(2)->getVal();

    if (in1 == TUNDEF || in2 == TUNDEF)
        this->setPin(3, TUNDEF);
    else if (in1 == in2)
        this->setPin(3, TFALSE);
    else
        this->setPin(3, TTRUE);
    return this->getPin(3)->getVal();
}
