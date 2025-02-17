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
    this->_pins.emplace_back(new nts::Pin(nts::PinType::OUTPUT, 1));
    this->_pins[0]->setVal(nts::Tristate::True);
}

nts::component::SCTrue::~SCTrue()
{
}

void nts::component::SCTrue::simulate(std::size_t tick)
{
    if (tick <= 0)
        return;
}
