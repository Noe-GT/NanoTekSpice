/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** AndGate
*/

#include "../include/AndGate.hpp"

nts::AndGate::AndGate() : _nbInputs(2), _nbOutputs(1)
{
}

nts::AndGate::~AndGate()
{
}

void nts::AndGate::simulate(std::size_t tick)
{
    nts::Tristate in1;
    nts::Tristate in2;

    if (tick <= 0)
        return;
    in1 = this->_connections[0]->getVal();
    in2 = this->_connections[1]->getVal();

    if (in1 == nts::Tristate::True && in2 == nts::Tristate::True)
        this->_connections[2]->setVal(nts::Tristate::True);
    else
        this->_connections[2]->setVal(nts::Tristate::False);
}
