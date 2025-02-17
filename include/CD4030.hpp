/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** CD4030
*/

#ifndef CD4030_HPP_
#define CD4030_HPP_

#include "XorGate.hpp"
#include <list>

namespace nts
{
    namespace component
    {
        class CD4030 : public nts::AComponent
        {
            public:
                CD4030(const std::string &name="None");
                ~CD4030();
                void simulate(size_t tick) override;
            private:
                std::list<nts::component::XorGate &> _xorGates;
        };
    };
}

#endif /* !CD4030_HPP_ */
