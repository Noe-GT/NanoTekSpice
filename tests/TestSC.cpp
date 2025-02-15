/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** TestSC
*/

#include "../include/tests.hpp"

Test (SCTrue, pins)
{
    component::SCTrue comp;

    cr_assert(comp.getNbInputs() == 0 &&
        comp.getNbOutputs() == 1 &&
        comp.isOutputPin(1));
}

Test (SCFalse, pins)
{
    component::SCFalse comp;

    cr_assert(comp.getNbInputs() == 0 &&
        comp.getNbOutputs() == 1 &&
        comp.isOutputPin(1));
}

Test (SCInput, pins)
{
    component::SCInput comp;

    cr_assert(comp.getNbInputs() == 0 &&
        comp.getNbOutputs() == 1 &&
        comp.isOutputPin(1));
}

// Test (SCOutput, pins)
// {
//     component::SCOutput comp;

//     cr_assert(comp.getNbInputs() == 0 &&
//         comp.getNbOutputs() == 1 &&
//         comp.isOutputPin(1));
// }
