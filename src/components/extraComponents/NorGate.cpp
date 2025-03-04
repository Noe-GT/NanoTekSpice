/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** NorGate
*/

#include "../../../include/components/extraComponents/NorGate.hpp"

nts::component::NorGate::NorGate(const std::string &name):
    nts::AComponent(name),
    _or(),
    _not()
{
    this->_pins.push_back(this->_or.getPin(1));
    this->_pins.push_back(this->_or.getPin(2));
    this->_pins.push_back(this->_not.getPin(2));

    this->_or.setLink(3, this->_not, 1);
}

nts::component::NorGate::~NorGate()
{
}

nts::Tristate nts::component::NorGate::run(size_t)
{
    return this->_not.compute(2);
}
