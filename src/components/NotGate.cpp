/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** NotGate
*/

#include "../../include/components/NotGate.hpp"

nts::component::NotGate::NotGate(const std::string &name):
    nts::AComponent(1, 1, 0, name)
{
    this->_pins.emplace_back(new nts::Pin(nts::PinType::INPUT, 1));
    this->_pins.emplace_back(new nts::Pin(nts::PinType::OUTPUT, 2));
}

nts::component::NotGate::~NotGate()
{
}

nts::Tristate nts::component::NotGate::run(size_t)
{
    nts::Tristate in1 = this->getPin(1)->getVal();

    if (in1 == TTRUE)
        this->setPin(2, TFALSE);
    else if (in1 == TFALSE)
        this->setPin(2, TTRUE);
    else
        this->setPin(2, TUNDEF);
    return this->getPin(2)->getVal();
}
