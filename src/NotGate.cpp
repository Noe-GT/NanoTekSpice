/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** NotGate
*/

#include "../include/NotGate.hpp"

nts::component::NotGate::NotGate(const std::string &name):
    nts::AComponent(1, 1, name)
{
    nts::Pin p1(nts::PinType::INPUT, 1);
    nts::Pin p2(nts::PinType::OUTPUT, 2);

    this->_pins.push_back(p1);
    this->_pins.push_back(p2);
}

nts::component::NotGate::~NotGate()
{
}

void nts::component::NotGate::simulate(std::size_t tick)
{
    nts::Tristate in1;

    if (tick <= 0)
        return;
    in1 = this->_pins[0].getVal();
    if (in1 == nts::Tristate::True)
        this->_pins[1].setVal(nts::Tristate::False);
    else
        this->_pins[1].setVal(nts::Tristate::True);
}
