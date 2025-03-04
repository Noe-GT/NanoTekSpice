/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** GC4069
*/

#include "../../../include/components/gateComponents/GC4069.hpp"

nts::component::GC4069::GC4069(const std::string &name):
    nts::AComponent(name),
    _n1(),
    _n2(),
    _n3(),
    _n4(),
    _n5(),
    _n6()
{
    this->_pins.push_back(this->_n1.getPin(1));
    this->_pins.push_back(this->_n1.getPin(2));
    this->_pins.push_back(this->_n2.getPin(1));
    this->_pins.push_back(this->_n2.getPin(2));
    this->_pins.push_back(this->_n3.getPin(1));
    this->_pins.push_back(this->_n3.getPin(2));
    this->_pins.push_back(std::make_shared<nts::Pin>(nts::PinType::IGNORED, 7));
    this->_pins.push_back(this->_n4.getPin(2));
    this->_pins.push_back(this->_n4.getPin(1));
    this->_pins.push_back(this->_n5.getPin(2));
    this->_pins.push_back(this->_n5.getPin(1));
    this->_pins.push_back(this->_n6.getPin(2));
    this->_pins.push_back(this->_n6.getPin(1));
    this->_pins.push_back(std::make_shared<nts::Pin>(nts::PinType::IGNORED, 14));
}

nts::component::GC4069::~GC4069()
{
}

nts::Tristate nts::component::GC4069::run(size_t pin)
{
    switch (pin) {
        case 2:
            return this->_n1.run(2);
        case 4:
            return this->_n2.run(2);
        case 6:
            return this->_n3.run(2);
        case 8:
            return this->_n4.run(2);
        case 10:
            return this->_n5.run(2);
        case 12:
            return this->_n6.run(2);
        default:
            throw Exception("Incorrect pin given");
    }
}
