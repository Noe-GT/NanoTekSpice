/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** AComponent
*/

#include "../include/AComponent.hpp"

nts::Connection::Connection(std::size_t pin, nts::IComponent &other,
    std::size_t otherPin, nts::Tristate val): _pin(pin), _other(other),
    _otherPin(otherPin), _val(val)
{
}

nts::Connection::~Connection()
{
}

nts::AComponent::AComponent(): _nbInputs(0), _nbOutputs(0)
{
}

nts::AComponent::~AComponent()
{
    nts::Connection *connection;

    while (!this->_connections.empty()) {
        connection = this->_connections.back();
        this->_connections.pop_back();
        delete connection;
    }
}

void nts::AComponent::simulate(std::size_t tick)
{
    (void)tick;
}

bool nts::AComponent::isPinUsed(std::size_t pin) const
{
    Connection *connection;

    for (std::size_t i = 0; i < this->_connections.size(); i++) {
        connection = this->_connections.at(i);
        if (connection->getPin() == pin)
            return true;
    }
    return false;
}

bool nts::AComponent::isPinInRange(std::size_t pin) const
{
    return pin > 0 && pin <= this->_nbInputs + this->_nbOutputs;
}

bool nts::AComponent::isInputPin(std::size_t pin) const
{
    if (!this->isPinInRange(pin))
        throw Exception("Incalid pin number");
    return pin <= this->_nbInputs;
}

bool nts::AComponent::isOutputPin(std::size_t pin) const
{
    if (!this->isPinInRange(pin))
        throw Exception("Incalid pin number");
    return pin > this->_nbInputs;
}

void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other,
    std::size_t otherPin)
{
    Connection *newConnection;

    if (!this->isPinInRange(pin))
        throw Exception("Invalid pin number");
    if (this->isInputPin(pin) && this->isConnected(pin))
        throw Exception("Pin already used");
    if (this->isConnected(pin, other, otherPin))
        return;
    newConnection = new Connection(pin, other, otherPin);
    this->_connections.push_back(newConnection);
    other.setLink(otherPin, *this, pin);
}

bool nts::AComponent::isConnected(std::size_t pin,
    nts::IComponent &other, std::size_t otherPin) const
{
    Connection *tmp;

    if (!this->isPinInRange(pin))
        throw Exception("Invalid pin number");
    for (size_t i = 0; i < this->_connections.size(); i++) {
        tmp = this->_connections.at(i);
        if (tmp->getPin() == pin && &tmp->getComponent() == &other &&
        tmp->getOtherPin() == otherPin)
            return true;
    }
    return false;
}

bool nts::AComponent::isConnected(std::size_t pin) const
{
    Connection *tmp;

    if (!this->isPinInRange(pin))
        throw Exception("Invalid pin number");
    for (std::size_t i = 0; i < this->_connections.size(); i++) {
        tmp = this->_connections.at(i);
        if (tmp->getPin() == pin)
            return true;
    }
    return false;
}

nts::Connection *nts::AComponent::getConnection(std::size_t pin) const
{
    std::vector<Connection *> list;
    Connection *ans;

    if (!this->isPinInRange(pin))
        throw Exception("Invalid pin number");
    for (size_t i = 0; i < list.size(); i++) {
        ans = list.at(i);
        if (ans->getPin() == pin)
            return ans;
    }
    return nullptr;
}

nts::Tristate nts::AComponent::getLink(std::size_t pin) const
{
    Connection *connection;

    if (!this->isPinInRange(pin))
        throw Exception("Invalid pin number");
    connection = this->getConnection(pin);
    if (!connection)
        throw Exception("Connection does not exist");
    return connection->getComponent().compute(connection->getOtherPin());
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
