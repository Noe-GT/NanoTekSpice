/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** SCInput
*/

#include "../include/SCInput.hpp"

component::SCInput::SCInput() : nts::AComponent(1, 1)
{
    size_t nbPins;

    nbPins = this->_nbInputs + this->_nbOutputs;
    this->_pins.resize(nbPins);
    this->_inputValue = nts::Tristate::Undefined;
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
    this->_pins[0]->setVal(this->_inputValue);
    return;
}
