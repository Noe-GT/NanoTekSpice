/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** SCClock
*/

#ifndef SCCLOCK_HPP_
#define SCCLOCK_HPP_

#include "../AComponent.hpp"

namespace nts
{
    namespace component
    {
        class SCClock : public nts::AComponent
        {
            public:
                SCClock(const std::string &name="None");
                ~SCClock();
                nts::Tristate run(void) final;
                void simulate(size_t tick) final;
                bool setValue(std::string value) final;
            private:
                nts::Tristate _innerValue;
        };
    };
};

#endif /* !SCCLOCK_HPP_ */
