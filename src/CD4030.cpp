/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** CD4030
*/

#include "../include/CD4030.hpp"

component::CD4030::CD4030() : _xorGates()
{
    component::XorGate g1;
    component::XorGate g2;
    component::XorGate g3;
    component::XorGate g4;

    this->_xorGates.push_back(g1);
    this->_xorGates.push_back(g2);
    this->_xorGates.push_back(g3);
    this->_xorGates.push_back(g4);

    // ADD component linking

    this->_nbInputs = 8;
    this->_nbOutputs = 4;
}

component::CD4030::~CD4030()
{
}

void component::CD4030::simulate(std::size_t tick)
{
    nts::Tristate in1;
    nts::Tristate in2;

    if (tick <= 0)
        return;
    // lauch simulate on all internal components connected to main component inputs
    return;
}
