/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** GC4030
*/

#include "../../../include/components/gateComponents/GC4030.hpp"

nts::component::GC4030::GC4030(const std::string &name):
    nts::AComponent(name),
    _xg1(),
    _xg2(),
    _xg3(),
    _xg4()
{
    this->_pins.push_back(this->_xg1.getPin(1));
    this->_pins.push_back(this->_xg1.getPin(2));
    this->_pins.push_back(this->_xg1.getPin(3));
    this->_pins.push_back(this->_xg2.getPin(3));
    this->_pins.push_back(this->_xg2.getPin(1));
    this->_pins.push_back(this->_xg2.getPin(2));
    this->_pins.push_back(std::make_shared<nts::Pin>(nts::PinType::IGNORED, 7));
    this->_pins.push_back(this->_xg3.getPin(1));
    this->_pins.push_back(this->_xg3.getPin(2));
    this->_pins.push_back(this->_xg3.getPin(3));
    this->_pins.push_back(this->_xg4.getPin(3));
    this->_pins.push_back(this->_xg4.getPin(1));
    this->_pins.push_back(this->_xg4.getPin(2));
    this->_pins.push_back(std::make_shared<nts::Pin>(nts::PinType::IGNORED, 14));
}

nts::component::GC4030::~GC4030()
{
}

nts::Tristate nts::component::GC4030::run(size_t pin)
{
    switch (pin) {
        case 3:
            return this->_xg1.run(3);
        case 4:
            return this->_xg2.run(3);
        case 10:
            return this->_xg3.run(3);
        case 11:
            return this->_xg4.run(3);
        default:
            throw Exception("Incorrect pin given");
    }
}
