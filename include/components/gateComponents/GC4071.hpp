/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** GC4071
*/

#ifndef GC4071_HPP_
#define GC4071_HPP_

#include "../OrGate.hpp"

namespace nts
{
    namespace component
    {
        class GC4071 : public nts::AComponent
        {
            public:
                GC4071(const std::string &name="None");
                ~GC4071();
                nts::Tristate run(size_t) final;

            private:
                nts::component::OrGate _o1;
                nts::component::OrGate _o2;
                nts::component::OrGate _o3;
                nts::component::OrGate _o4;
        };
    };
};

#endif /* !GC4071_HPP_ */
