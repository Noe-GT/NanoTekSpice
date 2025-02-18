/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** NotGate
*/

#ifndef NOTGATE_HPP_
#define NOTGATE_HPP_

#include "AComponent.hpp"

namespace nts
{
    namespace component
    {
        class NotGate : public nts::AComponent
        {
            public:
                NotGate(const std::string &name="Name");
                ~NotGate();
                void run(void) final;
        };
    };
}

#endif /* !NOTGATE_HPP_ */
