/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** SCInput
*/

#include "../../../include/components/specialComponents/SCInput.hpp"

nts::component::SCInput::SCInput(const std::string &name):
    nts::AComponent(name)
{
    this->_innerValue = nts::Tristate::Undefined;
    this->_pins.emplace_back(new nts::Pin(nts::PinType::OUTPUT, 1));
}

nts::component::SCInput::~SCInput()
{
}

nts::Tristate nts::component::SCInput::run(size_t)
{
    return this->_pins[0]->getVal();
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

void nts::component::SCInput::simulate(size_t)
{
    this->_pins[0]->setVal(this->_innerValue);
}
