/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** SpecailComponent
*/

#ifndef SPECAILCOMPONENT_HPP_
#define SPECAILCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts
{
    namespace component
    {
        class SpecialComponent : public nts::AComponent
        {
            public:
                SpecialComponent(size_t in, size_t out, const std::string&);
                ~SpecialComponent();
                void setValue(nts::Tristate inputValue);
                nts::Tristate getValue() const;
            private:
                nts::Tristate _innerValue;
        };
    };
}


#endif /* !SPECAILCOMPONENT_HPP_ */
