/*
** EPITECH PROJECT, 2025
** miniLibC
** File description:
** tests
*/

#ifndef TESTS_H
    #define TESTS_H
    #include <criterion/criterion.h>
    #include <strings.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <stdint.h>
    #include <stdio.h>
    #include "../../include/NanoTekSpice.hpp"
    #include "../../include/Macros.hpp"

    void test_pins(nts::IComponent *comp, size_t in, size_t out);
#endif /* !TESTS_H */
