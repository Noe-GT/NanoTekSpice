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
    #include "AndGate.hpp"
    #include "OrGate.hpp"
    #include "XorGate.hpp"
    #include "NotGate.hpp"
    #include "SCTrue.hpp"
    #include "SCFalse.hpp"
    #include "SCInput.hpp"
    #include "SCOutput.hpp"
    #include "SCClock.hpp"

    void test_pins(nts::IComponent *comp, std::size_t in, std::size_t out);
#endif /* !TESTS_H */
