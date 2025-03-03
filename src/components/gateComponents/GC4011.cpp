/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** GC4011
*/

#include "../../../include/components/gateComponents/GC4011.hpp"

nts::component::GC4011::GC4011(const std::string &name):
    nts::AComponent(8, 4, name)
{
    this->_pins.emplace_back(new nts::Pin(nts::PinType::INPUT, 1));
    this->_pins.emplace_back(new nts::Pin(nts::PinType::INPUT, 2));
    this->_pins.emplace_back(new nts::Pin(nts::PinType::OUTPUT, 3));
    this->_pins.emplace_back(new nts::Pin(nts::PinType::OUTPUT, 4));
    this->_pins.emplace_back(new nts::Pin(nts::PinType::INPUT, 5));
    this->_pins.emplace_back(new nts::Pin(nts::PinType::INPUT, 6));
    this->_pins.emplace_back(new nts::Pin(nts::PinType::IGNORED, 7));
    this->_pins.emplace_back(new nts::Pin(nts::PinType::INPUT, 8));
    this->_pins.emplace_back(new nts::Pin(nts::PinType::INPUT, 9));
    this->_pins.emplace_back(new nts::Pin(nts::PinType::OUTPUT, 10));
    this->_pins.emplace_back(new nts::Pin(nts::PinType::OUTPUT, 11));
    this->_pins.emplace_back(new nts::Pin(nts::PinType::INPUT, 12));
    this->_pins.emplace_back(new nts::Pin(nts::PinType::INPUT, 13));
    this->_pins.emplace_back(new nts::Pin(nts::PinType::IGNORED, 14));
}

nts::component::GC4011::~GC4011()
{
}

nts::Tristate nts::component::GC4011::run(size_t)
{
    nts::Tristate in1 = this->getPin(1)->getVal();
    nts::Tristate in2 = this->getPin(2)->getVal();

    if (in1 == in2)
        this->setPin(3, in1);
    else if (in1 == TFALSE || in2 == TFALSE)
        this->setPin(3, TFALSE);
    else
        this->setPin(3, TUNDEF);
    return this->getPin(3)->getVal();
}
