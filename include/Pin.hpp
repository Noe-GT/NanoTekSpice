/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** Pin
*/

#ifndef PIN_HPP_
#define PIN_HPP_
#include "IComponent.hpp"
#include <map>
#include <vector>

namespace nts {
    class Pin {
        public:
            Pin(std::size_t id, nts::IComponent &component);
            ~Pin();
            std::size_t getId() const;
            nts::IComponent &getComponent() const;
            std::map<IComponent &, std::vector<size_t>> getConnections()
            const;
            nts::Tristate getVal() const;
            void setVal(nts::Tristate val);

        private:
            std::size_t _id;
            nts::IComponent &_component;
            std::map<IComponent &, std::vector<size_t>> _connections;
            nts::Tristate _val;
    };
}

#endif /* !PIN_HPP_ */
