/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** XorGate
*/

#include "../include/XorGate.hpp"

nts::component::XorGate::XorGate() : nts::AComponent(2, 1)
{
    nts::Pin p1(nts::PinType::INPUT, 1);
    nts::Pin p2(nts::PinType::INPUT, 2);
    nts::Pin p3(nts::PinType::OUTPUT, 3);

    this->_pins.push_back(p1);
    this->_pins.push_back(p2);
    this->_pins.push_back(p3);
}

nts::component::XorGate::~XorGate()
{
}

void nts::component::XorGate::simulate(std::size_t tick)
{
    nts::Tristate in1;
    nts::Tristate in2;

    if (tick <= 0)
        return;
    in1 = this->_pins[0].getVal();
    in2 = this->_pins[1].getVal();

    if ((in1 == nts::Tristate::True && in2 == nts::Tristate::False) ||
        (in1 == nts::Tristate::False && in2 == nts::Tristate::True))
        this->_pins[2].setVal(nts::Tristate::True);
    else
        this->_pins[2].setVal(nts::Tristate::False);
}
