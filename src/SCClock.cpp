/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** SCClock
*/

#include "SCClock.hpp"

component::SCClock::SCClock() : nts::AComponent(0, 1)
{
    nts::Pin p1(nts::PinType::OUTPUT, 1);

    p1.setVal(nts::Tristate::False);
    this->_pins.push_back(p1);
}

component::SCClock::~SCClock()
{
}

void component::SCClock::setInput(nts::Tristate inputValue)
{
    this->_clockValue = inputValue;
}

void component::SCClock::simulate(std::size_t tick)
{
    if (tick <= 0)
        return;
    if (this->_clockValue == nts::Tristate::True)
        this->_clockValue =  nts::Tristate::False;
    else if (this->_clockValue == nts::Tristate::False)
        this->_clockValue =  nts::Tristate::True;
    this->_pins[0].setVal(this->_clockValue);
}
