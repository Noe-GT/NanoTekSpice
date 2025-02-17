/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** SCClock
*/

#ifndef SCCLOCK_HPP_
#define SCCLOCK_HPP_

#include "AComponent.hpp"

namespace nts
{
    namespace component
    {
        class SCClock : public nts::AComponent
        {
            public:
                SCClock(const std::string &name="None");
                ~SCClock();
                void simulate(std::size_t tick) final;
                void setInput(nts::Tristate inputValue);
            private:
                nts::Tristate _clockValue;
        };
    };
}

#endif /* !SCCLOCK_HPP_ */
