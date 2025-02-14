/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** Pin
*/

#include "../include/Pin.hpp"

nts::Pin::Pin(std::size_t id, nts::IComponent &component): _id(id),
    _component(component), _val(Undefined)
{
}

nts::Pin::~Pin()
{
}

std::size_t nts::Pin::getId() const
{
    return this->_id;
}

nts::IComponent &nts::Pin::getComponent() const
{
    return this->_component;
}

std::map<nts::IComponent &, std::vector<size_t>> nts::Pin::getConnections()
    const
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
