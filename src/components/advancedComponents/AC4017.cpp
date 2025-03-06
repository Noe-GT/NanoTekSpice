/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** AC4017
*/

#include "../../../include/components/advancedComponents/AC4017.hpp"

nts::component::AC4017::AC4017(const std::string &name):
    nts::AComponent(name),
    _precVal(TUNDEF)
{
    this->_pins.emplace_back(new nts::Pin(nts::PinType::OUTPUT, 1));
    this->_pins.emplace_back(new nts::Pin(nts::PinType::OUTPUT, 2));
    this->_pins.emplace_back(new nts::Pin(nts::PinType::OUTPUT, 3));
    this->_pins.emplace_back(new nts::Pin(nts::PinType::OUTPUT, 4));
    this->_pins.emplace_back(new nts::Pin(nts::PinType::OUTPUT, 5));
    this->_pins.emplace_back(new nts::Pin(nts::PinType::OUTPUT, 6));
    this->_pins.emplace_back(new nts::Pin(nts::PinType::OUTPUT, 7));
    this->_pins.emplace_back(new nts::Pin(nts::PinType::IGNORED, 8));
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

void nts::component::AC4017::reset_counter(std::vector<int> &outIndexes)
{
    for (int i : outIndexes)
        this->setPin(i, TFALSE);
    this->setPin(12, TTRUE);
}

void nts::component::AC4017::counter()
{
    std::vector<int> outIndexes = {3, 2, 4, 7, 10, 1, 5, 6, 9, 11};

    for (int i : outIndexes) {
        if (this->getPin(i)->getVal() != TTRUE) {
            if (i == 1)
                this->setPin(12, TFALSE);
            return this->setPin(i, TTRUE);
        }
    }
    this->reset_counter(outIndexes);
}

nts::Tristate nts::component::AC4017::run(size_t pin)
{
    if (this->getPin(13)->getVal() != TFALSE) {
        return this->getPin(pin)->getVal();
    }
    if (this->_precVal == TFALSE && this->getPin(14)->getVal() == TTRUE) {
        counter();
    }
    this->_precVal = this->getPin(14)->getVal();
    return this->getPin(pin)->getVal();
}
