/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** NandGate
*/

#include "../../../include/components/extraComponents/NandGate.hpp"

nts::component::NandGate::NandGate(const std::string &name):
    nts::AComponent(name),
    _and(),
    _not()
{
    this->_pins.push_back(this->_and.getPin(1));
    this->_pins.push_back(this->_and.getPin(2));
    this->_pins.push_back(this->_not.getPin(2));

    this->_and.setLink(3, this->_not, 1);
}

nts::component::NandGate::~NandGate()
{
}

nts::Tristate nts::component::NandGate::run(size_t)
{
    return this->_not.compute(2);
}
