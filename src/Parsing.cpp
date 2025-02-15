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

std::string &nts::Parsing::cleanStr(std::string &str)
{
    std::string ans("");
    std::stringstream ss(str);
    std::string tmp;

    while (ss >> tmp)
        ans = ans + tmp + " ";
    if (ans.length() > 0)
        ans.resize(ans.length() - 1);
    if (ans == "")
        ans.clear();
    return ans;
}

std::string &nts::Parsing::delComments(std::string &line)
{
    std::size_t ind = line.find('#');

    if (ind == std::string::npos)
        line.clear();
    else
        line.resize(ind);
    return line;
}

std::size_t nts::Parsing::getStringStreamLength(std::stringstream &ss)
{
    std::size_t len = 0;
    std::string tmp;

    while (ss >> tmp)
        len++;
    return len;
}

std::size_t nts::Parsing::getCharOcc(std::string &str, char c)
{
    std::size_t n = 0;

    for (int i = 0; i < str.length(); i++)
        if (str[i] == c)
            n++;
    return n;
}

bool nts::Parsing::isStrAlnum(std::string &str)
{
    for (std::size_t i = 0; i < str.length(); i++)
        if (!std::isalnum(str[i]))
            return false;
    return true;
}

bool nts::Parsing::isStrNum(std::string &str)
{
    for (std::size_t i = 0; i < str.length(); i++)
        if (!std::isdigit(str[i]))
            return false;
    return true;
}

bool nts::Parsing::isChipset(std::string &line)
{
    std::stringstream ss(line);
    std::string tmp;

    if (this->getStringStreamLength(ss) != 2)
        return false;
    for (int i = 0; i < 2; i++) {
        ss >> tmp;
        if (!this->isStrAlnum(tmp))
            return false;
    }
    return true;
}

bool nts::Parsing::isLink(std::string &line)
{
    std::stringstream ss(line);
    std::string tmp;
    std::string name;
    std::string pinId;

    if (this->getStringStreamLength(ss) != 2)
        return false;
    for (int i = 0; i < 2; i++) {
        ss >> tmp;
        if (this->getCharOcc(tmp, ':') != 1)
            return false;
        name = tmp.substr(0, tmp.find(':'));
        pinId = tmp.substr(tmp.find(':') + 1);
        if (name.empty() || this->isStrAlnum(name) || pinId.empty() ||
        this->isStrNum(pinId))
            return false;
    }
    return true;
}

nts::Chipset::Chipset(const std::string &type, const std::string &name):
    _type(type), _name(name)
{
}

nts::Chipset::~Chipset()
{
}

nts::Link::Link(const std::string &c1, std::size_t pin1, const std::string &c2,
    std::size_t pin2): _component1(c1, pin1), _component2(c2, pin2)
{
}

nts::Link::~Link()
{
}
