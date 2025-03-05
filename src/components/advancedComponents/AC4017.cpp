/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** AC4017
*/

#include "../../../include/components/advancedComponents/AC4017.hpp"

nts::component::AC4017::AC4017(const std::string &name):
    nts::AComponent(name)
{
    this->_pins.emplace_back(new nts::Pin(nts::PinType::OUTPUT, 1));
    this->_pins.emplace_back(new nts::Pin(nts::PinType::OUTPUT, 2));
    this->_pins.emplace_back(new nts::Pin(nts::PinType::OUTPUT, 3));
    this->_pins.emplace_back(new nts::Pin(nts::PinType::OUTPUT, 4));
    this->_pins.emplace_back(new nts::Pin(nts::PinType::OUTPUT, 5));
    this->_pins.emplace_back(new nts::Pin(nts::PinType::OUTPUT, 6));
    this->_pins.emplace_back(new nts::Pin(nts::PinType::OUTPUT, 7));
    this->_pins.emplace_back(new nts::Pin(nts::PinType::OUTPUT, 8));
    this->_pins.emplace_back(new nts::Pin(nts::PinType::OUTPUT, 9));
    this->_pins.emplace_back(new nts::Pin(nts::PinType::OUTPUT, 10));
    this->_pins.emplace_back(new nts::Pin(nts::PinType::OUTPUT, 11));
    this->_pins.emplace_back(new nts::Pin(nts::PinType::OUTPUT, 12));
    this->_pins.emplace_back(new nts::Pin(nts::PinType::INPUT, 13));
    this->_pins.emplace_back(new nts::Pin(nts::PinType::INPUT, 14));
    this->_pins.emplace_back(new nts::Pin(nts::PinType::INPUT, 15));
}

nts::component::AC4017::~AC4017()
{
}

nts::Tristate nts::component::AC4017::run(size_t)
{
    return TUNDEF;
}
