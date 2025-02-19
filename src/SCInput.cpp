/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** SCInput
*/

#include "../include/SCInput.hpp"

nts::component::SCInput::SCInput(const std::string &name):
    nts::AComponent(0, 1, name)
{
    this->_inputValue = nts::Tristate::Undefined;
    this->_pins.push_back(nts::Pin(nts::PinType::OUTPUT, 1));
}

nts::component::SCInput::~SCInput()
{
}

void nts::component::SCInput::setInput(nts::Tristate inputValue)
{
    this->_inputValue = inputValue;
}

nts::Tristate nts::component::SCInput::run()
{
    this->_pins[0].setVal(this->_inputValue);
    return this->_pins[0].getVal();
}
