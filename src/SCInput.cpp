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
    nts::Pin p1(nts::PinType::OUTPUT, 1);

    p1.setVal(nts::Tristate::Undefined);
    this->_pins.push_back(p1);
}

nts::component::SCInput::~SCInput()
{
}

void nts::component::SCInput::setInput(nts::Tristate inputValue)
{
    this->_inputValue = inputValue;
}

void nts::component::SCInput::simulate(std::size_t tick)
{
    if (tick <= 0)
        return;
    this->_pins[0].setVal(this->_inputValue);
    return;
}
