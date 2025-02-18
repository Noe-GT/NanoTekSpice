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
    this->_pins.emplace_back(new nts::Pin(nts::PinType::OUTPUT, 1));
    this->_pins[0]->setVal(nts::Tristate::False);
}

nts::component::SCClock::~SCClock()
{
}

void nts::component::SCClock::setInput(nts::Tristate inputValue)
{
    this->_clockValue = inputValue;
}

void nts::component::SCClock::run()
{
    if (this->_clockValue == nts::Tristate::True)
        this->_clockValue =  nts::Tristate::False;
    else if (this->_clockValue == nts::Tristate::False)
        this->_clockValue =  nts::Tristate::True;
    this->_pins[0]->setVal(this->_clockValue);
}
