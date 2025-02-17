/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** TestSC
*/

#include "../include/tests.hpp"

Test (SCTrue, pins)
{
    nts::component::SCTrue comp;

    cr_assert(comp.getNbInputs() == 0 &&
        comp.getNbOutputs() == 1 &&
        comp.isOutputPin(1));
}

Test (SCFalse, pins)
{
    nts::component::SCFalse comp;

    cr_assert(comp.getNbInputs() == 0 &&
        comp.getNbOutputs() == 1 &&
        comp.isOutputPin(1));
}

Test (SCInput, pins)
{
    nts::component::SCInput comp;

    cr_assert(comp.getNbInputs() == 0 &&
        comp.getNbOutputs() == 1 &&
        comp.isOutputPin(1));
}

Test (SCOutput, pins)
{
    nts::component::SCOutput comp;

    cr_assert(comp.getNbInputs() == 0 &&
        comp.getNbOutputs() == 1 &&
        comp.isOutputPin(1));
}
