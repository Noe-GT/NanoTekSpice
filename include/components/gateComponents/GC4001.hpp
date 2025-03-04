/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** GC4001
*/

#ifndef GC4001_HPP_
#define GC4001_HPP_

#include "../extraComponents/NorGate.hpp"

namespace nts
{
    namespace component
    {
        class GC4001 : public nts::AComponent
        {
            public:
                GC4001(const std::string &name="None");
                ~GC4001();
                nts::Tristate run(size_t) final;

            private:
                nts::component::NorGate _ng1;
                nts::component::NorGate _ng2;
                nts::component::NorGate _ng3;
                nts::component::NorGate _ng4;
        };
    };
};

#endif /* !GC4001_HPP_ */
