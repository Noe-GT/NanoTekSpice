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

namespace nts
{
    namespace component
    {
        class AndGate : public nts::AComponent
        {
            public:
                AndGate(const std::string &name="None");
                ~AndGate();
                nts::Tristate run(void) final;
            };
    };
};

#endif /* !ANDGATE_HPP_ */
