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

namespace nts
{
    class Chipset
    {
        public:
            Chipset(const std::string &line);
            Chipset(const std::string &type, const std::string &name);
            ~Chipset();
            std::string getType() const;
            std::string getName() const;

        private:
            std::string _type;
            std::string _name;
    };

    class Link {
        public:
            Link(const std::string &line);
            Link(const std::string &c1, size_t pin1,
            const std::string &c2, size_t pin2);
            ~Link();
            std::pair<std::string, size_t> getComponent1() const;
            std::pair<std::string, size_t> getComponent2() const;

        private:
            std::pair<std::string, size_t> _component1;
            std::pair<std::string, size_t> _component2;
    };

    class Parsing
    {
        public:
            enum ParsingType
            {
                NONE,
                CHIPSET,
                LINK
            };

            Parsing();
            Parsing(const std::string &filePath);
            ~Parsing();
            void setFilePath(const std::string &filePath);
            void getFile();
            void printFile() const;
            void printFile(size_t n) const;
            std::string &cleanStr(std::string &str);
            std::string &delComment(std::string &line);
            size_t getStringStreamLength(std::stringstream &&ss) const;
            size_t getCharOcc(const std::string &str, char c) const;
            bool isStrAlnum(const std::string &str) const;
            bool isStrNum(const std::string &str) const;
            bool isChipset(const std::string &line) const;
            bool isLink(const std::string &line) const;
            void checkChipset(const Chipset &&chipset);
            void checkLink(const Link &&link);
            bool isExistingChipset(const std::string &name) const;
            void parseFile();
            std::vector<Chipset> getChipsets() const;
            std::vector<Link> getLinks() const;
            void debug() const;

        private:
            void extractLine(const std::string &line);

            ParsingType _parsingType;
            std::string _filePath;
            std::string _data;
            std::vector<Chipset> _chipsets;
            std::vector<Link> _links;

            bool _isOutput;
    };
}

#endif /* !PARSING_HPP_ */
