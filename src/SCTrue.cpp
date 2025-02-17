/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** SCTrue
*/

#include "../include/SCTrue.hpp"

nts::component::SCTrue::SCTrue(const std::string &name):
    nts::AComponent(0, 1, name)
{
    nts::Pin p1(nts::PinType::OUTPUT, 1);

    p1.setVal(nts::Tristate::True);
    this->_pins.push_back(p1);
}

nts::component::SCTrue::~SCTrue()
{
}

void nts::component::SCTrue::simulate(std::size_t tick)
{
    if (tick <= 0)
        return;
}
