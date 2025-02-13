/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** Connection
*/

#ifndef CONNECTION_HPP_
#define CONNECTION_HPP_
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
}

#endif /* !CONNECTION_HPP_ */
