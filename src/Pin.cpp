/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** Pin
*/

#include "../include/Pin.hpp"

nts::Pin::Pin(PinType pinType, size_t id):
    _pinType(pinType), _id(id), _val(nts::Tristate::Undefined)
{
}

nts::Pin::~Pin()
{
}

nts::PinType nts::Pin::getPinType() const
{
    return this->_pinType;
}

size_t nts::Pin::getId() const
{
    return this->_id;
}

std::vector<nts::Connection> &nts::Pin::getConnections()
{
    return this->_connections;
}

nts::Tristate nts::Pin::getVal() const
{
    return this->_val;
}

void nts::Pin::setVal(nts::Tristate val)
{
    this->_val = val;
}
