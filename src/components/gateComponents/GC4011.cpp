/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** GC4011
*/

#include "../../../include/components/gateComponents/GC4011.hpp"
#include "../../../include/components/AndGate.hpp"
#include "../../../include/components/NotGate.hpp"

nts::component::GC4011::GC4011(const std::string &name):
    nts::AComponent(8, 4, 2, name)
{
    AndGate and1;
    NotGate not1;
    AndGate and2;
    NotGate not2;
    AndGate and3;
    NotGate not3;
    AndGate and4;
    NotGate not4;

    and1.setLink(3, not1, 1);
    and2.setLink(3, not2, 1);
    and3.setLink(3, not3, 1);
    and4.setLink(3, not4, 1);

    this->_pins.push_back(and1.getPin(1));
    this->_pins.push_back(and1.getPin(2));
    this->_pins.push_back(not1.getPin(2));
    this->_pins.push_back(not2.getPin(2));
    this->_pins.push_back(and2.getPin(1));
    this->_pins.push_back(and2.getPin(2));
    this->_pins.push_back(std::make_shared<nts::Pin>(nts::PinType::IGNORED, 7));
    this->_pins.push_back(and3.getPin(1));
    this->_pins.push_back(and3.getPin(2));
    this->_pins.push_back(not3.getPin(2));
    this->_pins.push_back(not4.getPin(2));
    this->_pins.push_back(and4.getPin(1));
    this->_pins.push_back(and4.getPin(2));
    this->_pins.push_back(std::make_shared<nts::Pin>(nts::PinType::IGNORED, 14));
}

nts::component::GC4011::~GC4011()
{
}

nts::Tristate nts::component::GC4011::run(size_t)
{
    return TUNDEF;
}
