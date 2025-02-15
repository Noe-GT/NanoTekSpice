/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** NotGate
*/

#include "../include/NotGate.hpp"

component::NotGate::NotGate() : nts::AComponent(1, 1)
{
    size_t nbPins;

    nbPins = this->_nbInputs + this->_nbOutputs;
}

component::NotGate::~NotGate()
{
}

void component::NotGate::simulate(std::size_t tick)
{
    nts::Tristate in1;
    nts::Tristate in2;

    if (tick <= 0)
        return;
    in1 = this->_pins[0]->getVal();
    if (in1 == nts::Tristate::True)
        this->_pins[1]->setVal(nts::Tristate::False);
    else
        this->_pins[1]->setVal(nts::Tristate::True);
}
