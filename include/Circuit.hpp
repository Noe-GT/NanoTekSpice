/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

#include <memory>

#include "IComponent.hpp"
#include "Parsing.hpp"

#include "AndGate.hpp"
#include "OrGate.hpp"
#include "XorGate.hpp"
#include "NotGate.hpp"

// #include "CD4030.hpp"

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
            std::shared_ptr<IComponent> getComponent(const std::string name)
            const;
            std::shared_ptr<IComponent> createComponent(nts::Chipset &chipset);
            void setComponentsLinks(std::vector<Link> links);
            void setComponentsList(Parsing &parsing);

            // void simulate(size_t tick) override;
            // void display() const;

        private:
            std::vector<std::shared_ptr<IComponent>> _allComponents;
            std::vector<std::shared_ptr<IComponent>> _outputs;
    };
}

#endif /* !CIRCUIT_HPP_ */
