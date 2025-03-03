/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** Parsing
*/

#include "../include/Parsing.hpp"

nts::Parsing::Parsing(): _parsingType(NONE)
{
}

nts::Parsing::Parsing(const std::string &filePath): _parsingType(NONE)
{
    this->setFilePath(filePath);
    this->parseFile();
}

nts::Parsing::~Parsing()
{
}

void nts::Parsing::setFilePath(const std::string &filePath)
{
    size_t ind = filePath.find('.');

    if (ind == std::string::npos || filePath.substr(ind) != ".nts")
        throw Exception("Incorrect file name");
    this->_filePath = filePath;
    this->getFile();
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
    std::cout << this->_data;
}

void nts::Parsing::printFile(size_t n) const
{
    std::string line;
    std::stringstream ss(this->_data);

    while (std::getline(ss, line) && n > 0) {
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
    str = ans;
    return str;
}

std::string &nts::Parsing::delComment(std::string &line)
{
    size_t ind = line.find('#');

    if (ind != std::string::npos)
        line.resize(ind);
    return line;
}

size_t nts::Parsing::getStringStreamLength(std::stringstream &&ss) const
{
    size_t len = 0;
    std::string tmp;

    while (ss >> tmp)
        len++;
    return len;
}

size_t nts::Parsing::getCharOcc(const std::string &str, char c) const
{
    size_t n = 0;

    for (size_t i = 0; i < str.length(); i++)
        if (str[i] == c)
            n++;
    return n;
}

bool nts::Parsing::isStrNum(const std::string &str) const
{
    for (size_t i = 0; i < str.length(); i++)
        if (!std::isdigit(str[i]))
            return false;
    return true;
}

bool nts::Parsing::isChipset(const std::string &line) const
{
    if (this->getStringStreamLength(std::stringstream(line)) != 2)
        return false;
    return true;
}

bool nts::Parsing::isLink(const std::string &line) const
{
    std::stringstream ss(line);
    std::string tmp;
    std::string name;
    std::string pinId;

    if (this->getStringStreamLength(std::stringstream(line)) != 2)
        return false;
    for (int i = 0; i < 2; i++) {
        ss >> tmp;
        if (this->getCharOcc(tmp, ':') != 1)
            return false;
        name = tmp.substr(0, tmp.find(':'));
        pinId = tmp.substr(tmp.find(':') + 1);
        if (name.empty() || pinId.empty() || !this->isStrNum(pinId))
            return false;
    }
    return true;
}

void nts::Parsing::addChipset(const Chipset &&chipset)
{
    if (this->isExistingChipset(chipset.getName()))
        throw Exception("Chipset name already used");
    this->_chipsets.push_back(chipset);
}

void nts::Parsing::addLink(const Link &&link)
{
    if (!this->isExistingChipset(link.getComponent1().first) ||
    !this->isExistingChipset(link.getComponent2().first))
        throw Exception("Unknown chipset given");
    this->_links.push_back(link);
}

bool nts::Parsing::isExistingChipset(const std::string &name) const
{
    for (size_t i = 0; i < this->_chipsets.size(); i++)
        if (this->_chipsets[i].getName() == name)
            return true;
    return false;
}

void nts::Parsing::extractLine(const std::string &line)
{
    if (line == ".chipsets:") {
        this->_parsingType = CHIPSET;
        return;
    } else if (line == ".links:") {
        this->_parsingType = LINK;
        return;
    }
    if (this->_parsingType == CHIPSET) {
        if (this->isChipset(line))
            this->addChipset(Chipset(line));
        else
            throw Exception("Unknown chipset given");
    } else if (this->_parsingType == LINK) {
        if (this->isLink(line))
            this->addLink(Link(line));
        else
            throw Exception("Unknown link given");
    }
    if (this->_parsingType == NONE)
        throw Exception("Unknown line given");
}

void nts::Parsing::parseFile()
{
    std::stringstream ss;
    std::string line;

    if (this->_filePath.empty())
        throw Exception("No file path given");
    ss << this->_data;
    while (std::getline(ss, line)) {
        line = this->cleanStr(this->delComment(line));
        if (line.empty())
            continue;
        this->extractLine(line);
    }
}

std::vector<nts::Chipset> nts::Parsing::getChipsets() const
{
    return this->_chipsets;
}
std::vector<nts::Link> nts::Parsing::getLinks() const
{
    return this->_links;
}

void nts::Parsing::debug() const
{
    if (this->_filePath.empty())
        throw Exception("Can't debug");

    std::cout <<
    "File path :" << std::endl <<  this->_filePath
    << std::endl << std::endl;

    std::cout <<
    "Data :" << std::endl << this->_data
    << std::endl;

    std::cout << "Chipsets list :" << std::endl;
    for (size_t i = 0; i < this->_chipsets.size(); i++)
        std::cout <<
        "Chipset : " << this->_chipsets[i].getName() << " -> " <<
        this->_chipsets[i].getType()
        << std::endl;
    std::cout << std::endl;

    std::cout << "Links list :" << std::endl;
    for (size_t i = 0; i < this->_links.size(); i++)
        std::cout << "Link : " << this->_links[i].getComponent1().first << ":"
        << this->_links[i].getComponent1().second << " -> " <<
        this->_links[i].getComponent2().first << ":" <<
        this->_links[i].getComponent2().second << std::endl;
    std::cout << std::endl;
}

nts::Chipset::Chipset(const std::string &line)
{
    std::stringstream ss(line);

    ss >> this->_type;
    ss >> this->_name;
}

nts::Chipset::Chipset(const std::string &type, const std::string &name):
    _type(type), _name(name)
{
}

nts::Chipset::~Chipset()
{
}

std::string nts::Chipset::getType() const
{
    return this->_type;
}
std::string nts::Chipset::getName() const
{
    return this->_name;
}

nts::Link::Link(const std::string &line)
{
    std::stringstream ss(line);
    std::string str;
    size_t pinId;

    ss >> str;
    pinId = std::stol(str.substr(str.find(':') + 1));
    this->_component1 = std::pair(str.substr(0, str.find(':')), pinId);
    ss >> str;
    pinId = std::stol(str.substr(str.find(':') + 1));
    this->_component2 = std::pair(str.substr(0, str.find(':')), pinId);
}

nts::Link::Link(const std::string &c1, size_t pin1, const std::string &c2,
    size_t pin2): _component1(c1, pin1), _component2(c2, pin2)
{
}

nts::Link::~Link()
{
}

std::pair<std::string, size_t> nts::Link::getComponent1() const
{
    return this->_component1;
}
std::pair<std::string, size_t> nts::Link::getComponent2() const
{
    return this->_component2;
}
