/*
** EPITECH PROJECT, 2025
** bootstrap
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_
#include <string>
#include <vector>
#include <Exception.hpp>

namespace nts {
    enum Tristate {
        Undefined = (-true),
        True = true,
        False = false
    };

    class IComponent {
        public:
            ~IComponent() = default;

            virtual void simulate(std::size_t tick) = 0;
            virtual nts::Tristate compute(std::size_t pin) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other,
            std::size_t otherPin) = 0;
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

        private:
            std::vector<nts::Connection *> _inputs;
            std::vector<nts::Connection *> _outputs;
            const std::size_t _nbInputs;
            const std::size_t _nbOutputs;
    };

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
}

#endif /* !ICOMPONENT_HPP_ */
