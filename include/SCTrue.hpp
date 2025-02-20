/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** SCTrue
*/

#ifndef SCTRUE_HPP_
#define SCTRUE_HPP_

#include "SpecialComponent.hpp"

namespace nts
{
    namespace component
    {
        class SCTrue : public nts::component::SpecialComponent
        {
            public:
                SCTrue(const std::string &name="None");
                ~SCTrue();
                nts::Tristate run(void) final;
        };
    };
}

#endif /* !SCTRUE_HPP_ */
