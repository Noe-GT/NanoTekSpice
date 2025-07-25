/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** SCTrue
*/

#include "../../../include/components/specialComponents/SCTrue.hpp"

nts::component::SCTrue::SCTrue(const std::string &name):
    nts::AComponent(name)
{
    this->_pins.emplace_back(new nts::Pin(nts::PinType::OUTPUT, 1));
    this->_pins[0]->setVal(nts::Tristate::True);
}

nts::component::SCTrue::~SCTrue()
{
}

nts::Tristate nts::component::SCTrue::run(size_t)
{
    return this->_pins[0]->getVal();
}
