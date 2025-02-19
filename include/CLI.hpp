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
            CLI();
            CLI(Circuit &circuit);
            ~CLI();
            void setCircuit(Circuit &circuit);
            void exit() const;
            void display();
            void simulate();
            void loop();
            void run();
            void setInput(std::string buff);
            Circuit &getCircuit();

        private:
            Circuit _circuit;
            int _tick;
    };
};

#endif /* !CLI_HPP_ */
