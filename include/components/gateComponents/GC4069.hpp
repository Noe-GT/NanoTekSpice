/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** GC4069
*/

#ifndef GC4069_HPP_
#define GC4069_HPP_

#include "../AComponent.hpp"
#include "../NotGate.hpp"

namespace nts
{
    namespace component
    {
        class GC4069 : public nts::AComponent {
            public:
                GC4069(const std::string &name="None");
                ~GC4069();
                nts::Tristate run(size_t) final;

            private:
                NotGate _n1;
                NotGate _n2;
                NotGate _n3;
                NotGate _n4;
                NotGate _n5;
                NotGate _n6;
        };
    };
};

#endif /* !GC4069_HPP_ */
