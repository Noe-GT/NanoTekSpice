/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** GC4030
*/

#ifndef GC4030_HPP_
#define GC4030_HPP_

#include "../XorGate.hpp"

namespace nts
{
    namespace component
    {
        class GC4030 : public nts::AComponent
        {
            public:
                GC4030(const std::string &name="None");
                ~GC4030();
                nts::Tristate run(size_t pin);
            private:
                nts::component::XorGate _xg1;
                nts::component::XorGate _xg2;
                nts::component::XorGate _xg3;
                nts::component::XorGate _xg4;
        };
    };
};

#endif /* !GC4030_HPP_ */
