/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** OrGate
*/

#ifndef ORGATE_HPP_
#define ORGATE_HPP_
#include "AComponent.hpp"

//  in_1  -1-+---|
        //   | or |-3- out
//  in_2  -2-+---/

namespace component {
    class OrGate : public nts::AComponent
    {
        public:
            OrGate();
            ~OrGate();
            void simulate(std::size_t tick) override;

    };
};

#endif /* !ORGATE_HPP_ */
