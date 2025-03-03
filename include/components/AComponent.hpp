/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_

#include "IComponent.hpp"
#include "../Pin.hpp"

namespace nts
{
    class AComponent : public IComponent
    {
        public:
            AComponent(size_t nbInputs, size_t nbOutputs,
            const std::string &name);
            ~AComponent();
            std::string getName() const final;
            virtual void simulate(size_t tick) override;
            virtual nts::Tristate run(size_t) override;
            nts::Tristate compute(size_t pin) override;
            void setLink(size_t pin, nts::IComponent &other,
            size_t otherPin) final;
            bool isConnected(size_t pin, nts::IComponent &other,
            size_t otherPin);
            bool isConnected(size_t pin);
            bool isPinInRange(size_t pin) const;
            bool isInputPin(size_t pin);
            bool isOutputPin(size_t pin);
            bool isIgnoredPin(size_t pin);
            size_t getNbInputs() const;
            size_t getNbOutputs() const;
            void setPin(size_t pin, nts::Tristate value);
            std::shared_ptr<nts::Pin> getPin(size_t pin) final;
            virtual bool setValue(std::string value) override;

        protected:
            void refreshInputs();
            std::vector<std::shared_ptr<nts::Pin>> _pins;
            const std::string _name;
            const size_t _nbInputs;
            const size_t _nbOutputs;
    };
};

#endif /* !ACOMPONENT_HPP_ */
