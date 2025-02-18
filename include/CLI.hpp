/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** CLI
*/

#ifndef CLI_HPP_
#define CLI_HPP_

#include "../include/Circuit.hpp"
#include "External.hpp"

namespace nts
{
    class CLI
    {
        public:
            CLI(nts::Circuit &circuit);
            ~CLI();
            void exit() const;
            void display() const;
            void simulate();
            void loop();
            void run();
        private:
            nts::Circuit &_circuit;
            int _tick;
    };
};

#endif /* !CLI_HPP_ */
