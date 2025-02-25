/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** Connection
*/

#ifndef CONNECTION_HPP_
#define CONNECTION_HPP_

#include "components/IComponent.hpp"

namespace nts
{
    class Connection
    {
        public:
            Connection(IComponent &link, size_t pin);
            ~Connection();
            IComponent &getLink() const;
            std::vector<size_t> getPins() const;
            bool find(size_t pinId) const;

        private:
            IComponent &_link;
            std::vector<size_t> _pins;
    };
};

#endif /* !CONNECTION_HPP_ */
