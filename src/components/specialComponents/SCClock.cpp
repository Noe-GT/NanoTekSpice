/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** SCClock
*/

#include "../../../include/SCClock.hpp"

nts::component::SCClock::SCClock(const std::string &name):
    nts::component::SpecialComponent(0, 1, name)
{
    this->_pins.push_back(nts::Pin(nts::PinType::OUTPUT, 1));
    this->_pins[0].setVal(nts::Tristate::False);
}

nts::component::SCClock::~SCClock()
{
}

nts::Tristate nts::component::SCClock::run()
{
    this->_pins[0].setVal(this->getValue());
    return this->_pins[0].getVal();
}

void nts::component::SCClock::simulate(size_t tick)
{
    if (tick == 0)
        return;
    if (this->getValue() == nts::Tristate::True)
        this->setValue(nts::Tristate::False);
    else if (this->getValue() == nts::Tristate::False)
        this->setValue(nts::Tristate::True);
}
