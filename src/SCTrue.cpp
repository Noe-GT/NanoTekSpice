/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** SCTrue
*/

#include "../include/SCTrue.hpp"

component::SCTrue::SCTrue() : nts::AComponent(0, 1)
{
    size_t nbPins;

    nbPins = this->_nbInputs + this->_nbOutputs;
    this->_pins.resize(nbPins);
    this->_pins[0]->setValue(nts::Tristate::True);
}

component::SCTrue::~SCTrue()
{
}

void component::SCTrue::simulate(std::size_t tick)
{
}
