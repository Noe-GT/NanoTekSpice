/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** SCTrue
*/

#ifndef SCTRUE_HPP_
#define SCTRUE_HPP_
#include "AComponent.hpp"

namespace nts {
    namespace component {
        class SCTrue : public nts::AComponent
        {
            public:
                SCTrue();
                ~SCTrue();
                void simulate(std::size_t tick) final;
        };
    };
}

#endif /* !SCTRUE_HPP_ */
