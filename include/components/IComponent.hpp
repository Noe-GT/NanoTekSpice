/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include "../Exception.hpp"
#include "../External.hpp"
#include "../Macros.hpp"

namespace nts
{
    class Pin;

    enum Tristate
    {
        Undefined = (-true),
        True = true,
        False = false
    };

    enum Bistate
    {
        STATE1 = 0,
        STATE2 = 1
    };

    class IComponent
    {
        public:
            ~IComponent() = default;
            virtual void simulate(size_t tick) = 0;
            virtual nts::Tristate compute(size_t pin) = 0;
            virtual nts::Tristate run(size_t pin) = 0;
            virtual void setLink(size_t pin, nts::IComponent &other,
            size_t otherPin) = 0;
            virtual std::string getName() const = 0;
            virtual std::shared_ptr<nts::Pin> &getPin(size_t pin) = 0;
            virtual bool setValue(std::string value) = 0;
            virtual nts::Bistate getRunState() const = 0;
    };
};

#endif /* !ICOMPONENT_HPP_ */
