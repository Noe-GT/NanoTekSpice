/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** SCClock
*/

#include "../include/SCClock.hpp"

nts::component::SCClock::SCClock(const std::string &name):
    nts::AComponent(0, 1, name)
{
    nts::Pin p1(nts::PinType::OUTPUT, 1);

    p1.setVal(nts::Tristate::False);
    this->_pins.push_back(p1);
}

nts::component::SCClock::~SCClock()
{
}

void nts::component::SCClock::setInput(nts::Tristate inputValue)
{
    this->_clockValue = inputValue;
}

void nts::component::SCClock::simulate(size_t tick)
{
    if (tick <= 0)
        return;
    if (this->_clockValue == nts::Tristate::True)
        this->_clockValue =  nts::Tristate::False;
    else if (this->_clockValue == nts::Tristate::False)
        this->_clockValue =  nts::Tristate::True;
    this->_pins[0].setVal(this->_clockValue);
}
