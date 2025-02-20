/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** CD4030
*/

#include "../../include/CD4030.hpp"

nts::component::CD4030::CD4030(const std::string &name):
    nts::AComponent(8, 4, name), _xorGates()
{
    // nts::component::XorGate g1;
    // nts::component::XorGate g2;
    // nts::component::XorGate g3;
    // nts::component::XorGate g4;

    this->_xorGates.emplace_back(nts::component::XorGate());
    this->_xorGates.emplace_back(nts::component::XorGate());
    this->_xorGates.emplace_back(nts::component::XorGate());
    this->_xorGates.emplace_back(nts::component::XorGate());

    // this->_pins.emplace_back(this->_xorGates[0].getPinPtr(0).get()); // pin 01
    // this->_pins.push_back(this->_xorGates[0].getPinPtr(1)); // pin 02
    // this->_pins.push_back(this->_xorGates[0].getPinPtr(2)); // pin 03

    // this->_pins.push_back(this->_xorGates[1].getPinPtr(2)); // pin 04
    // this->_pins.push_back(this->_xorGates[1].getPinPtr(1)); // pin 05
    // this->_pins.push_back(this->_xorGates[1].getPinPtr(0)); // pin 06

    // // this->_pins.emplace_back(NULL); // pin 07

    // this->_pins.push_back(this->_xorGates[2].getPinPtr(0)); // pin 08
    // this->_pins.push_back(this->_xorGates[2].getPinPtr(1)); // pin 09
    // this->_pins.push_back(this->_xorGates[2].getPinPtr(2)); // pin 10

    // this->_pins.push_back(this->_xorGates[3].getPinPtr(2)); // pin 11
    // this->_pins.push_back(this->_xorGates[3].getPinPtr(1)); // pin 12
    // this->_pins.push_back(this->_xorGates[3].getPinPtr(0)); // pin 13

    // this->_pins.emplace_back(NULL); // pin 13
}

nts::component::CD4030::~CD4030()
{
}

nts::Tristate nts::component::CD4030::run()
{
    nts::Tristate in1;
    nts::Tristate in2;

    // lauch simulate on all internal components connected to main component inputs
    return nts::Tristate::Undefined;
}
