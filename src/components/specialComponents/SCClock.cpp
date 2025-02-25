/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** SCClock
*/

#include "../../../include/components/specialComponents/SCClock.hpp"

nts::component::SCClock::SCClock(const std::string &name):
    nts::AComponent(0, 1, name)
{
    this->_innerValue = TUNDEF;
    this->_pins.push_back(nts::Pin(nts::PinType::OUTPUT, 1));
    this->_pins[0].setVal(TUNDEF);
}

nts::component::SCClock::~SCClock()
{
}

nts::Tristate nts::component::SCClock::run()
{
    return this->_pins[0].getVal();
}

void nts::component::SCClock::simulate(size_t tick)
{
    (void)tick;
    if (this->_innerValue != this->_pins[0].getVal()) {
        this->_pins[0].setVal(this->_innerValue);
        return;
    }
    if (this->_innerValue == TTRUE)
        this->_innerValue = TFALSE;
    else if (this->_innerValue == TFALSE)
        this->_innerValue = TTRUE;
    this->_pins[0].setVal(this->_innerValue);
}

bool nts::component::SCClock::setValue(std::string value)
{
    if (value == "U") {
        this->_innerValue = TUNDEF;
        return true;
    }
    if (value == "0") {
        this->_innerValue = TFALSE;
        return true;
    }
    if (value == "1") {
        this->_innerValue = TTRUE;
        return true;
    }
    return false;
}
