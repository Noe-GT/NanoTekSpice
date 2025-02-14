/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** Circuit
*/

#include "Circuit.hpp"

nts::Circuit::Circuit()
{
}

nts::Circuit::~Circuit()
{
}

void nts::Circuit::addComponent(IComponent &component)
{
    this->_allComponents.push_back(component);
}

// void nts::Circuit::simulate(std::size_t tick)
// {
// }

// void nts::Circuit::display() const
// {
// }
