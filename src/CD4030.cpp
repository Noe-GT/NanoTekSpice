/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** CD4030
*/

#include "../include/CD4030.hpp"

nts::component::CD4030::CD4030(const std::string &name):
    nts::AComponent(8, 4, name), _xorGates()
{
    nts::component::XorGate g1;
    nts::component::XorGate g2;
    nts::component::XorGate g3;
    nts::component::XorGate g4;

    this->_xorGates.push_back(g1);
    this->_xorGates.push_back(g2);
    this->_xorGates.push_back(g3);
    this->_xorGates.push_back(g4);

    // ADD component linking
}

nts::component::CD4030::~CD4030()
{
}

void nts::component::CD4030::simulate(std::size_t tick)
{
    nts::Tristate in1;
    nts::Tristate in2;

    if (tick <= 0)
        return;
    // lauch simulate on all internal components connected to main component inputs
    return;
}
