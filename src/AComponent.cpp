/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** AComponent
*/

#include "../include/AComponent.hpp"

nts::AComponent::AComponent(size_t nbInputs, size_t nbOutputs,
    const std::string &name):
    _pins(),
    _name(name),
    _nbInputs(nbInputs),
    _nbOutputs(nbOutputs)
{
    // this->_pins.resize(nbInputs + nbOutputs);
}

nts::AComponent::~AComponent()
{
}

std::string nts::AComponent::getName() const
{
    return this->_name;
}

void nts::AComponent::simulate(size_t tick)
{
    (void)tick;
}

bool nts::AComponent::isPinInRange(size_t pin) const
{
    return pin > 0 && pin <= this->_nbInputs + this->_nbOutputs;
}

bool nts::AComponent::isInputPin(size_t pin) const
{
    if (!this->isPinInRange(pin))
        throw Exception("Incalid pin number");
    return this->_pins[pin - 1].getPinType() == INPUT;
}

bool nts::AComponent::isOutputPin(size_t pin) const
{
    if (!this->isPinInRange(pin))
        throw Exception("Incalid pin number");
    return this->_pins[pin - 1].getPinType() == OUTPUT;
}

void nts::AComponent::setLink(size_t pin, nts::IComponent &other,
    size_t otherPin)
{
    std::vector<Connection> connectionsList;

    if (this == &other)
        throw Exception("Can't link a component to itself");
    if (!this->isPinInRange(pin))
        throw Exception("Invalid pin number");
    if (this->isInputPin(pin) && this->isConnected(pin))
        throw Exception("Pin already used");
    if (this->_pins[pin - 1].getPinType() == other.getPin(pin).getPinType())
        throw Exception("Can't link 2 pins with the same type");
    if (this->isConnected(pin, other, otherPin))
        return;
    connectionsList = this->_pins[pin - 1].getConnections();
    for (size_t i = 0; i < connectionsList.size(); i++) {
        if (&connectionsList[i].getLink() == &other) {
            connectionsList[i].getPins().push_back(otherPin);
            return other.setLink(otherPin, *this, pin);
        }
    }
    connectionsList.push_back(Connection(other, otherPin));
    other.setLink(otherPin, *this, pin);
}

bool nts::AComponent::isConnected(size_t pin,
    nts::IComponent &other, size_t otherPin) const
{
    std::vector<Connection> connectionsList;
    Connection tmp(other, otherPin);

    if (!this->isPinInRange(pin))
        throw Exception("Invalid pin number");
    connectionsList = this->_pins[pin - 1].getConnections();
    for (size_t i = 0; i < connectionsList.size(); i++)
        if (&connectionsList[i].getLink() == &other &&
        connectionsList[i].find(otherPin))
            return true;
    return false;
}

bool nts::AComponent::isConnected(size_t pin) const
{
    if (!this->isPinInRange(pin))
        throw Exception("Invalid pin number");
    return !this->_pins[pin - 1].getConnections().empty();
}

nts::Tristate nts::AComponent::getLink(size_t pin) const
{
    // appelle compute sur les composants liés aux pins d'input
    (void)pin;
    return Undefined;
}

nts::Tristate nts::AComponent::compute(size_t pin)
{
    if (this->_pins.size() > pin || pin == 0)
        return nts::Tristate::Undefined;
    return this->_pins[pin - 1].getVal();
}

size_t nts::AComponent::getNbInputs() const
{
    return this->_nbInputs;
}

size_t nts::AComponent::getNbOutputs() const
{
    return this->_nbOutputs;
}

void nts::AComponent::setPin(size_t pin, nts::Tristate value)
{
    if (pin <= (this->_nbInputs + this->_nbOutputs) && pin > 0)
        this->_pins[pin - 1].setVal(value);
}

nts::Pin &nts::AComponent::getPin(size_t pin)
{
    if (!this->isPinInRange(pin))
        throw Exception("Invalid pin number");
    return this->_pins[pin - 1];
}