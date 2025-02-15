/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** SCFalse
*/

#ifndef SCFALSE_HPP_
#define SCFALSE_HPP_
#include "AComponent.hpp"

namespace component {
    class SCFalse : public nts::AComponent
    {
        public:
            SCFalse();
            ~SCFalse();
            void simulate(std::size_t tick) final;
    };
};

#endif /* !SCFALSE_HPP_ */
