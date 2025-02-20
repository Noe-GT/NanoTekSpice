/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** SCClock
*/

#include "../../../include/SCClock.hpp"

nts::component::SCClock::SCClock(const std::string &name):
    nts::AComponent(0, 1, name)
{
    this->_innerValue = nts::Tristate::Undefined;
    this->_pins.push_back(nts::Pin(nts::PinType::OUTPUT, 1));
    this->_pins[0].setVal(nts::Tristate::False);
}

nts::component::SCClock::~SCClock()
{
}

nts::Tristate nts::component::SCClock::run()
{
    this->_pins[0].setVal(this->_innerValue);
    return this->_pins[0].getVal();
}

void nts::component::SCClock::simulate(size_t tick)
{
    if (tick == 0)
        return;
    if (this->_innerValue == nts::Tristate::True)
        this->_innerValue = nts::Tristate::False;
    else if (this->_innerValue == nts::Tristate::False)
        this->_innerValue = nts::Tristate::True;
}

bool nts::component::SCClock::setValue(std::string value)
{
    if (value == "U") {
        this->_innerValue = nts::Tristate::Undefined;
        return true;
    }
    if (value == "0") {
        this->_innerValue = nts::Tristate::False;
        return true;
    }
    if (value == "1") {
        this->_innerValue = nts::Tristate::True;
        return true;
    }
    return false;

}
