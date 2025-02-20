/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** SCOutput
*/

#ifndef SCOUTPUT_HPP_
#define SCOUTPUT_HPP_

#include "SpecialComponent.hpp"

namespace nts
{
    namespace component
    {
        class SCOutput : public nts::component::SpecialComponent
        {
            public:
                SCOutput(const std::string &name="None");
                ~SCOutput();
                nts::Tristate run(void) final;
        };
    };
}

#endif /* !SCOUTPUT_HPP_ */
