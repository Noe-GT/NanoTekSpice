/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** GC4011
*/

#ifndef GC4011_HPP_
#define GC4011_HPP_

#include "../extraComponents/NandGate.hpp"

namespace nts
{
    namespace component
    {
        class GC4011 : public nts::AComponent
        {
            public:
                GC4011(const std::string &name="None");
                ~GC4011();
                nts::Tristate run(size_t) final;

            private:
                NandGate _ng1;
                NandGate _ng2;
                NandGate _ng3;
                NandGate _ng4;
        };
    };
};

#endif /* !GC4011_HPP_ */
