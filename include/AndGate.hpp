/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** AndGate
*/

#ifndef ANDGATE_HPP_
#define ANDGATE_HPP_
#include "AComponent.hpp"

// in_1  -1-+---|
//          | &  |-3- out
// in_2  -2-+---|

namespace nts {
    namespace component {
        class AndGate : public nts::AComponent
        {
            public:
                AndGate();
                ~AndGate();
                void simulate(std::size_t tick) override;
        };
    };
}

#endif /* !ANDGATE_HPP_ */
