/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** OrGate
*/

#ifndef ORGATE_HPP_
#define ORGATE_HPP_
#include "AComponent.hpp"

namespace nts {
    class OrGate : public nts::AComponent
    {
        public:
            OrGate();
            ~OrGate();
            void simulate(std::size_t tick) override;
        protected:
            const std::size_t _nbInputs;
            const std::size_t _nbOutputs;
    };
};

#endif /* !ORGATE_HPP_ */
