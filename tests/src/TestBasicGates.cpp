/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** TestBasicGates
*/

#include "../include/tests.hpp"

Test(AndGate, pins)
{
    nts::component::AndGate comp;

    cr_assert(comp.getNbInputs() == 2 &&
        comp.getNbOutputs() == 1 &&
        comp.isInputPin(1) &&
        comp.isInputPin(2) &&
        comp.isOutputPin(3));
}

Test(AndGate, simulate)
{
    nts::component::AndGate comp;

    comp.setPin(1, TTRUE);
    comp.setPin(2, TTRUE);
    comp.simulate(1);
    if (comp.compute(3) != TTRUE)
        cr_assert(false);

    comp.setPin(1, TTRUE);
    comp.setPin(2, TFALSE);
    comp.simulate(1);
    if (comp.compute(3) != TFALSE)
        cr_assert(false);

    comp.setPin(1, TFALSE);
    comp.setPin(2, TFALSE);
    comp.simulate(1);
    if (comp.compute(3) != TFALSE)
        cr_assert(false);
}

Test(OrGate, pins)
{
    nts::component::OrGate comp;

    cr_assert(comp.getNbInputs() == 2 &&
        comp.getNbOutputs() == 1 &&
        comp.isInputPin(1) &&
        comp.isInputPin(2) &&
        comp.isOutputPin(3));
}

Test(OrGate, simulate)
{
    nts::component::OrGate comp;

    comp.setPin(1, TTRUE);
    comp.setPin(2, TTRUE);
    comp.simulate(1);
    if (comp.compute(3) != TTRUE)
        cr_assert(false);

    comp.setPin(1, TTRUE);
    comp.setPin(2, TFALSE);
    comp.simulate(1);
    if (comp.compute(3) != TTRUE)
        cr_assert(false);

    comp.setPin(1, TFALSE);
    comp.setPin(2, TFALSE);
    comp.simulate(1);
    if (comp.compute(3) != TFALSE)
        cr_assert(false);
}

Test(XorGate, pins)
{
    nts::component::XorGate comp;

    cr_assert(comp.getNbInputs() == 2 &&
        comp.getNbOutputs() == 1 &&
        comp.isInputPin(1) &&
        comp.isInputPin(2) &&
        comp.isOutputPin(3));
}

Test(XorGate, simulate)
{
    nts::component::XorGate comp;

    comp.setPin(1, TTRUE);
    comp.setPin(2, TTRUE);
    comp.simulate(1);
    if (comp.compute(3) != TFALSE)
        cr_assert(false);

    comp.setPin(1, TTRUE);
    comp.setPin(2, TFALSE);
    comp.simulate(1);
    if (comp.compute(3) != TTRUE)
        cr_assert(false);

    comp.setPin(1, TFALSE);
    comp.setPin(2, TFALSE);
    comp.simulate(1);
    if (comp.compute(3) != TFALSE)
        cr_assert(false);
}

Test(NotGate, pins)
{
    nts::component::NotGate comp;

    cr_assert(comp.getNbInputs() == 1 &&
        comp.getNbOutputs() == 1 &&
        comp.isInputPin(1) &&
        comp.isOutputPin(2));
}

Test(NotGate, simulate)
{
    nts::component::NotGate comp;

    comp.setPin(1, TTRUE);
    comp.simulate(1);
    if (comp.compute(2) != TFALSE)
        cr_assert(false);

    comp.setPin(1, TFALSE);
    comp.simulate(1);
    if (comp.compute(2) != TTRUE)
        cr_assert(false);
}
