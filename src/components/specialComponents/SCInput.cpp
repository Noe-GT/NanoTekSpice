/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** SCInput
*/

#include "../../../include/SCInput.hpp"

nts::component::SCInput::SCInput(const std::string &name):
    nts::AComponent(0, 1, name)
{
    this->_innerValue = nts::Tristate::Undefined;
    this->_pins.push_back(nts::Pin(nts::PinType::OUTPUT, 1));
}

nts::component::SCInput::~SCInput()
{
}

nts::Tristate nts::component::SCInput::run()
{
    this->_pins[0].setVal(this->_innerValue);
    return this->_innerValue;
}

bool nts::component::SCInput::setValue(std::string value)
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