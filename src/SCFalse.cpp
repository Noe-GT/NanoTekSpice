/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** SCFalse
*/

#include "../include/SCFalse.hpp"

nts::component::SCFalse::SCFalse(const std::string &name):
    nts::AComponent(0, 1, name)
{
    nts::Pin p1(nts::PinType::OUTPUT, 1);

    p1.setVal(nts::Tristate::False);
    this->_pins.push_back(p1);
}

nts::component::SCFalse::~SCFalse()
{
}

void nts::component::SCFalse::simulate(size_t tick)
{
    if (tick <= 0)
        return;
}
