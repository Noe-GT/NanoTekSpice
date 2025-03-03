/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** SCOutput
*/

#ifndef SCOUTPUT_HPP_
#define SCOUTPUT_HPP_

#include "../AComponent.hpp"

namespace nts
{
    namespace component
    {
        class SCOutput : public nts::AComponent
        {
            public:
                SCOutput(const std::string &name="None");
                ~SCOutput();
                nts::Tristate run(size_t) final;
            private:
                nts::Tristate _innerValue;
        };
    };
};

#endif /* !SCOUTPUT_HPP_ */
