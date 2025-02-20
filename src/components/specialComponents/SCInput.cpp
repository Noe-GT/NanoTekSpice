/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** SCInput
*/

#include "../../../include/SCInput.hpp"

nts::component::SCInput::SCInput(const std::string &name):
    nts::component::SpecialComponent(0, 1, name)
{
    this->_pins.push_back(nts::Pin(nts::PinType::OUTPUT, 1));
}

nts::component::SCInput::~SCInput()
{
}

nts::Tristate nts::component::SCInput::run()
{
    this->_pins[0].setVal(this->getValue());
    return this->_pins[0].getVal();
}
