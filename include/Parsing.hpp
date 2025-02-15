/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** Parsing
*/

#ifndef PARSING_HPP_
#define PARSING_HPP_
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include "Exception.hpp"

namespace nts {
    class Chipset {
        public:
            Chipset(const std::string &type, const std::string &name);
            ~Chipset();

        private:
            const std::string _type;
            const std::string _name;
    };

    class Link {
        public:
            Link(const std::string &c1, std::size_t pin1,
            const std::string &c2, std::size_t pin2);
            ~Link();

        private:
            const std::pair<std::string, std::size_t> _component1;
            const std::pair<std::string, std::size_t> _component2;
    };

    class Parsing {
        public:
            Parsing();
            Parsing(const std::string &filePath);
            ~Parsing();
            void setFilePath(const std::string &filePath);
            void getFile();
            void printFile() const;
            void printFile(std::size_t n) const;
            std::string &cleanStr(std::string &str);
            std::string &delComments(std::string &line);
            std::size_t getStringStreamLength(std::stringstream &ss);
            std::size_t getCharOcc(std::string &str, char c);
            bool isStrAlnum(std::string &str);
            bool isStrNum(std::string &str);
            bool isChipset(std::string &line);
            bool isLink(std::string &line);

        private:
            std::string _filePath;
            std::string _data;
            std::vector<Chipset> _chipsets;
            std::vector<Link> _links;
    };
}

#endif /* !PARSING_HPP_ */
