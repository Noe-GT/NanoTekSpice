/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** AndGate
*/

#include "../include/AndGate.hpp"

nts::component::AndGate::AndGate(const std::string &name):
    nts::AComponent(2, 1, name)
{
    this->_pins.push_back(nts::Pin(nts::PinType::INPUT, 1));
    this->_pins.push_back(nts::Pin(nts::PinType::INPUT, 2));
    this->_pins.push_back(nts::Pin(nts::PinType::OUTPUT, 3));
}

nts::component::AndGate::~AndGate()
{
}

void nts::component::AndGate::run()
{
    nts::Tristate in1;
    nts::Tristate in2;

    // size_t pinn1 = this->_pins[0]->getConnections()[0].getPins()[0];
    // size_t pinn2 = this->_pins[1]->getConnections()[0].getPins()[0];
    // this->_pins[0]->setVal(this->_pins[0]->getConnections()[0].getLink().compute(pinn1));
    // this->_pins[1]->setVal(this->_pins[1]->getConnections()[0].getLink().compute(pinn2));

    in1 = this->_pins[0].getVal();
    in2 = this->_pins[1].getVal();

    if (in1 == nts::Tristate::True && in2 == nts::Tristate::True)
        this->_pins[2].setVal(nts::Tristate::True);
    else
        this->_pins[2].setVal(nts::Tristate::False);
}
