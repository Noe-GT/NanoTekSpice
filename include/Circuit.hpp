/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

#include "NanoTekSpice.hpp"
#include "Parsing.hpp"

namespace nts
{
    class Circuit
    {
        public:
            Circuit();
            Circuit(Parsing &parsing);
            ~Circuit();
            void constructCircuit(Parsing &parsing);
            std::shared_ptr<IComponent> getComponent(const std::string name)
            const;
            std::shared_ptr<IComponent> createComponent(nts::Chipset &chipset);
            void setComponentsLinks(std::vector<Link> links);
            void setComponentsList(Parsing &parsing);
            void debug() const;
            std::vector<std::shared_ptr<IComponent>> &getInputs();
            std::vector<std::shared_ptr<IComponent>> &getOutputs();

        private:
            std::vector<std::shared_ptr<IComponent>> _allComponents;
            std::vector<std::shared_ptr<IComponent>> _inputs;
            std::vector<std::shared_ptr<IComponent>> _outputs;
    };
};

#endif /* !CIRCUIT_HPP_ */
