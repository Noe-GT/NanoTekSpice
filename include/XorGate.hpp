/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** XorGate
*/

#ifndef XORGATE_HPP_
#define XORGATE_HPP_
#include "AComponent.hpp"

namespace nts {
    class XorGate : public nts::AComponent
    {
        public:
            XorGate();
            ~XorGate();
            void simulate(std::size_t tick) override;
        protected:
            const std::size_t _nbInputs;
            const std::size_t _nbOutputs;
    };
};

#endif /* !XORGATE_HPP_ */
