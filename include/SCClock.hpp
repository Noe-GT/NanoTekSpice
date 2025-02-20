/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** SCClock
*/

#ifndef SCCLOCK_HPP_
#define SCCLOCK_HPP_

#include "SpecialComponent.hpp"

namespace nts
{
    namespace component
    {
        class SCClock : public nts::component::SpecialComponent
        {
            public:
                SCClock(const std::string &name="None");
                ~SCClock();
                nts::Tristate run(void) final;
                void simulate(size_t tick) final;
        };
    };
}

#endif /* !SCCLOCK_HPP_ */
