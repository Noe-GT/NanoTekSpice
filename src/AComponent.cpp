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

    while (!this->_inputs.empty()) {
        connection = this->_inputs.back();
        this->_inputs.pop_back();
        delete connection;
    }
    while (!this->_outputs.empty()) {
        connection = this->_outputs.back();
        this->_outputs.pop_back();
        delete connection;
    }
}

void nts::AComponent::simulate(std::size_t tick)
{
    (void)tick;
}

void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other,
    std::size_t otherPin)
{
    Connection *newConnection;
    Connection *tmp;

    if (pin <= 0 || pin > this->_nbInputs + this->_nbOutputs)
        throw Exception("Invalid pin number");
    for (size_t i = 0; i < this->_inputs.size(); i++) {
        tmp = this->_inputs.at(i);
        if (tmp->getPin() == pin)
            throw Exception("Pin already used");
    }
    if (this->isAlreadyConnected(pin, other, otherPin))
        return;
    newConnection = new Connection(pin, other, otherPin);
    if (pin <= this->_nbInputs)
        this->_inputs.push_back(newConnection);
    else
        this->_outputs.push_back(newConnection);
    other.setLink(otherPin, *this, pin);
}

bool nts::AComponent::isAlreadyConnected(std::size_t pin,
    nts::IComponent &other, std::size_t otherPin) const
{
    Connection *tmp;

    for (size_t i = 0; i < this->_inputs.size(); i++) {
        tmp = this->_inputs.at(i);
        if (tmp->getPin() == pin && &tmp->getComponent() == &other &&
        tmp->getOtherPin() == otherPin)
            return true;
    }
    for (size_t i = 0; i < this->_outputs.size(); i++) {
        tmp = this->_outputs.at(i);
        if (tmp->getPin() == pin && &tmp->getComponent() == &other &&
        tmp->getOtherPin() == otherPin)
            return true;
    }
    return false;
}

nts::Connection *nts::AComponent::getConnection(std::size_t pin) const
{
    std::vector<Connection *> list;
    Connection *ans = nullptr;

    if (pin <= 0 || pin > this->_nbInputs + this->_nbOutputs)
        throw Exception("Invalid pin number");
    if (pin <= this->_nbInputs)
        list = this->_inputs;
    else
        list = this->_outputs;
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

    if (pin <= 0 || pin > this->_nbInputs + this->_nbOutputs)
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
