/*
** EPITECH PROJECT, 2025
** nanotekspice
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
    #define ACOMPONENT_HPP_
    #include "IComponent.hpp"

class AComponent : public nts::IComponent
{
    public:
        AComponent();
        ~AComponent();
        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
    protected:
    private:
};

#endif /* !ACOMPONENT_HPP_ */
