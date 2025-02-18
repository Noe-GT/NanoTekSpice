/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** Circuit
*/

#include "../include/Circuit.hpp"

nts::Circuit::Circuit(nts::Parsing &parsing)
{
    this->setComponentsList(parsing);
    this->setComponentsLinks(parsing.getLinks());
}

nts::Circuit::~Circuit()
{
}

std::shared_ptr<nts::IComponent> nts::Circuit::getComponent(
    const std::string name) const
{
    for (size_t i = 0; i < this->_allComponents.size(); i++)
        if (this->_allComponents[i]->getName() == name)
            return this->_allComponents[i];
    throw Exception("Component not found");
}

std::shared_ptr<nts::IComponent> nts::Circuit::createComponent(
    nts::Chipset &chipset)
{
    std::string name(chipset.getName());
    std::string type(chipset.getType());

    if (type == "input")
        return std::shared_ptr<IComponent>(new nts::component::SCInput(name));
    if (type == "output")
        return std::shared_ptr<IComponent>(new nts::component::SCOutput(name));
    if (type == "and")
        return std::shared_ptr<IComponent>(new nts::component::AndGate(name));
    if (type == "or")
        return std::shared_ptr<IComponent>(new nts::component::OrGate(name));
    throw Exception("Unknown component given");
}

void nts::Circuit::setComponentsLinks(std::vector<Link> links)
{
    std::string name;
    std::pair<std::string, size_t> p1;
    std::pair<std::string, size_t> p2;
    std::shared_ptr<IComponent> tmp;

    for (size_t i = 0; i < this->_allComponents.size(); i++) {
        tmp = this->_allComponents[i];
        name = tmp->getName();
        for (size_t j = 0; j < links.size(); j++) {
            p1 = links[j].getComponent1();
            p2 = links[j].getComponent2();
            if (p1.first != name && p2.first != name)
                continue;
            this->getComponent(p1.first)->setLink(p1.second,
            *this->getComponent(p2.first), p2.second);
        }
    }
}

void nts::Circuit::setComponentsList(nts::Parsing &parsing)
{
    std::shared_ptr<IComponent> tmp;

    for (size_t i = 0; i < parsing.getChipsets().size(); i++) {
        tmp = this->createComponent(parsing.getChipsets()[i]);
        this->_allComponents.push_back(tmp);
        if (parsing.getChipsets()[i].getType() == "output")
            this->_outputs.push_back(tmp);
    }
}

void nts::Circuit::debug() const
{
    for (size_t i = 0; i < this->_allComponents.size(); i++) {
        std::cout <<
        "IComponent : " << this->_allComponents[i]->getName()
        << std::endl;
    }
}

std::vector<std::shared_ptr<nts::IComponent>> &nts::Circuit::getOutputs()
{
    return this->_outputs;
}
