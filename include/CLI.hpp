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
            void run();

        private:
            int _tick;
            Circuit _circuit;
            static bool _loop;
            bool _stopCLI;
            void exit();
            void display();
            void simulate();
            void loop();
            void setInput(std::string buff);
            Circuit &getCircuit();
            void sortInOut();
            void displayInOut(std::vector<std::shared_ptr<nts::IComponent>> &comps) const;
            static void ctrlCHandler(int signum);
    };
};

#endif /* !CLI_HPP_ */
