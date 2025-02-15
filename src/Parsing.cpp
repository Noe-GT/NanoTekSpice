/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** Parsing
*/

#include "../include/Parsing.hpp"

nts::Parsing::Parsing()
{
}

nts::Parsing::Parsing(const std::string &filePath): _filePath(filePath)
{
    this->getFile();
}

nts::Parsing::~Parsing()
{
}

void nts::Parsing::setFilePath(const std::string &filePath)
{
    this->_filePath = filePath;
}

void nts::Parsing::getFile()
{
    std::ifstream file;
    std::ostringstream buff;

    if (this->_filePath.empty())
        throw Exception("No file path given");
    file.open(this->_filePath);
    if (!file.is_open() || file.fail() || file.bad())
        throw Exception("Error opening file");
    buff << file.rdbuf();
    this->_data = buff.str();
    file.close();
}

void nts::Parsing::printFile() const
{
    if (this->_data.empty())
        throw Exception("No file to print");
    std::cout << this->_data;
}

void nts::Parsing::printFile(std::size_t n) const
{
    std::string line;
    std::istringstream iss(this->_data);

    if (this->_data.empty())
        throw Exception("No file to print");
    while (std::getline(iss, line) && n > 0) {
        std::cout << line << std::endl;
        n--;
    }
}
