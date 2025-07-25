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
            AComponent(const std::string &name);
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
            void setPin(size_t pin, nts::Tristate value);
            std::shared_ptr<nts::Pin> &getPin(size_t pin) final;
            virtual bool setValue(std::string value) override;
            nts::Bistate getRunState() const final;
            void switchRunState();

        protected:
            void refreshInputs();
            std::vector<std::shared_ptr<nts::Pin>> _pins;
            const std::string _name;
            nts::Bistate _runState;
    };
};

#endif /* !ACOMPONENT_HPP_ */
