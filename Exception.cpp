/*
** EPITECH PROJECT, 2025
** bootstrap
** File description:
** Exception
*/

#include "Exception.hpp"

Exception::Exception(const std::string &exception): _exception(exception)
{
}

Exception::~Exception()
{
}

const char *Exception::what() const noexcept
{
    return this->_exception.c_str();
}
