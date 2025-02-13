/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** Connection
*/

#include "../include/Connection.hpp"

nts::Connection::Connection(std::size_t pin, nts::IComponent &other,
    std::size_t otherPin, nts::Tristate val): _pin(pin), _other(other),
    _otherPin(otherPin), _val(val)
{
}

nts::Connection::~Connection()
{
}

std::size_t nts::Connection::getPin() const
{
    return this->_pin;
}

nts::IComponent &nts::Connection::getComponent() const
{
    return this->_other;
}

std::size_t nts::Connection::getOtherPin() const
{
    return this->_otherPin;
}

nts::Tristate nts::Connection::getVal() const
{
    return this->_val;
}

void nts::Connection::setVal(nts::Tristate val)
{
    this->_val = val;
}
