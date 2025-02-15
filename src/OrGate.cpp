/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** OrGate
*/

#include "../include/OrGate.hpp"

component::OrGate::OrGate() : nts::AComponent(2, 1)
{
    size_t nbPins;

    nbPins = this->_nbInputs + this->_nbOutputs;
}

component::OrGate::~OrGate()
{
}

void component::OrGate::simulate(std::size_t tick)
{
    nts::Tristate in1;
    nts::Tristate in2;

    if (tick <= 0)
        return;
    in1 = this->_pins[0]->getVal();
    in2 = this->_pins[1]->getVal();

    if (in1 == nts::Tristate::True || in2 == nts::Tristate::True)
        this->_pins[2]->setVal(nts::Tristate::True);
    else
        this->_pins[2]->setVal(nts::Tristate::False);
}
