/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** AndGate
*/

#ifndef ANDGATE_HPP_
#define ANDGATE_HPP_
#include "AComponent.hpp"

namespace nts {
    class AndGate : public nts::AComponent
    {
        public:
            AndGate();
            ~AndGate();
            void simulate(std::size_t tick) override;
        protected:
            const std::size_t _nbInputs;
            const std::size_t _nbOutputs;
    };
};

#endif /* !ANDGATE_HPP_ */
