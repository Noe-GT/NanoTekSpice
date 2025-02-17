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

namespace nts
{
    enum PinType
    {
        INPUT,
        OUTPUT
    };

    class Pin
    {
        public:
            Pin(PinType pinType, size_t id);
            ~Pin();
            PinType getPinType() const;
            size_t getId() const;
            // nts::IComponent &getComponent() const;
            std::vector<Connection> getConnections() const;
            nts::Tristate getVal() const;
            void setVal(nts::Tristate val);

        private:
            PinType _pinType;
            size_t _id;
            // nts::IComponent &_component;
            nts::Tristate _val;
            std::vector<Connection> _connections;
    };
};

#endif /* !PIN_HPP_ */
