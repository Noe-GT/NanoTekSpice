/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** GC4081
*/

#ifndef GC4081_HPP_
#define GC4081_HPP_

#include "../AComponent.hpp"
#include "../AndGate.hpp"

namespace nts
{
    namespace component
    {
        class GC4081 : public nts::AComponent
        {
            public:
                GC4081(const std::string &name="None");
                ~GC4081();
                nts::Tristate run(size_t) final;

            private:
                AndGate _a1;
                AndGate _a2;
                AndGate _a3;
                AndGate _a4;
        };
    };
};

#endif /* !GC4081_HPP_ */
