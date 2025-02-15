/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** Connection
*/

#include "../include/Connection.hpp"

nts::Connection::Connection(IComponent &link, size_t pin): _link(link)
{
    this->_pins.push_back(pin);
}

nts::Connection::~Connection()
{
}

nts::IComponent &nts::Connection::getLink() const
{
    return this->_link;
}

std::vector<size_t> nts::Connection::getPins() const
{
    return this->_pins;
}

bool nts::Connection::find(size_t pinId) const
{
    for (size_t i = 0; i < this->_pins.size(); i++)
        if (this->_pins[i] == pinId)
            return true;
    return false;
}
