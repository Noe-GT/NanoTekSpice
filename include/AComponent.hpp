/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_
#include "IComponent.hpp"
#include "Connection.hpp"

namespace nts {
    class AComponent : public IComponent {
        public:
            AComponent();
            ~AComponent();
            virtual void simulate(std::size_t tick) override;
            void setLink(std::size_t pin, nts::IComponent &other,
            std::size_t otherPin) final;
            bool isConnected(std::size_t pin, nts::IComponent &other,
            std::size_t otherPin) const;
            bool isConnected(std::size_t pin) const;
            bool isPinUsed(std::size_t pin) const;
            bool isPinInRange(std::size_t pin) const;
            bool isInputPin(std::size_t pin) const;
            bool isOutputPin(std::size_t pin) const;
            Connection *getConnection(std::size_t pin) const;
            nts::Tristate getLink(std::size_t pin) const;

        protected:
            std::string _name;
            std::vector<Connection *> _connections;
            const std::size_t _nbInputs;
            const std::size_t _nbOutputs;
    };
}

#endif /* !ACOMPONENT_HPP_ */
