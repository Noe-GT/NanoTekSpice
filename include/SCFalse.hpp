/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** SCFalse
*/

#ifndef SCFALSE_HPP_
#define SCFALSE_HPP_

#include "SpecialComponent.hpp"

namespace nts
{
    namespace component
    {
        class SCFalse : public nts::component::SpecialComponent
        {
            public:
                SCFalse(const std::string &name="None");
                ~SCFalse();
                nts::Tristate run(void) final;
        };
    };
}

#endif /* !SCFALSE_HPP_ */
