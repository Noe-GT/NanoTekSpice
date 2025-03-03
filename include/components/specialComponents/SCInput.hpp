/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** SCInput
*/

#ifndef SCINPUT_HPP_
#define SCINPUT_HPP_

#include "../AComponent.hpp"

namespace nts
{
    namespace component
    {
        class SCInput : public nts::AComponent
        {
            public:
                SCInput(const std::string &name="None");
                ~SCInput();
                nts::Tristate run(size_t) final;
                bool setValue(std::string value) final;
                void simulate(size_t tick) final;
            private:
                nts::Tristate _innerValue;
        };
    };
};

#endif /* !SCINPUT_HPP_ */
