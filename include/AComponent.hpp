/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_
#include "IComponent.hpp"
#include "Pin.hpp"

namespace nts {
    class AComponent : public IComponent {
        public:
            AComponent(size_t nbInputs, size_t nbOutputs);
            ~AComponent();
            virtual void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin) override;
            void setLink(std::size_t pin, nts::IComponent &other,
            std::size_t otherPin) final;
            bool isConnected(std::size_t pin, nts::IComponent &other,
            std::size_t otherPin) const;
            bool isConnected(std::size_t pin) const;
            bool isPinInRange(std::size_t pin) const;
            bool isInputPin(std::size_t pin) const;
            bool isOutputPin(std::size_t pin) const;
            nts::Tristate getLink(std::size_t pin) const;

        protected:
            std::string _name;
            std::vector<Pin> _pins;
            const std::size_t _nbInputs;
            const std::size_t _nbOutputs;
        };
}

#endif /* !ACOMPONENT_HPP_ */
