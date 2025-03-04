/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** GC4011
*/

#include "../../../include/components/gateComponents/GC4011.hpp"

nts::component::GC4011::GC4011(const std::string &name):
    nts::AComponent(name),
    _ng1(),
    _ng2(),
    _ng3(),
    _ng4()
{
    this->_pins.push_back(this->_ng1.getPin(1));
    this->_pins.push_back(this->_ng1.getPin(2));
    this->_pins.push_back(this->_ng1.getPin(3));
    this->_pins.push_back(this->_ng2.getPin(3));
    this->_pins.push_back(this->_ng2.getPin(1));
    this->_pins.push_back(this->_ng2.getPin(2));
    this->_pins.push_back(std::make_shared<nts::Pin>(nts::PinType::IGNORED, 7));
    this->_pins.push_back(this->_ng3.getPin(1));
    this->_pins.push_back(this->_ng3.getPin(2));
    this->_pins.push_back(this->_ng3.getPin(3));
    this->_pins.push_back(this->_ng4.getPin(3));
    this->_pins.push_back(this->_ng4.getPin(1));
    this->_pins.push_back(this->_ng4.getPin(2));
    this->_pins.push_back(std::make_shared<nts::Pin>(nts::PinType::IGNORED, 14));
}

nts::component::GC4011::~GC4011()
{
}

nts::Tristate nts::component::GC4011::run(size_t pin)
{
    switch (pin) {
        case 3:
            return this->_ng1.run(3);
        case 4:
            return this->_ng2.run(3);
        case 10:
            return this->_ng3.run(3);
        case 11:
            return this->_ng4.run(3);
        default:
            throw Exception("Incorrect pin given");
    }
}
