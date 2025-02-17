/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

#include "IComponent.hpp"

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
    class Circuit : public IComponent
    {
        public:
            Circuit();
            ~Circuit();
            IComponent &createComponent(std::string type, std::string name);
            void addComponent(IComponent &component);
            // void simulate(std::size_t tick) override;
            // void display() const;

        private:
            std::vector<IComponent &> _allComponents;
            std::vector<IComponent &> _outputs;
    };
}

#endif /* !CIRCUIT_HPP_ */
