/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** NandGate
*/

#ifndef NANDGATE_HPP_
#define NANDGATE_HPP_

#include "../AComponent.hpp"
#include "../AndGate.hpp"
#include "../NotGate.hpp"

namespace nts
{
    namespace component
    {
        class NandGate : public nts::AComponent
        {
            public:
                NandGate(const std::string &name="None");
                ~NandGate();
                nts::Tristate run(size_t) final;

            private:
                AndGate _and;
                NotGate _not;
        };
    };
};

#endif /* !NANDGATE_HPP_ */
