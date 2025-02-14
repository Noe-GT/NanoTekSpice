/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** AComponent
*/

#include "../include/AComponent.hpp"

nts::AComponent::AComponent(size_t nbInputs, size_t nbOutputs): _name("None"),
    _nbInputs(nbInputs), _nbOutputs(nbOutputs)
{
}

nts::AComponent::~AComponent()
{
}

void nts::AComponent::simulate(std::size_t tick)
{
    (void)tick;
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
    std::vector<size_t> otherConnections;

    if (!this->isPinInRange(pin))
        throw Exception("Invalid pin number");
    if (this->isInputPin(pin) && this->isConnected(pin))
        throw Exception("Pin already used");
    if (this->isConnected(pin, other, otherPin))
        return;
    otherConnections.push_back(otherPin);
    this->_pins[pin - 1].getConnections()[other] = otherConnections;
    other.setLink(otherPin, *this, pin);
}

bool nts::AComponent::isConnected(std::size_t pin,
    nts::IComponent &other, std::size_t otherPin) const
{
    std::vector<size_t> connectionsList;
    std::map<nts::IComponent &, std::vector<size_t>>::iterator iterator;

    if (!this->isPinInRange(pin))
        throw Exception("Invalid pin number");
    iterator = this->_pins[pin - 1].getConnections().find(other);
    if (iterator == this->_pins[pin - 1].getConnections().end())
        return false;
    connectionsList = this->_pins[pin - 1].getConnections()[other];
    for (size_t i = 0; i < connectionsList.size(); i++)
        if (connectionsList[i] == otherPin)
            return true;
    return false;
}

bool nts::AComponent::isConnected(std::size_t pin) const
{
    if (!this->isPinInRange(pin))
        throw Exception("Invalid pin number");
    return this->_pins[pin - 1].getConnections().empty();
}

nts::Tristate nts::AComponent::getLink(std::size_t pin) const
{
    // appelle compute sur les composants liés aux pins d'input
    (void)pin;
    return Undefined;
}
