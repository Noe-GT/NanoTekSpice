/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** NorGate
*/

#ifndef NORGATE_HPP_
#define NORGATE_HPP_

#include "../OrGate.hpp"
#include "../NotGate.hpp"

namespace nts
{
    namespace component
    {
        class NorGate : public nts::AComponent
        {
            public:
                NorGate(const std::string &name="None");
                ~NorGate();
                nts::Tristate run(size_t) final;

            private:
                nts::component::OrGate _or;
                nts::component::NotGate _not;
        };
    };
};

#endif /* !NORGATE_HPP_ */
