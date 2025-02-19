/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** Circuit
*/

#include "../include/Circuit.hpp"

nts::Circuit::Circuit()
{
}

nts::Circuit::Circuit(nts::Parsing &parsing)
{
    this->setComponentsList(parsing);
    this->setComponentsLinks(parsing.getLinks());
}

nts::Circuit::~Circuit()
{
}

void nts::Circuit::constructCircuit(Parsing &parsing)
{
    this->setComponentsList(parsing);
    this->setComponentsLinks(parsing.getLinks());
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

    if (type == "input")    return std::make_shared<nts::component::SCInput>(name);
    if (type == "output")   return std::make_shared<nts::component::SCOutput>(name);
    if (type == "and")      return std::make_shared<nts::component::AndGate>(name);
    if (type == "or")       return std::make_shared<nts::component::OrGate>(name);
    if (type == "not")      return std::make_shared<nts::component::NotGate>(name);
    if (type == "xor")      return std::make_shared<nts::component::XorGate>(name);
    if (type == "clock")    return std::make_shared<nts::component::SCClock>(name);
    if (type == "false")    return std::make_shared<nts::component::SCFalse>(name);
    if (type == "true")     return std::make_shared<nts::component::SCTrue>(name);
    throw Exception("Unknown component given");
}

void nts::Circuit::setComponentsLinks(std::vector<Link> links)
{
    std::string name;
    std::pair<std::string, size_t> p1;
    std::pair<std::string, size_t> p2;

    for (size_t i = 0; i < this->_allComponents.size(); i++) {
        name = this->_allComponents[i]->getName();
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
    std::shared_ptr<IComponent> newComponent;
    std::string componentType;

    for (size_t i = 0; i < parsing.getChipsets().size(); i++) {
        newComponent = this->createComponent(parsing.getChipsets()[i]);
        componentType = parsing.getChipsets()[i].getType();
        this->_allComponents.push_back(newComponent);
        if (componentType == "input" || componentType == "clock")
            this->_inputs.push_back(newComponent);
        else if (componentType == "output")
            this->_outputs.push_back(newComponent);
    }
}

void nts::Circuit::debug() const
{
    std::cout << "All components :" << std::endl;
    for (size_t i = 0; i < this->_allComponents.size(); i++) {
        std::cout <<
        "IComponent : " << this->_allComponents[i]->getName()
        << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Input components :" << std::endl;
    for (size_t i = 0; i < this->_inputs.size(); i++) {
        std::cout <<
        "IComponent : " << this->_inputs[i]->getName()
        << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Output components :" << std::endl;
    for (size_t i = 0; i < this->_outputs.size(); i++) {
        std::cout <<
        "IComponent : " << this->_outputs[i]->getName()
        << std::endl;
    }
}

std::vector<std::shared_ptr<nts::IComponent>> &nts::Circuit::getOutputs()
{
    return this->_outputs;
}
