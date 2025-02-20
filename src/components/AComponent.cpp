/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** AComponent
*/

#include "../../include/AComponent.hpp"

nts::AComponent::AComponent(size_t nbInputs, size_t nbOutputs,
    const std::string &name):
    _pins(),
    _name(name),
    _nbInputs(nbInputs),
    _nbOutputs(nbOutputs)
{
}

nts::AComponent::~AComponent()
{
}

std::string nts::AComponent::getName() const
{
    return this->_name;
}

bool nts::AComponent::isPinInRange(size_t pin) const
{
    return pin > 0 && pin <= this->_nbInputs + this->_nbOutputs;
}

bool nts::AComponent::isInputPin(size_t pin)
{
    if (!this->isPinInRange(pin))
        throw Exception("Incalid pin number");
    return this->getPin(pin).getPinType() == INPUT;
}

bool nts::AComponent::isOutputPin(size_t pin)
{
    if (!this->isPinInRange(pin))
        throw Exception("Incalid pin number");
    return this->getPin(pin).getPinType() == OUTPUT;
}

void nts::AComponent::setLink(size_t pin, nts::IComponent &other,
    size_t otherPin)
{
    if (this->getName() == other.getName())
        throw Exception("Can't link a component to itself");
    if (!this->isPinInRange(pin))
        throw Exception("Invalid pin number");
    if (this->getPin(pin).getPinType() == other.getPin(
    otherPin).getPinType())
        throw Exception("Can't link 2 pins with the same type");
    if (this->isConnected(pin, other, otherPin))
        return;
    if (this->isInputPin(pin) && this->isConnected(pin))
        throw Exception("Pin already used");
    for (size_t i = 0; i < this->getPin(pin).getConnections().size(); i++) {
        if (this->getPin(pin).getConnections()[i].getLink().getName() ==
        other.getName()) {
            this->getPin(pin).getConnections()[i].getPins().push_back(
            otherPin);
            return other.setLink(otherPin, *this, pin);
        }
    }
    this->getPin(pin).getConnections().push_back(Connection(other,
    otherPin));
    other.setLink(otherPin, *this, pin);
}

bool nts::AComponent::isConnected(size_t pin, nts::IComponent &other,
    size_t otherPin)
{
    if (!this->isPinInRange(pin))
        throw Exception("Invalid pin number");
    for (size_t i = 0; i < this->getPin(pin).getConnections().size(); i++)
        if (this->getPin(pin).getConnections()[i].getLink().getName() ==
        other.getName() && this->getPin(pin).getConnections()[i].find(
        otherPin))
            return true;
    return false;
}

bool nts::AComponent::isConnected(size_t pin)
{
    if (!this->isPinInRange(pin))
        throw Exception("Invalid pin number");
    return !this->getPin(pin).getConnections().empty();
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
    if (!this->isPinInRange(pin))
        throw Exception("Invalid pin number");
    this->getPin(pin).setVal(value);
}

nts::Pin &nts::AComponent::getPin(std::size_t pin)
{
    if (!this->isPinInRange(pin))
        throw Exception("Invalid pin number");
    return this->_pins[pin - 1];
}

void nts::AComponent::refreshInputs()
{
    size_t pinNb;

    for (nts::Pin &pin : this->_pins) {
        if (pin.getPinType() == nts::PinType::INPUT && pin.getConnections().size() > 0) {
            pinNb = pin.getConnections()[0].getPins()[0];
            pin.setVal(pin.getConnections()[0].getLink().compute(pinNb));
        }
    }
}

nts::Tristate nts::AComponent::compute(size_t pin)
{
    nts::Tristate precedValue = nts::Tristate::Undefined;

    for (nts::Pin &in_pin : this->_pins) {
        if (in_pin.getPinType() == nts::PinType::INPUT && in_pin.getConnections().size() > 0) {
            precedValue = in_pin.getConnections()[0].getLink().compute(in_pin.getConnections()[0].getPins()[0]);
            in_pin.setVal(precedValue);
        }
    }
    (void)pin;
    return this->run();
}

nts::Tristate nts::AComponent::run() {
    return nts::Tristate::Undefined;
}

void nts::AComponent::simulate(size_t tick)
{
    for (nts::Pin &in_pin : this->_pins) {
        if (in_pin.getPinType() == nts::PinType::INPUT && in_pin.getConnections().size() > 0) {
            in_pin.getConnections()[0].getLink().simulate(tick);
        }
    }
}
