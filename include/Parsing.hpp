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
#include "Exception.hpp"

namespace nts {
    class Parsing {
        public:
            Parsing();
            Parsing(const std::string &filePath);
            ~Parsing();
            void setFilePath(const std::string &filePath);
            void getFile();
            void printFile() const;
            void printFile(std::size_t n) const;

        private:
            std::string _filePath;
            std::string _data;
    };
}

#endif /* !PARSING_HPP_ */
