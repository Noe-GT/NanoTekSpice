/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** XorGate
*/

#ifndef XORGATE_HPP_
#define XORGATE_HPP_

#include "AComponent.hpp"

//  in_1  -1-+---|
//           |xor |-3- out
//  in_2  -2-+---/

namespace nts
{
    namespace component
    {
        class XorGate : public nts::AComponent
        {
            public:
                XorGate(const std::string &name="None");
                ~XorGate();
                nts::Tristate run(size_t) final;
        };
    };
};

#endif /* !XORGATE_HPP_ */
