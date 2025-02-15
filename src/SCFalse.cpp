/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** SCFalse
*/

#include "../include/SCFalse.hpp"

component::SCFalse::SCFalse() : nts::AComponent(0, 1)
{
    size_t nbPins;

    nbPins = this->_nbInputs + this->_nbOutputs;
    this->_pins.resize(nbPins);
    this->_pins[0]->setValue(nts::Tristate::False);
}

component::SCFalse::~SCFalse()
{
}

void component::SCFalse::simulate(std::size_t tick)
{
}
