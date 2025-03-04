/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** GC4081
*/

#include "../../../include/components/gateComponents/GC4081.hpp"

nts::component::GC4081::GC4081(const std::string &name):
    nts::AComponent(name),
    _a1(),
    _a2(),
    _a3(),
    _a4()
{
    this->_pins.push_back(this->_a1.getPin(1));
    this->_pins.push_back(this->_a1.getPin(2));
    this->_pins.push_back(this->_a1.getPin(3));
    this->_pins.push_back(this->_a2.getPin(3));
    this->_pins.push_back(this->_a2.getPin(1));
    this->_pins.push_back(this->_a2.getPin(2));
    this->_pins.push_back(std::make_shared<nts::Pin>(nts::PinType::IGNORED, 7));
    this->_pins.push_back(this->_a3.getPin(1));
    this->_pins.push_back(this->_a3.getPin(2));
    this->_pins.push_back(this->_a3.getPin(3));
    this->_pins.push_back(this->_a4.getPin(3));
    this->_pins.push_back(this->_a4.getPin(1));
    this->_pins.push_back(this->_a4.getPin(2));
    this->_pins.push_back(std::make_shared<nts::Pin>(nts::PinType::IGNORED, 14));
}

nts::component::GC4081::~GC4081()
{
}

nts::Tristate nts::component::GC4081::run(size_t pin)
{
    switch (pin) {
        case 3:
            this->_a1.compute(3);
            return this->_a1.run(3);
        case 4:
            this->_a2.compute(3);
            return this->_a2.run(3);
        case 10:
            this->_a3.compute(3);
            return this->_a3.run(3);
        case 11:
            this->_a4.compute(3);
            return this->_a4.run(3);
        default:
            throw Exception("Incorrect pin given");
    }
}
