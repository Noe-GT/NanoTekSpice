/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_
#include "IComponent.hpp"

namespace nts {
    class Connection {
        public:
            Connection(std::size_t pin, nts::IComponent &other,
            std::size_t otherPin, nts::Tristate val=Undefined);
            ~Connection();
            std::size_t getPin() const;
            nts::IComponent &getComponent() const;
            std::size_t getOtherPin() const;
            nts::Tristate getVal() const;

        private:
            std::size_t _pin;
            nts::IComponent &_other;
            std::size_t _otherPin;
            nts::Tristate _val;
    };

    class AComponent : public IComponent {
        public:
            AComponent();
            ~AComponent();
            virtual void simulate(std::size_t tick) override;
            void setLink(std::size_t pin, nts::IComponent &other,
            std::size_t otherPin) final;
            bool isAlreadyConnected(std::size_t pin, nts::IComponent &other,
            std::size_t otherPin) const;
            Connection *getConnection(std::size_t pin) const;
            nts::Tristate getLink(std::size_t pin) const;

        private:
            std::vector<Connection *> _inputs;
            std::vector<Connection *> _outputs;
            const std::size_t _nbInputs;
            const std::size_t _nbOutputs;
    };
}

#endif /* !ACOMPONENT_HPP_ */
