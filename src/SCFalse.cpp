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
    this->_pins.emplace_back(new nts::Pin(nts::PinType::OUTPUT, 1));
    this->_pins[0]->setVal(nts::Tristate::False);
}

nts::component::SCFalse::~SCFalse()
{
}

void nts::component::SCFalse::simulate(std::size_t tick)
{
    if (tick <= 0)
        return;
}
