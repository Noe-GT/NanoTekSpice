/*
** EPITECH PROJECT, 2025
** bootstrap
** File description:
** IComponent
*/

#include "IComponent.hpp"

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
}

void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other,
    std::size_t otherPin)
{
    // vérifier si la liaison n'existe pas déjà avec la méthode isAldreadyConnected()
    // tester setLink()
    Connection *newConnection;

    if (pin <= 0 || pin > this->_nbInputs + this->_nbOutputs)
        throw Exception("Invalid pin number");
    newConnection = new Connection(pin, other, otherPin);
    if (pin <= this->_nbInputs)
        this->_inputs.push_back(newConnection);
    else
        this->_outputs.push_back(newConnection);
    
}

bool nts::AComponent::isAlreadyConnected(std::size_t pin,
    nts::IComponent &other, std::size_t otherPin) const
{
    Connection *tmp;

    for (int i = 0; i < this->_inputs.size(); i++) {
        tmp = this->_inputs.at(i);
        if (tmp->getPin() == pin && &tmp->getComponent() == &other &&
        tmp->getOtherPin() == otherPin)
            return true;
    }
    for (int i = 0; i < this->_outputs.size(); i++) {
        tmp = this->_outputs.at(i);
        if (tmp->getPin() == pin && &tmp->getComponent() == &other &&
        tmp->getOtherPin() == otherPin)
            return true;
    }
    return false;
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
