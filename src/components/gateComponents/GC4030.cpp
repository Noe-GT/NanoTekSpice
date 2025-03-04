/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** GC4030
*/

#include "../../../include/components/gateComponents/GC4030.hpp"

nts::component::GC4030::GC4030(const std::string &name):
    nts::AComponent(name), _xorGates()
{
    for (int i = 0; i < 4; i++)
        this->_xorGates.emplace_back(new nts::component::XorGate());

    this->_pins.emplace_back(this->_xorGates[0]->getPin(0)); // pin 01
    this->_pins.push_back(this->_xorGates[0]->getPin(1)); // pin 02
    this->_pins.push_back(this->_xorGates[0]->getPin(2)); // pin 03

    this->_pins.push_back(this->_xorGates[1]->getPin(2)); // pin 04
    this->_pins.push_back(this->_xorGates[1]->getPin(1)); // pin 05
    this->_pins.push_back(this->_xorGates[1]->getPin(0)); // pin 06

    this->_pins.emplace_back(new nts::Pin(PinType::IGNORED, 7)); // pin 07

    this->_pins.push_back(this->_xorGates[2]->getPin(0)); // pin 08
    this->_pins.push_back(this->_xorGates[2]->getPin(1)); // pin 09
    this->_pins.push_back(this->_xorGates[2]->getPin(2)); // pin 10

    this->_pins.push_back(this->_xorGates[3]->getPin(2)); // pin 11
    this->_pins.push_back(this->_xorGates[3]->getPin(1)); // pin 12
    this->_pins.push_back(this->_xorGates[3]->getPin(0)); // pin 13

    this->_pins.emplace_back(new nts::Pin(PinType::IGNORED, 14)); // pin 14
}

nts::component::GC4030::~GC4030()
{
}
