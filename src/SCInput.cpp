/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** SCInput
*/

#include "../include/SCInput.hpp"

component::SCInput::SCInput() : nts::AComponent(0, 1)
{
    nts::Pin p1(nts::PinType::OUTPUT, 1);

    p1.setVal(nts::Tristate::Undefined);
    this->_pins.push_back(p1);
}

component::SCInput::~SCInput()
{
}

void component::SCInput::setInput(nts::Tristate inputValue)
{
    this->_inputValue = inputValue;
}

void component::SCInput::simulate(std::size_t tick)
{
    if (tick <= 0)
        return;
    this->_pins[0].setVal(this->_inputValue);
    return;
}
