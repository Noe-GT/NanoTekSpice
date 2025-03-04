/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** SCClock
*/

#include "../../../include/components/specialComponents/SCClock.hpp"

nts::component::SCClock::SCClock(const std::string &name):
    nts::AComponent(name)
{
    this->_pins.emplace_back(new nts::Pin(nts::PinType::OUTPUT, 1));
    this->_pins[0]->setVal(TUNDEF);
    this->_innerValue = TUNDEF;
    this->_change = false;
}

nts::component::SCClock::~SCClock()
{
}

nts::Tristate nts::component::SCClock::run(size_t)
{
    return this->_pins[0]->getVal();
}

void nts::component::SCClock::simulate(size_t)
{
    if (this->_change == true) {
        this->_pins[0]->setVal(this->_innerValue);
        this->_change = false;
        return;
    }
    if (this->_innerValue == TTRUE)
        this->_innerValue = TFALSE;
    else if (this->_innerValue == TFALSE)
        this->_innerValue = TTRUE;
    this->_pins[0]->setVal(this->_innerValue);
}

bool nts::component::SCClock::setValue(std::string value)
{
    if (value == "U") {
        this->_innerValue = TUNDEF;
        this->_change = true;
        return true;
    }
    if (value == "0") {
        this->_innerValue = TFALSE;
        this->_change = true;
        return true;
    }
    if (value == "1") {
        this->_innerValue = TTRUE;
        this->_change = true;
        return true;
    }
    return false;
}
