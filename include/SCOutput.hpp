/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** SCOutput
*/

#ifndef SCOUTPUT_HPP_
#define SCOUTPUT_HPP_

#include "AComponent.hpp"

namespace nts
{
    namespace component
    {
        class SCOutput : public nts::AComponent
        {
            public:
                SCOutput(const std::string &name="None");
                ~SCOutput();
                void simulate(std::size_t tick) final;
                nts::Tristate getOutput() const;
            protected:
            private:
                nts::Tristate _outputValue;
        };
    };
}

#endif /* !SCOUTPUT_HPP_ */
