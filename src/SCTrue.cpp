/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** SCTrue
*/

#include "../include/SCTrue.hpp"

component::SCTrue::SCTrue() : nts::AComponent(0, 1)
{
    nts::Pin p1(nts::PinType::OUTPUT, 1);

    p1.setVal(nts::Tristate::True);
    this->_pins.push_back(p1);
}

component::SCTrue::~SCTrue()
{
}

void component::SCTrue::simulate(std::size_t tick)
{
}
