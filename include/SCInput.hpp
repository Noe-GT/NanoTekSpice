/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** SCInput
*/

#ifndef SCINPUT_HPP_
#define SCINPUT_HPP_

#include "SpecialComponent.hpp"

namespace nts
{
    namespace component
    {
        class SCInput : public nts::component::SpecialComponent
        {
            public:
                SCInput(const std::string &name="None");
                ~SCInput();
                nts::Tristate run(void) final;
        };
    };
}

#endif /* !SCINPUT_HPP_ */
