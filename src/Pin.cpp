/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** Pin
*/

#include "../include/Pin.hpp"

nts::Pin::Pin(PinType pinType, std::size_t id):
    _pinType(pinType), _id(id), _val(Undefined)
{
}

nts::Pin::~Pin()
{
}

nts::PinType nts::Pin::getPinType() const
{
    return this->_pinType;
}

std::size_t nts::Pin::getId() const
{
    return this->_id;
}

// nts::IComponent &nts::Pin::getComponent() const
// {
//     return this->_component;
// }

std::vector<nts::Connection> nts::Pin::getConnections() const
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
