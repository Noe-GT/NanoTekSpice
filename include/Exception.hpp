/*
** EPITECH PROJECT, 2025
** NanoTekSpice
** File description:
** Exception
*/

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <exception>
#include <string>

class Exception : public std::exception
{
    public:
        Exception(const std::string &exception) noexcept;
        ~Exception() noexcept;
        const char *what() const noexcept override;

    private:
        std::string _exception;
};

#endif /* !EXCEPTION_HPP_ */
