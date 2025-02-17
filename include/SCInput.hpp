/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** SCInput
*/

#ifndef SCINPUT_HPP_
#define SCINPUT_HPP_

#include "AComponent.hpp"

namespace nts
{
    namespace component
    {
        class SCInput : public nts::AComponent
        {
            public:
                SCInput(const std::string &name="None");
                ~SCInput();
                void simulate(size_t tick) final;
                void setInput(nts::Tristate inputValue);
            private:
                nts::Tristate _inputValue;
        };
    };
}

#endif /* !SCINPUT_HPP_ */
