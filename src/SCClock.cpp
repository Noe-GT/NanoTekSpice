/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** SCClock
*/

#include "SCClock.hpp"

component::SCClock::SCClock()
{
    size_t nbPins;

    nbPins = this->_nbInputs + this->_nbOutputs;
    this->_pins.resize(nbPins);
    this->_pins[0]->setValue(nts::Tristate::False);
}

component::SCClock::~SCClock()
{
}

void component::SCClock::setInput(nts::Tristate inputValue)
{
    this->_inputValue = inputValue;
}

void component::SCClock::simulate(std::size_t tick)
{
    if (tick <= 0)
        return;
    if (this->_clockValue == nts::Tristate::True)
        this->_clokValue =  nts::Tristate::False;
    else if (this->_clockValue == nts::Tristate::False)
        this->_clokValue =  nts::Tristate::True;
    this->_pins[0].setValue(this->_clockValue);
}
