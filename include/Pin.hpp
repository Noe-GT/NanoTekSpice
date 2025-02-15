/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** Pin
*/

#ifndef PIN_HPP_
#define PIN_HPP_
#include "IComponent.hpp"
#include "Connection.hpp"

namespace nts {
    enum PinType {
        INPUT,
        OUTPUT
    };

    class Pin {
        public:
            Pin(PinType pinType, std::size_t id, nts::IComponent &component);
            ~Pin();
            PinType getPinType() const;
            std::size_t getId() const;
            nts::IComponent &getComponent() const;
            std::vector<Connection> getConnections() const;
            nts::Tristate getVal() const;
            void setVal(nts::Tristate val);

        private:
            PinType _pinType;
            std::size_t _id;
            nts::IComponent &_component;
            std::vector<Connection> _connections;
            nts::Tristate _val;
    };
}

#endif /* !PIN_HPP_ */
