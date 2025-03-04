/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** GC4071
*/

#include "../../../include/components/gateComponents/GC4071.hpp"

nts::component::GC4071::GC4071(const std::string &name):
    nts::AComponent(name),
    _o1(),
    _o2(),
    _o3(),
    _o4()
{
    this->_pins.push_back(this->_o1.getPin(1));
    this->_pins.push_back(this->_o1.getPin(2));
    this->_pins.push_back(this->_o1.getPin(3));
    this->_pins.push_back(this->_o2.getPin(3));
    this->_pins.push_back(this->_o2.getPin(1));
    this->_pins.push_back(this->_o2.getPin(2));
    this->_pins.push_back(std::make_shared<nts::Pin>(nts::PinType::IGNORED, 7));
    this->_pins.push_back(this->_o3.getPin(1));
    this->_pins.push_back(this->_o3.getPin(2));
    this->_pins.push_back(this->_o3.getPin(3));
    this->_pins.push_back(this->_o4.getPin(3));
    this->_pins.push_back(this->_o4.getPin(1));
    this->_pins.push_back(this->_o4.getPin(2));
    this->_pins.push_back(std::make_shared<nts::Pin>(nts::PinType::IGNORED, 14));
}

nts::component::GC4071::~GC4071()
{
}

nts::Tristate nts::component::GC4071::run(size_t pin)
{
    switch (pin) {
        case 3:
            this->_o1.compute(3);
            return this->_o1.run(3);
        case 4:
            this->_o2.compute(3);
            return this->_o2.run(3);
        case 10:
            this->_o3.compute(3);
            return this->_o3.run(3);
        case 11:
            this->_o4.compute(3);
            return this->_o4.run(3);
        default:
            throw Exception("Incorrect pin given");
    }
}
