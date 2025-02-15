/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_
#include "IComponent.hpp"

namespace nts {
    class Circuit : public IComponent {
        public:
            Circuit();
            ~Circuit();
            void addComponent(IComponent &component);
            // void simulate(std::size_t tick) override;
            // void display() const;

        private:
            std::vector<IComponent &> _allComponents;
            std::vector<IComponent &> _outputs;
    };
}

#endif /* !CIRCUIT_HPP_ */
