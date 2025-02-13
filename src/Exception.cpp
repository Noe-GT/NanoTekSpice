/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** Exception
*/

#include "../include/Exception.hpp"

Exception::Exception(const std::string &exception) noexcept: _exception(exception)
{
}

Exception::~Exception() noexcept
{
}

const char *Exception::what() const noexcept
{
    return this->_exception.c_str();
}
