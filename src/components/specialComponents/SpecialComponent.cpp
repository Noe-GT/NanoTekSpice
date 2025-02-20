/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** SpecailComponent
*/

#include "../../../include/SpecialComponent.hpp"

nts::component::SpecialComponent::SpecialComponent(size_t in, size_t out, const std::string &name):
    nts::AComponent(in, out, name)
{
    this->_innerValue = nts::Tristate::Undefined;
}

nts::component::SpecialComponent::~SpecialComponent()
{
}

void nts::component::SpecialComponent::setValue(nts::Tristate inputValue)
{
    this->_innerValue = inputValue;
}

nts::Tristate nts::component::SpecialComponent::getValue() const
{
    return this->_innerValue;
}
