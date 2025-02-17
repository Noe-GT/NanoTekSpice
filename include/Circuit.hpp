/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

#include "IComponent.hpp"
#include "Parsing.hpp"

#include "AndGate.hpp"
#include "OrGate.hpp"
#include "XorGate.hpp"
#include "NotGate.hpp"

#include "CD4030.hpp"

#include "SCInput.hpp"
#include "SCOutput.hpp"
#include "SCFalse.hpp"
#include "SCTrue.hpp"
#include "SCClock.hpp"

namespace nts
{
    class Circuit
    {
        public:
            Circuit(Parsing &parsing);
            ~Circuit();
            IComponent &getComponent(const std::string name);
            IComponent &&createComponent(nts::Chipset &chipset);
            void setComponentsLinks(std::vector<Link> links);
            void setComponentsList(Parsing &parsing);
            // void simulate(size_t tick) override;
            // void display() const;

        private:
            std::vector<IComponent &> _allComponents;
            std::vector<IComponent &> _outputs;
    };
}

#endif /* !CIRCUIT_HPP_ */
