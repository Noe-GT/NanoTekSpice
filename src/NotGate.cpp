/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** NotGate
*/

#include "../include/NotGate.hpp"

nts::NotGate::NotGate() : _nbInputs(1), _nbOutputs(1)
{
}

nts::NotGate::~NotGate()
{
}

void nts::NotGate::simulate(std::size_t tick)
{
    nts::Tristate in1;
    nts::Tristate in2;

    if (tick <= 0)
        return;
    in1 = this->_connections[0]->getVal();
    if (in1 == nts::Tristate::True)
        this->_connections[1]->setVal(nts::Tristate::False);
    else
        this->_connections[1]->setVal(nts::Tristate::True);
}
