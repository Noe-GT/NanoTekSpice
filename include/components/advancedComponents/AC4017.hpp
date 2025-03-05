/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** AC4017
*/

#ifndef AC4017_HPP_
#define AC4017_HPP_
#include "../AComponent.hpp"

namespace nts {
    namespace component {
        class AC4017 : public nts::AComponent
        {
            public:
                AC4017(const std::string &name);
                ~AC4017();
                nts::Tristate run(size_t pin);
        };
    }
}
#endif /* !AC4017_HPP_ */
